#include <fstream>
#include <gtest/gtest.h>


#include "../ContoCorrente.h"
#include "../Tingresso.h"
#include "../Tuscita.h"

using namespace std;

const string testFile = "test_transazioni.txt";
//transaz importi nulli o negativi

TEST(AddTransazione,TransazioneIngresso){
    ContoCorrente conto;

    conto.addTransazione(make_unique<Tingresso>(100,"Stipendio",1000,"Lavoro"),testFile);

    ASSERT_EQ(conto.getSaldo(),1000);
}

TEST(AddTransazione, SaldoInsufficiente){
    ContoCorrente conto;
    conto.addTransazione(make_unique<Tuscita>(101,"Kebab",10,"Mr Kebab"),testFile);
    ASSERT_EQ(conto.getSaldo(),0);
}

TEST(AddTransazione,TransazioneUscita){
    ContoCorrente conto;

    conto.addTransazione(make_unique<Tingresso>(102,"Regalo",100,"Mamma"),testFile);
    conto.addTransazione(make_unique<Tuscita>(103,"Pranzo",20,"Ristorante"),testFile);
    ASSERT_EQ(conto.getSaldo(),80);
}

TEST(ClearFile,PuliziaRiuscita){
    ContoCorrente conto;
    bool x=false;

    conto.addTransazione(make_unique<Tingresso>(100,"Stipendio",1000,"Lavoro"),testFile);
    conto.clearFile(testFile);

    ifstream file(testFile);
    if (file.peek()==istream::traits_type::eof())
    {
        x=true;
    }
    ASSERT_EQ(true,x);
}

TEST(AddTransazione,ScritturaFile){
    ContoCorrente conto;
    bool x=true;

    conto.addTransazione(make_unique<Tingresso>(100,"Stipendio",1000,"Lavoro"),testFile);

    ifstream file(testFile);
    if (file.peek()==istream::traits_type::eof())
    {
        x=false;
    }
    ASSERT_EQ(true,x);
}
TEST(EliminaTransazioni,RimborsoEffettuato){
    ContoCorrente conto;
    conto.addTransazione(make_unique<Tingresso>(103,"Stipendio",2000,"Lavoro"),testFile);
    conto.addTransazione(make_unique<Tuscita>(104,"Playstation",500,"Sony"),testFile);
    bool x=conto.eliminaTransazione(104);
    ASSERT_EQ(conto.getSaldo(),2000);
    ASSERT_EQ(x,true);

}
TEST(EliminaTransazioni,RimborsoSaldoInsufficiente){
    ContoCorrente conto;
    conto.addTransazione(make_unique<Tingresso>(103,"Stipendio",2000,"Lavoro"),testFile);
    conto.addTransazione(make_unique<Tuscita>(104,"Playstation",500,"Sony"),testFile);
    bool x=conto.eliminaTransazione(103);
    ASSERT_EQ(conto.getSaldo(),1500);
    ASSERT_EQ(x,false);
}
