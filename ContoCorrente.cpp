//
// Created by nverl on 24/01/2025.
//

#include "ContoCorrente.h"
#include <sstream>

#include "Tingresso.h"
#include "Tuscita.h"

ContoCorrente::ContoCorrente() {
    saldo=0;
}
ContoCorrente::~ContoCorrente()
{}

void ContoCorrente::stampaTransazioni() const {
    if(!transazioni.empty()){
        cout << "\nSTAMPA:";
        for (const auto& t : transazioni) {
            t->stampa();
        }
        cout << "\nSaldo attuale: " << saldo << " euro" << endl;
    }
    else
        cout << "Nessuna transazione registrata, saldo: 0 euro" << endl;

}

void ContoCorrente::addTransazione(unique_ptr<Transazione> t) {
    if(t->printType() == "uscita"){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo+(t->getImporto())<0){
            cout << "Saldo insufficiente per effettuare la transazione!" << endl;
            return;
        }
    }

    saldo=saldo+t->getImporto();    //aggiorno il saldo

    try{    //salvo la transazione nel file subito dopo averla aggiunta al vector
        ofstream outfile("fileTransazioni.txt", ios::app);
        t->salvaFile(outfile);
        outfile.close();
    }
    catch(exception&){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
    transazioni.push_back(move(t));
    cout << "TRANSAZIONE REGISTRATA!" << endl;
}

void ContoCorrente::stampaDaFile() const {
    cout << "\nSTAMPA DA FILE:\n";
    try{
        ifstream infile("fileTransazioni.txt");
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

void ContoCorrente::clearFile() {
    try{
        ofstream outfile("fileTransazioni.txt", ios::trunc);
    }
    catch(exception& ){
        cout << "errore pulizia file";
    }
}

void ContoCorrente::letturaFile(){
    try
    {
        ifstream infile("fileTransazioni.txt");
        string line;
        while (getline(infile,line))
        {
            istringstream iss(line);
            string campo;
            vector<std::string> campi;
            int id;
            double imp;
            string tipo,md,desc; //md = mittente/destinatario

            while (getline(iss, campo, ',')) {  //leggo tutti i campi della riga e li salvo
                campi.push_back(campo);
            }

            tipo = campi[0];
            md = campi[1];
            id = stoi(campi[2]);
            desc = campi[3];
            imp = stod(campi[4]);

            unique_ptr<Transazione> temp;
            if (tipo == "uscita"){
                temp =make_unique<Tuscita>(id,desc,imp,md);
            }
            else{
                temp = make_unique<Tingresso>(id,desc,imp,md);
            }
            saldo+=imp;
            transazioni.push_back(move(temp));
        }
        cout << "LETTURA FILE COMPLETATA!" << endl;
    }
    catch(exception& e)
    {
        cout << "ERRORE: " << e.what() << endl;
    }

}

bool ContoCorrente::eliminaTransazione(const int& k){
    bool found = false;
    int i=0;
    for (const auto& t : transazioni) {
        if (t->getId()==k){ //transazione trovata, procedo ad eliminare
            rimborso(t);
            transazioni.erase(transazioni.begin()+i);
            found = true;
            break;
        }
        i++;
    }
    updateFile();
    return found;
}
void ContoCorrente::updateFile() const
{
    try
    {
        ofstream outfile("fileTransazioni.txt", ios::trunc);
        for (const auto& t : transazioni){
            t->salvaFile(outfile);
        }
        outfile.close();
    }catch (exception& e){
        cout << "ERRORE: " << e.what() << endl;
    }
}

void ContoCorrente::rimborso(const unique_ptr<Transazione>& t)
{
    if (t->printType()=="entrata"){
        saldo=saldo-t->getImporto();
    }else{
        saldo=saldo+t->getImporto();
    }
}




