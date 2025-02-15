#include <iostream>
#include "ContoCorrente.h"
#include "Tuscita.h"
#include "Tingresso.h"
//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in grado di leggere e salvare i dati su file.

int main() {
    ContoCorrente conto;

    conto.clearFile();
    conto.stampaTransazioni();
    conto.addTransazione(new Tuscita("Pranzo", 10, "Pizzeria"));
    conto.addTransazione(new Tingresso("Stipendio", 1340, "Lavoro"));
    conto.addTransazione(new Tingresso("Regalo natale", 50, "Nonna"));
    conto.addTransazione(new Tuscita("Shopping", 150, "Zara"));
   // conto.addTransazione(new Tuscita("Multe", 1240, "Polizia municipale"));
    conto.stampaTransazioni();
    conto.stampaDaFile();


    return 0;
}
