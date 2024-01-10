#pragma once
#include "Karty.h"
#include <string>

class Hrac {
private:
    std::string meno;
    int pocetVyhier;
    Karty karty;

public:
    Hrac(std::string meno);

    std::string getMeno() const;
    Karty getKarty() const;
    int getPocetVyhier() const;

    void zoberKarty(int paCislaKariet[], int paZnakyKariet[]);
    void pridajSiBod();

    ~Hrac();
};