#include <ctime>
#include <random>
#include <iostream>
#include <sstream>
#include "Osoba.h"

Osoba::Osoba(std::string lastName, std::string name, int pocetZapasov, int pocetZltychKariet) {
    m_Meno = name;
    m_Priezvisko = lastName;
    m_PocetZapasov = pocetZapasov;
    m_OdohranyCas = new int[m_PocetZapasov];
    m_PocetZltychKariet = pocetZltychKariet;

    VygenerujOdohranyCas();
    VypocitajCelkovyCas();
    VypocitajUzitocnost();
}

Osoba::~Osoba() {
    delete[] m_OdohranyCas;
}

auto Osoba::VygenerujOdohranyCas() -> void {
    std::srand(std::time(nullptr));

    for (int i = 0; i < m_PocetZapasov; ++i) {
        m_OdohranyCas[i] = std::rand() % 48 + 2;

    }
}

auto Osoba::VypocitajUzitocnost() -> void
{
    double x = std::round(((double)m_CelkovyPocetOdohranychMinut / (double)m_PocetZapasov) * 100) / 100;

    m_UzitocnostHraca = std::round((x / m_PocetZltychKariet) * 100) / 100;
}

auto Osoba::GetUzitocnost() -> double {
    return m_UzitocnostHraca;
}

auto Osoba::GetCelkovyPocetOdohranychMinut() const -> int {
    return  m_CelkovyPocetOdohranychMinut;
}

auto Osoba::VypocitajCelkovyCas() -> void
{
    int sucet = 0;
    for (int i = 0; i < m_PocetZapasov; i++) {
        sucet += m_OdohranyCas[i];
    }
    m_CelkovyPocetOdohranychMinut = sucet;

}

auto Osoba::GetMeno() -> std::string {
    return m_Meno;
}

auto Osoba::GetPriezvisko() -> std::string {
    return m_Priezvisko;
}

auto Osoba::GetPocetZapasov() -> int
{
    return m_PocetZapasov;
}

auto Osoba::GetPocetZltychKariet() -> int
{
    return m_PocetZltychKariet;
}


auto Osoba::GetOdohranyCasVypis() -> std::string
{
    std::ostringstream s;
    int x;

    for (int i = 0; i < m_PocetZapasov; i++) {
        x = m_OdohranyCas[i];
        s << x << " ";

    }
    return s.str();
}
