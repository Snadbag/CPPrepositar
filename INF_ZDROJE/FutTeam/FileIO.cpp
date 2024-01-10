#include <iostream>

#include "FileIO.h"

auto FileIO::GetVsetkychFutbalistov() -> std::vector<Futbalista*> {
    std::vector<Futbalista*> Futbalisti;

    if (!m_InputFile.is_open()) {
        std::cerr << "Failed to open file.\n";
        return Futbalisti;
    }

    std::string meno, priezvisko;
    int pocetZapasov, pocetZltychkariet;

    while (m_InputFile >> priezvisko >> meno >> pocetZapasov >> pocetZltychkariet) {
        Futbalisti.push_back(new Futbalista(meno, priezvisko, pocetZapasov, pocetZltychkariet));
    }

    return Futbalisti;
}

auto FileIO::Zapis(const std::string& output) -> void {
    if (!m_OutputFile.is_open()) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    m_OutputFile << output;
}

FileIO::~FileIO() {
    m_InputFile.close();
    m_OutputFile.close();
}