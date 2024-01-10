#pragma once
#include <string>
using namespace std;

class Futbalista {
private:
    string Meno;
    string Priezvisko;
    int PocetZapasov;
    int PocetZltychKariet;
    int OdohrateMinuty;
    int UzitocnostHraca;
    int* MinutyZapasov;

public:
    Futbalista(string name, string lastName, int matchCount, int yellowCardCount);
    ~Futbalista();

    auto VygenerujOdohrateMinuty() -> void;
    auto GetUzitocnostHraca() -> double;
    auto GetMeno() -> string;
    auto GetPriezvisko() -> string;
    auto GetPocetZapasov() -> int;
    auto GetPocetZltychKariet() -> int;
    auto GetMinutyZapasov() -> int*;
    auto GetOdohrateMinuty() const -> int;

    static bool PorovnajPodlaUzitocnosti(const Futbalista* a, const Futbalista* b) {
        return a->UzitocnostHraca > b->UzitocnostHraca;
    }
};