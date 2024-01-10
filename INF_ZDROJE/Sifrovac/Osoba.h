#pragma once

class Osoba {
private:
    std::string m_Meno;
    std::string m_Priezvisko;
    int m_PocetZapasov;
    int m_PocetZltychKariet;
    int m_CelkovyPocetOdohranychMinut;
    double m_UzitocnostHraca;
    int* m_OdohranyCas;
public:
    Osoba(std::string lastName, std::string name, int pocetZapasov, int pocetZltychKariet);
    ~Osoba();

    auto VygenerujOdohranyCas() -> void;
    auto VypocitajUzitocnost() -> void;
    auto VypocitajCelkovyCas() -> void;
    auto GetMeno() -> std::string;
    auto GetPriezvisko() -> std::string;
    auto GetPocetZapasov() -> int;
    auto GetPocetZltychKariet() -> int;
    auto GetUzitocnost() -> double;
    auto GetOdohranyCasVypis() -> std::string;
    auto GetCelkovyPocetOdohranychMinut() const -> int;

    static bool PorovnajPodlaUzitocnosti(Osoba* a, Osoba* b) {
        return a->GetUzitocnost() > b->GetUzitocnost();
    }
};
