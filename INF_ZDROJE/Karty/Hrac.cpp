#pragma once
#include "Hrac.h"
#include <string>

Hrac::Hrac(std::string meno) : meno(meno), pocetVyhier(0) {}

Hrac::~Hrac() {
}

std::string Hrac::getMeno() const {
    return meno;
}

Karty Hrac::getKarty() const {
    return karty;
}

int Hrac::getPocetVyhier() const {
    return pocetVyhier;
}

void Hrac::zoberKarty(int cislaKariet[], int znakyKariet[]) {
    for (int i = 0; i < 8; ++i) {
        karty.cislaKariet[i] = cislaKariet[i];
        karty.znakyKariet[i] = znakyKariet[i];
    }
}

void Hrac::pridajSiBod() {
    pocetVyhier++;
}