//
// Created by nverl on 24/01/2025.
//

#include "ContoCorrente.h"

ContoCorrente::ContoCorrente() {
    saldo=0;
}

ContoCorrente::~ContoCorrente() {
    for (auto t : transazioni) {
        delete t;
    }

}

void ContoCorrente::stampaTransazioni() const {
    if(!transazioni.empty()){
        for (const auto& t : transazioni) {
            t->stampa();
        }
        cout << "\nSaldo attuale: " << saldo << " euro" << endl;
    }
    else
        cout << "Nessuna transazione registrata, saldo: 0 euro" << endl;

}

void ContoCorrente::addTransazione(Transazione *t) {
    if(t->printType() == "uscita"){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo+(t->getImporto())<0){
            cout << "Saldo insufficiente per effettuare la transazione!" << endl;
            return;
        }
    }
    transazioni.push_back(t);

    try{
        ofstream outfile("fileTransazioni.txt", ios::app);
        t->salvaFile(outfile);  //salvo la transazione nel file subito dopo averla aggiunta al vector
        cout << "TRANSAZIONE REGISTRATA!" << endl;
        outfile.close();
    }
    catch(exception){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
    saldo=saldo+t->getImporto();

}

void ContoCorrente::stampaDaFile() const {
    cout << "STAMPA DA FILE:\n";
    try{
        ifstream infile("fileTransazioni.txt");
        string line;
        while (getline(infile,line)){
            cout << line << endl;
        }
        infile.close();
    }
    catch(exception){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
}

void ContoCorrente::clearFile() {
    ofstream outfile("fileTransazioni.txt", ios::trunc);
}
