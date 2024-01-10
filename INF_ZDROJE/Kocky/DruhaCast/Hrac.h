#pragma once
#include <string>
#include "Kocka.h"

class Hrac {
private:
    std::string meno;
    Kocka kocka = { 0,0 };
    int pocetVyhier = 0;

public:
    Hrac(std::string meno) : meno(meno), pocetVyhier(0) {};

    std::string getMeno() const;
    Kocka getKocka() const;
    int getPocetVyhier() const;

    void zoberKocku(Kocka dice);
    void pridajSiBod();

    ~Hrac();
};