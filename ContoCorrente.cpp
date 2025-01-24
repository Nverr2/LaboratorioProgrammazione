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
    for (const auto& t : transazioni) {
        t->stampa();
    }
    cout << "\nSaldo attuale: " << saldo << " €" << endl;
}

void ContoCorrente::addTransazione(Transazione *t, const string& filename) {
    if(t->printType() == "uscita"){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo-t->getImporto()<0){
            cout << "Saldo insufficiente per effettuare la transazione!" << endl;
            return;
        }
    }
    transazioni.push_back(t);
    ofstream outfile("fileTransazioni.txt");
    if(outfile.is_open()){
        t->salvaFile(outfile);  //salvo la transazione nel file subito dopo averla aggiunta al vector
        cout << "TRANSAZIONE REGISTRATA!" << endl;

    }
    else{
        cout << "ERRORE APERTURA FILE!" << endl;
    }

}

void ContoCorrente::stampaDaFile() const {
    ifstream infile("fileTransazioni.txt");
    if(infile.is_open()){
        string line;
        while (getline(infile,line)){
            cout << line << endl;
        }
    }
    else{
        cout << "ERRORE APERTURA FILE!" << endl;
    }
}
