//
// Created by nverl on 24/01/2025.
//

#ifndef LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H
#define LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H

#include <string>
#include "iostream"
#include "fstream"
#include <chrono>

using namespace std;
using namespace chrono;

class Transazione{
    private:
        int id;
        string descrizione,md;  //md=mittente/destinatario
        double importo;
        bool type; //true=ingresso, false=uscita
        year_month_day data;


    public:
        Transazione(bool tp,int identifier,string mitdest,string desc,double imp,year y, month m,day d);
        virtual ~Transazione() = default;
        double getImporto()const{return importo;}
        void setImporto(double imp){
            if (imp>0)
                importo = imp;
            else
                cout<<"Importo non accettabile!";
        }
        bool getType()const{return type;}
        int getId()const{return id;}
        string getDescrizione()const{return descrizione;}
        void setDescrizione(string desc){descrizione=desc;}
        year_month_day getData()const{return data;}
        string getMitDest()const{return md;}

};

#endif //LABORATORIOPROGRAMMAZIONE_TRANSAZIONE_H
