// hrac.cpp
#include "hrac.h"
#include <ctime>
#include <cstdlib>

Hrac::Hrac(const std::string& priezv, const std::string& m, int zapasy, int zlte_karty)
    : priezvisko(priezv), meno(m), pocet_zapasov(zapasy), pocet_žltých_kariet(zlte_karty), odohrane_minuty(nullptr) {
    odohrane_minuty = new int[pocet_zapasov];

    for (int i = 0; i < pocet_zapasov; ++i) {
        odohrane_minuty[i] = rand() % 49 + 2; // Generate a random number of played minutes between 2 and 50
    }
}

/*Hrac::~Hrac() {
    delete[] odohrane_minuty;
}*/

int Hrac::celkovyPocetOdohranychMinut() const {
    int suma = 0;
    for (int i = 0; i < pocet_zapasov; ++i) {
        suma += odohrane_minuty[i];
    }
    return suma;
}

double Hrac::uzitocnostHraca() const {
    if (pocet_zapasov == 0) return 0.0;
    return static_cast<double>(celkovyPocetOdohranychMinut()) / pocet_zapasov / pocet_žltých_kariet;
}
