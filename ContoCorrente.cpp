//
// Created by nverl on 24/01/2025.
//

#include "ContoCorrente.h"
#include <sstream>
#include <iostream>
#include "Transazione.h"

ContoCorrente::ContoCorrente(const string& n) : nome(n){
    saldo=0;
}
ContoCorrente::~ContoCorrente() = default;

void ContoCorrente::scritturaFile(const Transazione& t,const string& filename) const{
        ofstream outfile(filename, ios::app);
        if (!outfile)
            throw runtime_error("Errore scrittura file");

        if (t.getType()){  //transazione in ingresso
            outfile <<t.getType()<<", "<<t.getId()<<", "<<t.getMitDest()<<", "<<t.getDescrizione()<<", "<<t.getImporto()<<", "<<t.getData()<<"\n";
        }
        else{   //transazione in uscita
            outfile <<t.getType()<<", "<<t.getId()<<", "<<t.getMitDest()<<", "<<t.getDescrizione()<<", "<<t.getImporto()<<", "<<t.getData()<<"\n";
        }
        outfile.close();
}

bool ContoCorrente::addTransazione(unique_ptr<Transazione> t, const string& filename){
    if (!transazioni.empty()){
        for (const auto& t2 : transazioni){
            if (t->getId()==t2->getId())
                throw runtime_error("Impossibile aggiungere transazione");
        }
    }
    if(t->getType()==false){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo+(t->getImporto())<0){
            return false;
        }
    }
    saldo=saldo+t->getImporto();
    scritturaFile(*t,filename);
    transazioni.push_back(move(t));
    return true;
}

void ContoCorrente::stampaDaFile(const string& filename) const{
    cout << "\nSTAMPA DA FILE:\n";
    ifstream infile(filename);
    if (!infile)
        throw runtime_error("Errore lettura file");
    string line;
    while (getline(infile,line)){
        cout << line << endl;
    }
    cout << "Saldo attuale: " << saldo << " euro" << ", Transazioni registrate: "<< numTransazioni(this->getTransazioni()) <<endl;
    infile.close();
}

void ContoCorrente::clearFile(const string& filename) const{
        ofstream outfile(filename, ios::trunc);
        if (!(outfile))
            throw runtime_error("Errore scrittura file");
        outfile.close();
    }

void ContoCorrente::letturaFile(const string& filename){
    try
    {
        ifstream infile(filename);
        string line;
        while(getline(infile,line)){
            istringstream iss(line);
            string campo,num;
            vector<string> campi;
            vector<int>ymd;
            bool tipo;
            int id;
            double imp;
            string md,desc; //md = mittente/destinatario

            while(getline(iss, campo, ',')){  //leggo tutti i campi della riga e li salvo
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
    }
    catch(exception& e){
        cerr << "ERRORE: " << e.what() << endl;
    }
}

bool ContoCorrente::eliminaTransazione(const int k,const string& filename){
    bool found = false;
    int i=0;
    for ( auto& t : transazioni) {
        if (t->getId()==k){                 //transazione trovata, procedo ad eliminare
            if (saldo-(t->getImporto())<0){ //non posso rimborsare più soldi di quanti ne posseggo
                return false;
            }
            rimborso(t);
            transazioni.erase(transazioni.begin()+i);
            found = true;
            break;
        }
        i++;
    }
    updateFile(filename);
    return found;
}

void ContoCorrente::updateFile(const string& filename) const{
        if (transazioni.empty()){
            ofstream outfile(filename, ios::trunc);
            if (!outfile)
                throw runtime_error("Errore scrittura file");
            outfile.close();
        }
        else
        {
            ofstream outfile(filename, ios::trunc);
            for (const auto& t : transazioni){
                scritturaFile(*t,filename);
                outfile.close();
            }
        }
}

vector<unique_ptr<Transazione>> ContoCorrente::ricercaTransazione(year_month_day data) const{    //stampa tutte le transazioni effettuate in un determinato giorno
    int i=0;
    vector<unique_ptr<Transazione>> found;
    for (const auto& t : transazioni){
        if (t->getData()==data){
            i++;
            found.push_back(make_unique<Transazione>(*t));
        }
    }
    return move(found);
}

bool ContoCorrente::modificaTransazione(const int k, const string& desc,const string& filename){
    bool mod=false;
    for (auto& t : transazioni){
        if (t->getId()==k){
            t->setDescrizione(desc);
            mod=true;
            updateFile(filename);
        }
    }
    return mod;
}

void ContoCorrente::rimborso(const unique_ptr<Transazione>& t){
    saldo=saldo-(t->getImporto());
}

int ContoCorrente::numTransazioni(const vector<unique_ptr<Transazione>>& t) const{
    return static_cast<int>(t.size());
}





