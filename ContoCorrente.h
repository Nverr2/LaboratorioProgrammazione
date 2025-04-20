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
        void rimborso(const unique_ptr<Transazione>& t);
        static void scritturaFile(const Transazione& t,const string& filename) ;
        int numTransazioni() const;

    public:
        ContoCorrente();
        ~ContoCorrente();
        bool addTransazione(unique_ptr<Transazione> t,const string& filename);
        void stampaTransazioni()const;
        void stampaDaFile(const string& filename)const;
        void clearFile(const string& filename) ;
        void letturaFile(const string& filename);
        bool eliminaTransazione(int k);
        void updateFile(const string& filename) const;
        double getSaldo()const{return saldo;}
        bool ricercaTransazione(year_month_day data) const;
        bool modificaTransazione(int k,const string& desc,const string& filename) const;
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
