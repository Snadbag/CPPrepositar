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
        std::cout << "Enter the name for player " << i + 1 << ": ";
        std::getline(std::cin, meno);
        hraci.push_back(Hrac(meno));
    }

    dajHracomKarty();
}

Hra::~Hra() {
}

void Hra::dajHracomKarty() {
    int cisla[32];
    int znaky[32];
    int indexy[32];

    for (int i = 0; i < 32; i++) {
        indexy[i] = i;
    }

    std::random_shuffle(std::begin(indexy), std::end(indexy));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; j++) {
            cisla[i * 8 + j] = j + 1;
            znaky[i * 8 + j] = 65 + i;
        }
    }

    int cislaPreHraca[8];
    int znakyPreHraca[8];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cislaPreHraca[j] = cisla[indexy[i * 8 + j]];
            znakyPreHraca[j] = znaky[indexy[i * 8 + j]];
        }

        hraci[i].zoberKarty(cislaPreHraca, znakyPreHraca);
    }
}

void Hra::hraj() {
    for (int i = 0; i < 8; i++) {
        Hrac* najlepsiHrac = &hraci[0];

        for (int j = 1; j < 4; j++) {
            if (najlepsiHrac->getKarty().cislaKariet[i] < hraci[j].getKarty().cislaKariet[i]) {
                najlepsiHrac = &hraci[j];
            } else if (najlepsiHrac->getKarty().cislaKariet[i] == hraci[j].getKarty().cislaKariet[i] && najlepsiHrac->getKarty().znakyKariet[i] > hraci[j].getKarty().znakyKariet[i]) {
                najlepsiHrac = &hraci[j];
            }
        }

        (*najlepsiHrac).pridajSiBod();

        for (int j = 0; j < 4; j++) {
            std::cout << hraci[j].getKarty().cislaKariet[i] << char(hraci[j].getKarty().znakyKariet[i]) << ' ';
        }

        std::cout << ": " << najlepsiHrac->getMeno() << " " << najlepsiHrac->getKarty().cislaKariet[i] << char(najlepsiHrac->getKarty().znakyKariet[i]) << std::endl;
    }

    std::cout << "Vysledok:" << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << hraci[i].getMeno() << " " << hraci[i].getPocetVyhier() << std::endl;
    }
}