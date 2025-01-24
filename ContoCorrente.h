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
        void addTransazione(Transazione* t);
        void stampaTransazioni()const;
        void stampaDaFile()const;
        void clearFile();
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
