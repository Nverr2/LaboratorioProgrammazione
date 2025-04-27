//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#define LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
#include <memory>
#include "fstream"
#include "vector"
#include "Transazione.h"

using namespace std;


class ContoCorrente {
    private:
        string nome;
        vector<unique_ptr<Transazione>>transazioni;
        double saldo;
        void rimborso(const unique_ptr<Transazione>& t);
        void scritturaFile(const Transazione& t,const string& filename) const;

    public:
        explicit ContoCorrente(const string& n);
        ~ContoCorrente();
        bool addTransazione(unique_ptr<Transazione> t,const string& filename);
        void stampaDaFile(const string& filename)const;
        void clearFile(const string& filename) const;
        void letturaFile(const string& filename);
        bool eliminaTransazione(int k,const string& filename);
        void updateFile(const string& filename) const;
        double getSaldo()const{return saldo;}
        const vector<unique_ptr<Transazione>>& getTransazioni() const{return transazioni;}
        vector<unique_ptr<Transazione>> ricercaTransazione(year_month_day data) const;
        bool modificaTransazione(int k,const string& desc,const string& filename);
        int numTransazioni(const vector<unique_ptr<Transazione>>& t) const;
};


#endif //LABORATORIOPROGRAMMAZIONE_CONTOCORRENTE_H
