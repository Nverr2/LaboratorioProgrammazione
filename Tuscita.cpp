//
// Created by nverl on 24/01/2025.
//

#include "Tuscita.h"

void Tuscita::stampa() const {
    cout << "\nDescrizione: " << descrizione << ", Destinatario: " << destinatario << ", Importo: " << importo << " euro";
}

void Tuscita::salvaFile(ofstream &outfile) const {
    outfile << "Uscita, " << destinatario << ", ";
    Transazione::salvaFile(outfile);
}
