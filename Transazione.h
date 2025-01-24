//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H
#define LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H

#include <string>
#include "iostream"
#include "fstream"

using namespace std;
class Transazione{
    protected:
        string descrizione;
        double importo;

    public:
        Transazione(string desc,double imp) : descrizione(desc), importo(imp){

        }
        virtual ~Transazione() = default;
        virtual void stampa()const = 0;
        double getImporto()const{
            return importo;
        }
        virtual void salvaFile(ofstream& outfile)const{
            outfile << importo << " euro" << "\n";
        }
        virtual string printType()const=0;
};

#endif //LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H
