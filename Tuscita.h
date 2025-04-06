//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_TUSCITA_H
#define LABORATORIOPROGRAMMAZIONE_TUSCITA_H


#include "Transazione.h"

class Tuscita : public Transazione{
    public:
        Tuscita(string desc,double imp,string dest) : Transazione(desc,imp), destinatario(dest){
            importo=-imp;
        }
        void stampa()const override;
        string getDestinatario()const{
            return destinatario;
        }
        void setDestinatario(string dest)
        {
            destinatario = dest;
        }
        void salvaFile(ofstream& outfile) const override;
        string printType()const override{
            return "uscita";
        }

    private:
        string destinatario;
};


#endif //LABORATORIOPROGRAMMAZIONE_TUSCITA_H
