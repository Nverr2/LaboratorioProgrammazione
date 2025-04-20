#include <iostream>
#include "ContoCorrente.h"

//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in grado di leggere e salvare i dati su file.

int main() {
    ContoCorrente conto;
    string file="fileTransazioni.txt";
    year y1{2025};
    month m1{4};
    day d1{18};
    year_month_day ymd{y1,m1,d1};

   // conto.clearFile(file);
    conto.letturaFile(file);
    conto.stampaDaFile(file);

    conto.addTransazione(make_unique<Transazione>(true,12,"Babbo","Regalo",50,y1,m1,d1),file);
    conto.addTransazione(make_unique<Transazione>(false,13,"MC","Pranzo",20,y1,m1,d1),file);
    //conto.addTransazione(make_unique<Transazione>(true,15,"Nonna","Visita",10,year{2023},month{2},day{29}),file);

    conto.stampaDaFile(file);

   /* cout<<"\nRICERCA:\n";
    bool x1=conto.ricercaTransazione(ymd);*/

    bool x=conto.eliminaTransazione(13,file);
    if (x)
        cout << "TRANSAZIONE RIMBORSATA!\n";
    else
        cout << "TRANSAZIONE NON TROVATA!\n";

    /* cout<<"\nRICERCA:\n";
    bool x2=conto.modificaTransazione(12,"Lapo",file);*/

    conto.stampaDaFile(file);

   // conto.clearFile(file);
    return 0;
}
