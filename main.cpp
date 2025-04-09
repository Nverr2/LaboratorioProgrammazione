#include <iostream>
#include "ContoCorrente.h"
#include "Tuscita.h"
#include "Tingresso.h"
//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in grado di leggere e salvare i dati su file.

int main() {
    ContoCorrente conto;

   conto.letturaFile();
    //conto.clearFile();
   // conto.addTransazione(make_unique<Tingresso>("Stipendio", 1340, "Lavoro"));
    //conto.addTransazione(make_unique<Tingresso>("regalo natale", 50, "Nonna"));
    //conto.addTransazione(make_unique<Tuscita>("Shopping", 150, "Zara"));
    //conto.addTransazione(make_unique<Tuscita>("Multe", 1200, "Polizia municipale")); //non ancora registrata
    conto.stampaTransazioni();
    conto.stampaDaFile();


    return 0;
}
