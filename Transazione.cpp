#include "Transazione.h"

using namespace std;

Transazione::Transazione(const bool tp, const int identifier, const string& mitdest,const string& desc, double imp,year y,month m,day d): id(identifier),descrizione(desc),md(mitdest),type(tp){
    while (imp<=0){
        cout<<"Importo non accettabile!\nInserire importo positivo: ";
        cin>>imp;
    }
    if (tp==false)
        imp=-imp;
    importo=imp;
    year_month_day date{y,m,d};
    while(date.ok()==false){ //se non ho una data accettabile es: 29 feb 2023
        unsigned y1,m1,d1;
        cout<<"\nData inserita non valida, inserirne una nuova:\nAnno: ";
        cin>>y1;
        cout<<"\nMese: ";
        cin>>m1;
        cout<<"\nGiorno: ";
        cin>>d1;
        year_month_day newData{year{static_cast<int>(y1)},month{m1},day{d1}};
        date=newData;
    }
    data=date;
}
