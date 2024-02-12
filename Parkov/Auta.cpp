#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Struktúra pre auto
struct Auto {
    string SPZ;
    string casZaciatkuParkovania; // Zmena typu na string pre lepšie formátovanie
    double dobaParkovania;
    double platba;
    
};

// Funkcia pre načítanie SPZ zo súboru
vector<string> nacitajSPZ(const string& nazovSuboru) {
    vector<string> znacky;
    ifstream subor(nazovSuboru);

    if (subor.is_open()) {
        string SPZ;
        while (subor >> SPZ) {
            znacky.push_back(SPZ);
        }
        subor.close();
    }
    else {
        cerr << "Chyba pri otvaraní súboru s SPZ." << endl;
    }

    return znacky;
}

// Funkcia pre generovanie náhodného času v intervale <0, 23>
double generujAktualnyCas() {
    return rand() % 24;
}

// Funkcia pre generovanie náhodného času začiatku parkovania v intervale <0, 23>
string generujCasZaciatkuParkovania(double aktualnyCas) {
    int hodiny = static_cast<int>(aktualnyCas);
    int minuty = rand() % 60;

    stringstream ss;
    ss << hodiny << ":" << (minuty < 10 ? "0" : "") << minuty;

    return ss.str();
}

// Funkcia pre generovanie náhodnej doby parkovania v intervale <1, 240>
double generujDobuParkovania() {
    return rand() % 240 + 1;
}

// Funkcia pre výpočet platby za parkovanie
double vypocitajPlatbu(double dobaParkovania) {
    if (dobaParkovania <= 24) {
        return 0.5 * dobaParkovania;
    }
    else {
        int celeDni = static_cast<int>(dobaParkovania) / 24;
        return 5 * celeDni + 0.5 * (dobaParkovania - 24 * celeDni);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Pouzitie: " << argv[0] << " <nazov_suboru_so_SPZ>" << endl;
        return 1;
    }

    srand(time(0)); // Inicializácia generátora náhodných čísel

    vector<string> znacky = nacitajSPZ(argv[1]);
    double aktualnyCas = generujAktualnyCas();

    vector<Auto> parkovaneAuta;

    for (const auto& spz : znacky) {
        double casZaciatku = generujAktualnyCas();
        string casZaciatkuStr = generujCasZaciatkuParkovania(casZaciatku);

        if (parkovaneAuta.size() < 50 && casZaciatku >= aktualnyCas) {
            double dobaParkovania = generujDobuParkovania();
            double platba = vypocitajPlatbu(dobaParkovania);

            parkovaneAuta.push_back({ spz, casZaciatkuStr, dobaParkovania, platba });
        }
    }

    // Výpis na obrazovku
    //cout << "Poradove cislo   Znacka   Cas_zaciatku_parkovania   Doba_parkovania_v_hodinach   Platba_za_parkovanie" << endl;

    for (size_t i = 0; i < parkovaneAuta.size(); ++i) {
        const Auto& autoInfo = parkovaneAuta[i];
        cout << i + 1 << setw(10) << autoInfo.SPZ << setw(10) << autoInfo.casZaciatkuParkovania
            << setw(10) << autoInfo.dobaParkovania << setw(10) << autoInfo.platba << " eur" << endl;
    }

    return 0;
}
