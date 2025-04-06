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
   // conto.addTransazione(new Tingresso("Stipendio", 1340, "Lavoro"));     //transazione già memorizzzata
   // conto.addTransazione(new Tingresso("Regalo natale", 50, "Nonna"));    //transazione già memorizzata
  //  conto.addTransazione(new Tuscita("Shopping", 150, "Zara"));           //transazione già memorizzata
   // conto.addTransazione(new Tuscita("Multe", 1240, "Polizia municipale"));
    // conto.addTransazione(new Tuscita("Pranzo", 10, "Pizzeria"));          //transazione già memorizzata
    conto.stampaTransazioni();
    conto.stampaDaFile();


    return 0;
}
