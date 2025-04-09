//
// Created by nverl on 24/01/2025.
//

#include "Tingresso.h"

void Tingresso::stampa() const {
    cout << "\nID: " << id <<", Descrizione: " << descrizione << ", Mittente: " << mittente << ", Importo: " << importo << " euro";
}

void Tingresso::salvaFile(ofstream &outfile)const {
    outfile << "Entrata, " << mittente << ", ";
    Transazione::salvaFile(outfile);
}
