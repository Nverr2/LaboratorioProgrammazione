//
// Created by nverl on 24/01/2025.
//

#include "ContoCorrente.h"

ContoCorrente::ContoCorrente() {

}

ContoCorrente::~ContoCorrente() {
    for (auto t : transazioni) {
        delete t;
    }

}

void ContoCorrente::stampaTransazioni() const {
    for (const auto& t : transazioni) {
        t->stampa();
    }
}
