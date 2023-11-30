#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Osoba {
	std::string meno;
	std::string priezvisko;
	int PocetPretekov;
	int* umiestnenia;

    Osoba(const std::string& priezv, const std::string& m, int preteky)
        : priezvisko(priezv), meno(m), PocetPretekov(preteky), umiestnenia(nullptr) {
        umiestnenia = new int[PocetPretekov];
        
        for (int i = 0; i < PocetPretekov; ++i) {
            umiestnenia[i] = rand() % 30 + 1; // Generate a random placement between 1 and 30
        }

    }

    double vypocitajPriemerUmiestneni() const {
        if (PocetPretekov == 0) return 0.0;
        double suma = 0.0;
        for (int i = 0; i < PocetPretekov; ++i) {
            suma += umiestnenia[i];
        }
        return suma / PocetPretekov;
    }

    int dokopyBody() const {
        int body = 0;
        for (int i = 0; i < PocetPretekov; ++i) {
            body += (30 - umiestnenia[i] - 1);
        }
        return body;
    }

};

std::vector<Osoba> nacitajOsoby(const std::string& nazovSuboru) {
    std::vector<Osoba> osoby;
    std::ifstream subor(nazovSuboru);

    if (!subor.is_open()) {
        std::cerr << "Nepodarilo sa otvorit subor: " << nazovSuboru << std::endl;
        return osoby;
    }

    std::string priezvisko, meno;
    int preteky;
    while (subor >> priezvisko >> meno >> preteky) {
        osoby.emplace_back(priezvisko, meno, preteky);
    }

    subor.close();
    return osoby;
}
   
bool porovnaj(const Osoba& a, const Osoba& b) {
    return a.dokopyBody() > b.dokopyBody();
}

int main(int argc,char* argv[]) {

    if (argc != 2) {
        std::cerr << "nespravny argument.\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr))); //nahodny seed pre nove cisla

    std::string nazovSuboru = argv[1];
    std::vector<Osoba> osoby = nacitajOsoby(nazovSuboru);

    std::sort(osoby.begin(), osoby.end(),porovnaj );


    for (const auto& osoba : osoby) {
        std::cout << std::setw(12) << osoba.priezvisko << std::setw(12) << osoba.meno
            << std::setw(5) << osoba.dokopyBody() << std::setw(5) << osoba.PocetPretekov
            << std::setw(30) << std::fixed << std::setprecision(4) << osoba.vypocitajPriemerUmiestneni() << " - ["
            << osoba.PocetPretekov << "] ";
        for (int i = 0; i < osoba.PocetPretekov; ++i) {
            std::cout << osoba.umiestnenia[i] << ' ';
        }
        std::cout << std::endl;
    }

    for(auto& osoba : osoby) {
        delete[] osoba.umiestnenia;
    }
    
    return 0;
}