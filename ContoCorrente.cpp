//
// Created by nverl on 24/01/2025.
//

#include "ContoCorrente.h"
#include <sstream>
#include "Transazione.h"

ContoCorrente::ContoCorrente() {
    saldo=0;
}
ContoCorrente::~ContoCorrente()
{}

void ContoCorrente::stampaTransazioni() const {
    if(!transazioni.empty()){
        cout << "STAMPA:\n";
        for (const auto& t : transazioni) {
            if (t->getType()){  //transazione in ingresso
                cout<<"INGRESSO, Id: "<<t->getId()<<", Mit: "<<t->getMitDest()<<", Descrizione: "<<t->getDescrizione()<<", Importo: "<<t->getImporto()<<", Data: "<<t->getData()<<endl;
            }
            else{   //transazione in uscita
                cout<<"USCITA, Id: "<<t->getId()<<", Dest: "<<t->getMitDest()<<", Descrizione: "<<t->getDescrizione()<<", Importo: "<<t->getImporto()<<", Data: "<<t->getData()<<endl;
            }
        }
        cout << "Saldo attuale: " << saldo << " euro" << endl;
    }
    else
        cout << "Nessuna transazione registrata, saldo: 0 euro" << endl;

}
void ContoCorrente::scritturaFile(const Transazione& t,const string& filename) const{

    try{
        ofstream outfile(filename, ios::app);
        if (t.getType()){  //transazione in ingresso
            outfile <<t.getType()<<", "<<t.getId()<<", "<<t.getMitDest()<<", "<<t.getDescrizione()<<", "<<t.getImporto()<<", "<<t.getData()<<"\n";
        }
        else{   //transazione in uscita
            outfile <<t.getType()<<", "<<t.getId()<<", "<<t.getMitDest()<<", "<<t.getDescrizione()<<", "<<t.getImporto()<<", "<<t.getData()<<"\n";
        }
        outfile.close();
    }
    catch(exception&){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
}


void ContoCorrente::addTransazione(unique_ptr<Transazione> t, const string& filename) {
    if (!transazioni.empty()){
        for (const auto& t2 : transazioni){
            if (t->getId()==t2->getId())
                throw runtime_error("ID GIA' ASSEGNATO, IMPOSSIBILE AGGIUNGERE TRANSAZIONE!!!");
        }
    }
    if(t->getType()==false){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo+(t->getImporto())<0){
            cout << "Saldo insufficiente per effettuare la transazione!" << endl;
            return;
        }
    }

    saldo=saldo+t->getImporto();

    scritturaFile(*t,filename);         //salvo la transazione nel file subito dopo averla aggiunta al vector
    transazioni.push_back(move(t));
    cout << "TRANSAZIONE REGISTRATA!" << endl;
}

void ContoCorrente::stampaDaFile(const string& filename) const {
    cout << "\nSTAMPA DA FILE:\n";
    try{
        ifstream infile(filename);
        string line;
        while (getline(infile,line)){
            cout << line << endl;
        }

       cout << "Saldo attuale: " << saldo << " euro" << endl;
        infile.close();
    }
    catch(exception&){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
}

void ContoCorrente::clearFile(const string& filename)
{
    try{
        ofstream outfile(filename, ios::trunc);
    }
    catch(exception& ){
        cout << "errore pulizia file";
    }
}

void ContoCorrente::letturaFile(const string& filename){
    try
    {
        ifstream infile(filename);
        string line;
        while (getline(infile,line)){
            istringstream iss(line);
            string campo,num;
            vector<string> campi;
            vector<int>ymd;
            bool tipo;
            int id;
            double imp;
            string md,desc; //md = mittente/destinatario

            while (getline(iss, campo, ',')) {  //leggo tutti i campi della riga e li salvo
                campi.push_back(campo);
            }
            if (stoi(campi[0])==1){
                tipo=true;
                imp = stod(campi[4]);
                saldo+=imp;
            }

            else{
                tipo=false;
                imp =-(stod(campi[4]));
                saldo-=imp;
            }
            id = stoi(campi[1]);
            md = campi[2];
            desc = campi[3];

            istringstream s(campi[5]);
            while(getline(s, num,'-')){
                ymd.push_back(stoi(num));
            }
            year_month_day ymd1= year{ymd[0]}/month{static_cast<unsigned>(ymd[1])}/day{static_cast<unsigned>(ymd[2])};

            unique_ptr<Transazione> temp;
            temp=make_unique<Transazione>(tipo,id,md,desc,imp,ymd1.year(),ymd1.month(),ymd1.day());

            transazioni.push_back(move(temp));
        }
        cout << "LETTURA FILE COMPLETATA!" << endl;
    }
    catch(exception& e){
        cout << "ERRORE: " << e.what() << endl;
    }
}

bool ContoCorrente::eliminaTransazione(const int k){
    bool found = false;
    int i=0;
    for (const auto& t : transazioni) {
        if (t->getId()==k){ //transazione trovata, procedo ad eliminare
            if (saldo-(t->getImporto())<0){ //non posso rimborsare più soldi di quanti ne posseggo
                cout << "SALDO INSUFFICIENTE PER EFFETTUARE IL RIMBORSO!!!" << endl;
                return false;
            }
            rimborso(t);
            transazioni.erase(transazioni.begin()+i);
            found = true;
            break;
        }
        i++;
    }
    updateFile("fileTransazioni.txt");
    return found;
}
void ContoCorrente::updateFile(const string& filename) const
{
    try
    {
        ofstream outfile(filename, ios::trunc);
        for (const auto& t : transazioni){
           scritturaFile(*t,filename);
        }
        outfile.close();
    }catch (exception& e){
        cout << "ERRORE: " << e.what() << endl;
    }
}

void ContoCorrente::rimborso(const unique_ptr<Transazione>& t)
{
    saldo=saldo-(t->getImporto());  //vista la struttura del progetto i casi pos/neg combaciano(da controllare dopo le modifiche)

}




