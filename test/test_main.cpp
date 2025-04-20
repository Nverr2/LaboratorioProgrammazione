#include <fstream>
#include <gtest/gtest.h>


#include "../ContoCorrente.h"


using namespace std;

const string testFile = "test_transazioni.txt";

TEST(AddTransazione,TransazioneIngresso){
    ContoCorrente conto;

    bool x=conto.addTransazione(make_unique<Transazione>(true,100,"Nonna","Visita",10,year{2023},month{8},day{24}),testFile);

    ASSERT_EQ(conto.getSaldo(),10);
    ASSERT_EQ(true,x);
}

TEST(AddTransazione, SaldoInsufficiente){
    ContoCorrente conto;
    bool x=conto.addTransazione(make_unique<Transazione>(false,101,"Ristorante","Pranzo",10,year{2024},month{7},day{12}),testFile);
    ASSERT_EQ(conto.getSaldo(),0);
    ASSERT_EQ(false,x);
}

TEST(AddTransazione,TransazioneUscita){
    ContoCorrente conto;

    bool x1=conto.addTransazione(make_unique<Transazione>(true,102,"Babbo","Regalo",100,year{2025},month{4},day{20}),testFile);
    bool x2=conto.addTransazione(make_unique<Transazione>(false,103,"Ristorante","Pranzo",20,year{2025},month{4},day{20}),testFile);

    ASSERT_EQ(conto.getSaldo(),80);
    ASSERT_EQ(true,x1);
    ASSERT_EQ(true,x2);
}

TEST(EliminaTransazione, EliminazioneRiuscita){
    ContoCorrente conto;
    bool x1=false;

    bool x2=conto.addTransazione(make_unique<Transazione>(true,104,"Babbo","Regalo",100,year{2025},month{4},day{20}),testFile);
    bool x3=conto.eliminaTransazione(104,testFile);

    ifstream file(testFile);
    if (file.peek()==istream::traits_type::eof()){
        x1=true;
    }
    ASSERT_EQ(true,x2); //transazione aggiunta con successo
    ASSERT_EQ(true,x3); //eliminazione avvenut con successo
    ASSERT_EQ(true,x1); //modifica del file avvenuta con successo
}

TEST(EliminaTransazione, EliminazioneFallita){
    ContoCorrente conto;

    bool x1=conto.addTransazione(make_unique<Transazione>(true,105,"Lavoro","Stipendio",500,year{2025},month{4},day{20}),testFile);
    bool x2=conto.addTransazione(make_unique<Transazione>(false,106,"Sony","PS5",400,year{2025},month{4},day{20}),testFile);
    bool x3=conto.eliminaTransazione(105,testFile);

    ASSERT_EQ(true,x1);//stipendio registrato con successo
    ASSERT_EQ(true,x2); //pagamento ps5 registrato con successo
    ASSERT_EQ(false,x3); //impossibile rimborsare lo stipendio per saldo insufficiente
}

TEST(AddTransazione,ScritturaFile){
    ContoCorrente conto;
    bool x=true;

    bool x1=conto.addTransazione(make_unique<Transazione>(true,107,"Lavoro","Stipendio",500,year{2025},month{4},day{20}),testFile);

    ifstream file(testFile);
    if (file.peek()==istream::traits_type::eof()){
        x=false;
    }
    ASSERT_EQ(true,x1);
    ASSERT_EQ(true,x);  //file non vuoto, scrittura avvenuta
}
TEST(RicercaTransazioni,TransazioneTrovata){
    ContoCorrente conto;
    year_month_day ymd{year{2025},month{4},day{20}};

    bool x1=conto.addTransazione(make_unique<Transazione>(true,108,"Lavoro","Stipendio",500,year{2025},month{4},day{20}),testFile);
    bool x2=conto.ricercaTransazione(ymd);

    ASSERT_EQ(true,x1);
    ASSERT_EQ(true,x2);
}
TEST(RicercaTransazioni,NessunRiscontro){
    ContoCorrente conto;
    year_month_day ymd{year{2025},month{3},day{11}};

    bool x1=conto.addTransazione(make_unique<Transazione>(true,109,"Lavoro","Stipendio",500,year{2025},month{4},day{20}),testFile);
    bool x2=conto.ricercaTransazione(ymd);

    ASSERT_EQ(true,x1);
    ASSERT_EQ(false,x2);
}

TEST(ModificaTransazioni,MoficaEffettuata){
    ContoCorrente conto;
    string temp="Lapo";

    bool x1=conto.addTransazione(make_unique<Transazione>(true,110,"Babbo","Regalo",50,year{2025},month{4},day{20}),testFile);
    bool x2=conto.modificaTransazione(110,temp,testFile);

    ASSERT_EQ(true,x1);
    ASSERT_EQ(true,x2);
}

TEST(ModificaTransazioni,TransazioneInesistente){
    ContoCorrente conto;
    string temp="Lapo";

    bool x1=conto.addTransazione(make_unique<Transazione>(true,111,"Babbo","Regalo",50,year{2025},month{4},day{20}),testFile);
    bool x2=conto.modificaTransazione(110,temp,testFile);

    ASSERT_EQ(true,x1);
    ASSERT_EQ(false,x2);
}