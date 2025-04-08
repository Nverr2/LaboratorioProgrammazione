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
    //conto.addTransazione(make_unique<Tuscita>("Multe", 1200, "Polizia municipale"));
    conto.stampaTransazioni();
    conto.stampaDaFile();


    return 0;
}
