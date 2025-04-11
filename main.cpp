#include <iostream>
#include "ContoCorrente.h"
#include "Tuscita.h"
#include "Tingresso.h"
//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in grado di leggere e salvare i dati su file.

int main() {
    ContoCorrente conto;
    string file="fileTransazioni.txt";

   conto.letturaFile(file);
   // conto.clearFile(file);
  //   conto.addTransazione(make_unique<Tingresso>(100,"Stipendio", 1340, "Lavoro"),file);
   //  conto.addTransazione(make_unique<Tingresso>(101,"Regalo natale", 50, "Nonna"),file);
  //   conto.addTransazione(make_unique<Tuscita>(102,"Shopping", 150, "Zara"),file);
   // conto.addTransazione(make_unique<Tuscita>(104,"Multe", 1200, "Polizia municipale"),file); //per provare eliminazione
    bool x=conto.eliminaTransazione(104);
    if (x)
        cout << "TRANSAZIONE RIMBORSATA!";
    else
        cout << "TRANSAZIONE NON TROVATA!";
  //  conto.stampaTransazioni();
    conto.stampaDaFile(file);


    return 0;
}
