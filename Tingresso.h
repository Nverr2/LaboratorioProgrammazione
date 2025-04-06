//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_TINGRESSO_H
#define LABORATORIOPROGRAMMAZIONE_TINGRESSO_H


#include "Transazione.h"

class Tingresso : public Transazione{
    public:
        Tingresso(string desc, double imp,string mit) : Transazione(desc,imp), mittente(mit){
        }
        void stampa() const override;

        string getMittente()const{
            return mittente;
        }
        void setMittente(string mit)
        {
            mittente = mit;
        }
        string printType()const override{
            return "entrata";
        }
        void salvaFile(ofstream& outfile) const override;
    private:
        string mittente;
};


#endif //LABORATORIOPROGRAMMAZIONE_TINGRESSO_H
