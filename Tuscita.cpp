//
// Created by nverl on 24/01/2025.
//

#include "Tuscita.h"

void Tuscita::stampa() const {
    cout << "\nTRANSAZIONE IN ENTRATA: Descrizione: " << descrizione << ", Destinatario: " << destinatario << "\nImporto: " << " €";
}

void Tuscita::salvaFile(ofstream &outfile) const {
    outfile << "Uscita, destinatario: " << destinatario << ",";
    Transazione::salvaFile(outfile);
}
