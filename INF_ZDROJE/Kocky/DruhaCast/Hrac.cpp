#pragma once
#include "Hrac.h"
#include <string>

Hrac::~Hrac() {
}

std::string Hrac::getMeno() const {
    return meno;
}

Kocka Hrac::getKocka() const {
    return kocka;
}

int Hrac::getPocetVyhier() const {
    return pocetVyhier;
}

void Hrac::zoberKocku(Kocka dice) {
    kocka.cislo = dice.cislo;
    kocka.priorita = dice.priorita;
}

void Hrac::pridajSiBod() {
    pocetVyhier++;
}