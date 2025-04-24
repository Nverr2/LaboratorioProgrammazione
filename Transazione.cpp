#include "Transazione.h"

using namespace std;

Transazione::Transazione(const bool tp, const int identifier, const string& mitdest,const string& desc, double imp,year y,month m,day d): id(identifier),descrizione(desc),md(mitdest),type(tp){
    if(imp<=0){
        //throw
    }
    if (tp==false)
        imp=-imp;
    importo=imp;
    year_month_day date{y,m,d};
    if(date.ok()==false){ //se non ho una data accettabile es: 29 feb 2023
        //throw
    }
    data=date;
}
