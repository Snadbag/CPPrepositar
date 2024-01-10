#pragma once
#include "Hra.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

Hra::Hra() {
    std::string meno;

    for (int i = 0; i < 4; i++) {
        std::cout << "Meno " << i + 1 << " hraca" << ": ";
        std::getline(std::cin, meno);
        hraci.push_back(Hrac(meno));
    }
}

Hra::~Hra() {
}

void Hra::dajHracomKocky() {
    std::vector<int> cisla;
    std::vector<int> priority;
    
    std::srand((int)time(0));

    for (int i = 0; i < 4; i++) {
        priority.push_back(i);
    }

    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(priority), std::end(priority), rng);

    std::random_device crypto_random_generator;
    std::uniform_int_distribution<int> int_distribution2(1, 6);

    for (int i = 0; i < 4; i++) {
        std::uniform_int_distribution<int> int_distribution(0, 3 - i);
        int result = int_distribution(crypto_random_generator);
        int result2 = int_distribution2(crypto_random_generator);

        hraci[i].zoberKocku({ result2, priority[result] });

        priority.erase(priority.begin() + result);
    }
}

void Hra::hraj() {
    std::vector<std::string> farbyKociek;

    farbyKociek.push_back("BIELA");
    farbyKociek.push_back("MODRA");
    farbyKociek.push_back("HNEDA");
    farbyKociek.push_back("ZLATA");

    int najdlhsieMeno = 10;

    for (int i = 0; i < 4; i++) {
        if (hraci[i].getMeno().length() >= najdlhsieMeno) najdlhsieMeno = hraci[i].getMeno().length() + 1;
    }

    for (int i = 0; i < 4; i++) {
        std::string medzery = "";

        for (int j = hraci[i].getMeno().length(); j < najdlhsieMeno; j++) {
            medzery += " ";
        }

        std::cout << hraci[i].getMeno() << medzery;

        medzery.erase();
    }

    std::cout << std::endl;

    std::string zaKockami = "";

    for (int i = 0; i < najdlhsieMeno - 8; i++) {
        zaKockami += " ";
    }
    
    for (int i = 0; i < 10; i++) {
        dajHracomKocky();

        Hrac* najlepsiHrac = &hraci[0];

        for (int j = 1; j < 4; j++) {
            if (najlepsiHrac->getKocka().cislo > hraci[j].getKocka().cislo) {
                najlepsiHrac = &hraci[j];
            }
            else if (najlepsiHrac->getKocka().cislo == hraci[j].getKocka().cislo && najlepsiHrac->getKocka().priorita < hraci[j].getKocka().priorita) {
                najlepsiHrac = &hraci[j];
            }
        }

        (*najlepsiHrac).pridajSiBod();

        for (int j = 0; j < 4; j++) {
            std::cout << hraci[j].getKocka().cislo << " " << farbyKociek[hraci[j].getKocka().priorita] << "," << zaKockami;
        }

        std::cout << ": " << najlepsiHrac->getMeno() << "-" << najlepsiHrac->getKocka().cislo << " " << farbyKociek[najlepsiHrac->getKocka().priorita] << std::endl;
    }

    std::cout << "Vysledok:" << std::endl;

  

    for (int i = 0; i < 4; i++) {
        std::string medzery = "";

        for (int j = hraci[i].getMeno().length(); j < najdlhsieMeno; j++) {
            medzery += " ";
        }

        std::cout << hraci[i].getMeno() << medzery << ": " << hraci[i].getPocetVyhier() << std::endl;
        
        medzery.erase();
    }
}