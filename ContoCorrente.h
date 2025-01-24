//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#define LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H

using namespace std;
#include "vector";
#include "Transazione.h"

class ContoCorrente {
    private:
       vector<Transazione *>transazioni;

    public:
        ContoCorrente();
        ~ContoCorrente();
        void addTransazione(Transazione* t){
            transazioni.push_back(t);
        }
        void stampaTransazioni()const;
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
