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

    conto.addTransazione(make_unique<Transazione>(true,12,"Babbo","Regalo",50,y1,m1,d1),file);
    conto.addTransazione(make_unique<Transazione>(false,13,"MC","Pranzo",20,y1,m1,d1),file);
    conto.stampaTransazioni();




  // conto.letturaFile(file);
   // conto.clearFile(file);

  /*  bool x=conto.eliminaTransazione(104);
    if (x)
        cout << "TRANSAZIONE RIMBORSATA!";
    else
        cout << "TRANSAZIONE NON TROVATA!";*/
    //conto.stampaDaFile(file);


    return 0;
}
