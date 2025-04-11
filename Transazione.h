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
        int id;
        string descrizione;
        double importo;

    public:
        Transazione(int identifier,string desc,double imp) : id(identifier), descrizione(desc), importo(imp){

        }
        virtual ~Transazione() = default;
        virtual void stampa()const = 0;
        double getImporto()const{
            return importo;
        }
        void setImporto(double imp){
            importo = imp;
        }
        virtual void salvaFile(ofstream& outfile)const{
            outfile << id <<"," << descrizione << "," << importo << "\n";
        }
        virtual string printType()const=0;
        int getId()const
        {
            return id;
        }
};

#endif //LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H
