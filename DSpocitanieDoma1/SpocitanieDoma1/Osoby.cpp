#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Hrac {
    std::string priezvisko;
    std::string meno;
    int pocetZapasov;
    int pocetZltychKariet;
    int* odohraneMinuty; // Dynamické pole pre odohrané minúty
};

// Funkcia na výpočet užitočnosti hráča
double vypocitajUzitocnost(const Hrac& hrac) {
    double celkovyCas = 0;
    for (int i = 0; i < hrac.pocetZapasov; ++i) {
        celkovyCas += hrac.odohraneMinuty[i];
    }

    double uzitocnost = celkovyCas / hrac.pocetZapasov / hrac.pocetZltychKariet;
    return uzitocnost;
}

int main(int argc, char* argv[]) {
    // Overenie, či bol zadný správny počet parametrov
    if (argc != 2) {
        std::cerr << "Chyba: Zadajte meno vstupneho suboru." << std::endl;
        return 1;
    }

    // Názov vstupného súboru
    std::string nazovSuboru = argv[1];

    // Načítanie hráčov zo súboru
    std::ifstream subor(nazovSuboru);
    if (!subor.is_open()) {
        std::cerr << "Chyba: Subor sa nepodarilo otvorit." << std::endl;
        
    }

    // Uloženie hráčov do vektoru
    std::vector<Hrac> hraci;
    while (!subor.eof()) {
        Hrac hrac;
        subor >> hrac.priezvisko >> hrac.meno >> hrac.pocetZapasov >> hrac.pocetZltychKariet;

        // Dynamická alokácia pre odohrané minúty
        hrac.odohraneMinuty = new int[hrac.pocetZapasov];
        for (int i = 0; i < hrac.pocetZapasov; ++i) {
            subor >> hrac.odohraneMinuty[i];
        }

        hraci.push_back(hrac);
    }
    subor.close();

    // Výpočet užitočnosti a zoradenie hráčov podľa nej
    std::sort(hraci.begin(), hraci.end(), [](const Hrac& a, const Hrac& b) {
        return vypocitajUzitocnost(a) > vypocitajUzitocnost(b);
        });

    // Výpis do konzoly a do súboru
    std::ofstream vystupnySubor("vystup.txt");
    for (const auto& hrac : hraci) {
        double uzitocnost = vypocitajUzitocnost(hrac);
        std::cout << hrac.meno << " " << hrac.priezvisko << " <" << hrac.pocetZltychKariet << "> Uzitocnost: "
            << uzitocnost << " Celkovy cas: [" << hrac.pocetZapasov << "] - ";
        for (int i = 0; i < hrac.pocetZapasov; ++i) {
            std::cout << hrac.odohraneMinuty[i] << " ";
        }
        std::cout << std::endl;

        // Výpis do súboru
        vystupnySubor << hrac.meno << " " << hrac.priezvisko << " <" << hrac.pocetZltychKariet << "> Uzitocnost: "
            << uzitocnost << " Celkovy cas: [" << hrac.pocetZapasov << "] - ";
        for (int i = 0; i < hrac.pocetZapasov; ++i) {
            vystupnySubor << hrac.odohraneMinuty[i] << " ";
        }
        vystupnySubor << std::endl;
    }
    vystupnySubor.close();

    // Uvoľnenie pamäte pre odohrané minúty
    for (auto& hrac : hraci) {
        delete[] hrac.odohraneMinuty;
    }

    return 0;
}