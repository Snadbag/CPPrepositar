#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "hrac.h"

std::vector<Hrac> nacitajHracov(const std::string& nazovSuboru) {
    std::vector<Hrac> hraci;
    std::ifstream subor(nazovSuboru);

    if (!subor.is_open()) {
        std::cerr << "Nepodarilo sa otvorit subor: " << nazovSuboru << std::endl;
        return hraci;
    }

    std::string priezvisko, meno;
    int zapasy, zlte_karty;
    while (subor >> priezvisko >> meno >> zapasy >> zlte_karty) {
        hraci.emplace_back(priezvisko, meno, zapasy, zlte_karty);
    }

    subor.close();
    return hraci;
}