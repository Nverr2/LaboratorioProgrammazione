//
// Created by nverl on 24/01/2025.
//

#include "Tingresso.h"

void Tingresso::stampa() const {
    cout << "\nTRANSAZIONE IN ENTRATA: Descrizione: " << descrizione << ", Mittente: " << mittente << "\nImporto: " << " €";
}

void Tingresso::salvaFile(ofstream &outfile)const {
    outfile << "Entrata, mittente: " << mittente << ",";
    Transazione::salvaFile(outfile);
}
