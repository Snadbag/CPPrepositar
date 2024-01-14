// Kocky1-Op.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Kocka {
public:
    int hod() {
        return rand() % 6 + 1;
    }
};

class Hrac {
public:
    std::vector<int> hodnoty;

    void pridajHod(int hod) {
        hodnoty.push_back(hod);
    }

    int ziskajSucet() const {
        int sucet = 0;
        for (int hod : hodnoty) {
            sucet += hod;
        }
        return sucet;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Kocka kocka;
    Hrac hracA, hracB;

    int pocetVyhierA = 0;
    int pocetVyhierB = 0;


    std::ofstream vystupnySubor("vysledok.txt");

    for (int kolo = 0; kolo < 50; ++kolo) {
       

        for (int vrh = 0; vrh < 3; ++vrh) {
            hracA.pridajHod(kocka.hod());
            hracB.pridajHod(kocka.hod());
        }

        int sucetA = hracA.ziskajSucet();
        int sucetB = hracB.ziskajSucet();

        //vypis kazdy hod
        std::cout << kolo + 1 << ". A: " << hracA.hodnoty[0] << "+" << hracA.hodnoty[1] << "+" << hracA.hodnoty[2] << " = " << sucetA;
        std::cout << "\n" << kolo + 1 << ". B: " << hracB.hodnoty[0] << "+" << hracB.hodnoty[1] << "+" << hracB.hodnoty[2] << " = " << sucetB;

            std::cout << std::endl;
            std::cout << "\n";

            //zisti kto vyhral kolo
            if (sucetA > sucetB) {
                pocetVyhierA++;
            }
            else if (sucetB > sucetA) {
                pocetVyhierB++;
            }

            // Vyprázdnenie hodnot pre ďalšie kolo
            hracA.hodnoty.clear();
            hracB.hodnoty.clear();
        }

        vystupnySubor << "Vysledky hry:" << std::endl;
        vystupnySubor << "A: " << pocetVyhierA << " vitazstiev" << std::endl;

        vystupnySubor << "B: " << pocetVyhierB << " vitazstiev" << std::endl;


        // Výpis na konzolu
        //std::cout << "\nCelkove body:" << std::endl;
        std::cout << "A: " << pocetVyhierA << " bodov " << std::endl;
        std::cout << "B: " << pocetVyhierB << " bodov " << std::endl;


        vystupnySubor.close();

        return 0;
    

}