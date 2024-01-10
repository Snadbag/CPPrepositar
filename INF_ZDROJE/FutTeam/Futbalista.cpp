#include <ctime>
#include <random>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Futbalista.h"

Futbalista::Futbalista(std::string name, std::string lastName, int pocetZapasov, int pocetZltychkariet) {
    Meno = name;
    Priezvisko = lastName;
    PocetZapasov = pocetZapasov < 0 ? 0 : pocetZapasov;
    MinutyZapasov = new int[pocetZapasov <= 0 ? 1 : pocetZapasov];
    PocetZltychKariet = pocetZltychkariet;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    VygenerujOdohrateMinuty();
    OdohrateMinuty = GetOdohrateMinuty();

    UzitocnostHraca = GetUzitocnostHraca(); 
}

auto Futbalista::VygenerujOdohrateMinuty() -> void {
    

    for (int i = 0; i < PocetZapasov; ++i) {
        MinutyZapasov[i] = std::rand() % 49 + 2;
    }
}

auto Futbalista::GetOdohrateMinuty() const -> int {
    double sucet = 0;

    for (int i = 0; i < PocetZapasov; ++i) {
        sucet += MinutyZapasov[i];
    }

    return sucet;
}

auto Futbalista::GetUzitocnostHraca() -> double {
    double uzitocnost = 0;

    if (PocetZapasov <= 0) return 0;

    uzitocnost = std::round((OdohrateMinuty / PocetZapasov/ (PocetZltychKariet <= 0 ? 1 : PocetZltychKariet),2) * 100) / 100;

    return uzitocnost;
}

auto Futbalista::GetMeno() -> std::string {
    return Meno;
}

auto Futbalista::GetPriezvisko() -> std::string {
    return Priezvisko;
}

auto Futbalista::GetPocetZapasov() -> int {
    return PocetZapasov;
}

auto Futbalista::GetPocetZltychKariet() -> int {
    return PocetZltychKariet;
}

auto Futbalista::GetMinutyZapasov() -> int* {
    return MinutyZapasov;
}

Futbalista::~Futbalista() {
    delete[] MinutyZapasov;
}