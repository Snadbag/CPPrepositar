#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "hrac.h"
#include "nacitanie.h"
#include "porovnaj.h"

/*struct Hrac {
    std::string meno;
    std::string priezvisko;
    int pocet_zapasov;
    int pocet_žltých_kariet;
    int* odohrane_minuty;

    Hrac(const std::string& priezv, const std::string& m, int zapasy, int zlte_karty)
        : priezvisko(priezv), meno(m), pocet_zapasov(zapasy), pocet_žltých_kariet(zlte_karty), odohrane_minuty(nullptr) {
        odohrane_minuty = new int[pocet_zapasov];

        for (int i = 0; i < pocet_zapasov; ++i) {
            odohrane_minuty[i] = rand() % 49 + 2; // Generate a random number of played minutes between 2 and 50
        }
    }


    int celkovyPocetOdohranychMinut() const {
        int suma = 0;
        for (int i = 0; i < pocet_zapasov; ++i) {
            suma += odohrane_minuty[i];
        }
        return suma;
    }

    double uzitocnostHraca() const {
        if (pocet_zapasov == 0) return 0.0;
        return static_cast<double>(celkovyPocetOdohranychMinut()) / pocet_zapasov / pocet_žltých_kariet;
    }
}; */


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Nespravny argument.\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr))); //nahodny seed pre nove cisla

    std::string nazovSuboru = argv[1];
    std::vector<Hrac> hraci = nacitajHracov(nazovSuboru);

    std::sort(hraci.begin(), hraci.end(), porovnajHracov);

    for (const auto& hrac : hraci) {
        std::cout << std::setw(11) << hrac.meno << std::setw(11) << hrac.priezvisko << std::setw(5)
            << " <" << hrac.pocet_žltých_kariet << "> " 
            << std::setw(8) << std::fixed << std::setprecision(2) << hrac.uzitocnostHraca()
            << std::setw(8) << hrac.celkovyPocetOdohranychMinut() << std::setw(8) << " [" << hrac.pocet_zapasov << "] - ";
        for (int i = 0; i < hrac.pocet_zapasov; ++i) {
            std::cout << hrac.odohrane_minuty[i] << ' ';
        }
        std::cout << std::endl;
    }

    for (auto& hrac : hraci) {
        delete[] hrac.odohrane_minuty;
    }

    return 0;
}
