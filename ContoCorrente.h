//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#define LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H

using namespace std;
#include "vector"
#include "Transazione.h"

class ContoCorrente {
    private:
       vector<Transazione *>transazioni;
       double saldo;

    public:
        ContoCorrente();
        ~ContoCorrente();
        void addTransazione(Transazione* t,const string& filename);
        void stampaTransazioni()const;
        void stampaDaFile()const;
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
