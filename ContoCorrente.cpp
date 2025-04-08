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

void ContoCorrente::addTransazione(const unique_ptr<Transazione>& t) {
    if(t->printType() == "uscita"){   //verifico di avere un saldo sufficiente per effettuare la transazione
        if(saldo+(t->getImporto())<0){
            cout << "Saldo insufficiente per effettuare la transazione!" << endl;
            return;
        }
    }
    transazioni.push_back(move(t));
    saldo=saldo+t->getImporto();    //aggiorno il saldo

    try{    //salvo la transazione nel file subito dopo averla aggiunta al vector
        ofstream outfile("fileTransazioni.txt", ios::app);
        t->salvaFile(outfile);
        cout << "TRANSAZIONE REGISTRATA!" << endl;
        outfile.close();
    }
    catch(exception&){
        cout << "ERRORE APERTURA FILE!" << endl;
    }
}

void ContoCorrente::stampaDaFile() const {
    cout << "STAMPA DA FILE:\n";
    try{
        ifstream infile("fileTransazioni.txt");
        string line;
        while (getline(infile,line)){
            cout << line << endl;
        }

       cout << "\nSaldo attuale: " << saldo << " euro" << endl;
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
            double imp;
            string tipo,md,desc; //md = mittente/destinatario

            while (getline(iss, campo, ',')) {  //leggo tutti i campi della riga e li salvo
                campi.push_back(campo);
            }

            tipo = campi[0];
            md = campi[1];
            desc = campi[2];
            imp = stod(campi[3]);

            unique_ptr<Transazione> temp;
            if (tipo == "uscita"){
                temp =make_unique<Tuscita>(desc,imp,md);
            }
            else{
                temp =make_unique<Tingresso>(desc,imp,md);
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
