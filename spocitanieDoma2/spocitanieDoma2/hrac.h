#pragma once

#include <string>
#include "hrac.h"

struct Hrac {
    std::string meno;
    std::string priezvisko;
    int pocet_zapasov;
    int pocet_žltých_kariet;
    int* odohrane_minuty;

    Hrac(const std::string& priezv, const std::string& m, int zapasy, int zlte_karty);

    int celkovyPocetOdohranychMinut() const;

    double uzitocnostHraca() const;
};