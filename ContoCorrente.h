//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#define LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#include <memory>

using namespace std;
#include "vector"
#include "Transazione.h"

class ContoCorrente {
    private:
       vector<unique_ptr<Transazione>>transazioni;
       double saldo;

    public:
        ContoCorrente();
        ~ContoCorrente();
        void addTransazione(unique_ptr<Transazione> t);
        void stampaTransazioni()const;
        void stampaDaFile()const;
        void clearFile();
        void letturaFile();
        bool eliminaTransazione(const int& k);
        void updateFile() const;
        void rimborso(const unique_ptr<Transazione>& t);
        double getSaldo()const{
            return saldo;
        }
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
