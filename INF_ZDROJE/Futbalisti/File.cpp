#include <iostream>

#include "File.h"

auto File::GetVsetkychFutbalistov() -> std::vector<Futbalista*> {
    std::vector<Futbalista*> futbalisti;

    if (!m_InputFile.is_open()) {
        std::cerr << "Failed to open file.\n";
        return futbalisti;
    }

    std::string meno, priezvisko;
    int pocetZapasov;
    int pocetZltychKariet;

    while (m_InputFile >> meno >> priezvisko  >> pocetZapasov >> pocetZltychKariet) {
        futbalisti.push_back(new Futbalista(meno, priezvisko, pocetZapasov, pocetZltychKariet));
    }

    return futbalisti;
}

File::~File() {
    m_InputFile.close();
}