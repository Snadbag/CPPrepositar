#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

struct Kocka {
    int hod;
    int priorita;

};

class Hrac {

    std::string meno;
    Kocka kocka = { 0, 0 };
    int pocetVyhier = 0;
    //int hod = 0;

public:
    void dostanKocku(Kocka koc) {
        kocka.hod = koc.hod; 
        kocka.priorita = koc.priorita;
       // koc.hod = rand() % 6 + 1;
    }

    std::string getMeno() {
        return meno;
    };

    int getVyhry() const {
        return pocetVyhier;
    }
    void plusVyhra() {
        pocetVyhier++;
    }

    Kocka getKocka() const {
        return kocka;
    }
};

class Priradenie {
public:
    std::vector<Hrac> hraci;
    

    void rozdelKocky() {
        std::vector<int> hody;
        std::vector<int> priority;

        srand(static_cast<unsigned>(time(0)));

        hraci.resize(4);

        // Initialize the hraci vector with 4 Hrac objects
        

        for (int i = 0; i < 4; i++) {
            priority.push_back(i);
        }
        auto rng = std::default_random_engine{};
        std::random_shuffle(std::begin(priority), std::end(priority));

        std::random_device crypto_random_generator;
        std::uniform_int_distribution<int> int_distribution2(1, 6);

        for (int i = 0; i < 4; i++) {
            //std::random_shuffle(std::begin(priority), std::end(priority));
            std::uniform_int_distribution<int> int_distribution(0, 3 - i);
            int result = int_distribution(crypto_random_generator); 
            int result2 = int_distribution2(crypto_random_generator);


            hraci[i].dostanKocku({ result2 ,priority[result] });

            priority.erase(priority.begin()+ result);
        }
    }

};

int main() {
    //srand(static_cast<unsigned>(time(0)));
    Hrac Peter, Pavol, Jozef, Milan;
    

    std::vector<std::string> farbyKociek;

    farbyKociek.push_back("BIELA");
    farbyKociek.push_back("MODRA");
    farbyKociek.push_back("HNEDA");
    farbyKociek.push_back("ZLATA");



    std::cout << "Peter" << std::setw(12) << "Pavol" << std::setw(12) << "Jozef" << std::setw(12) << "Milan";

    Priradenie priradenie;
    

    for (int kolo = 0; kolo < 10; kolo++) {
        priradenie.rozdelKocky();
        Hrac* najlepsiHrac = &priradenie.hraci[0];

        for (int i = 1; i < 4; i++) {
            if (najlepsiHrac->getKocka().hod > priradenie.hraci[i].getKocka().hod) {
                najlepsiHrac = &priradenie.hraci[i];
            }
            else if (najlepsiHrac->getKocka().hod == priradenie.hraci[i].getKocka().hod && najlepsiHrac->getKocka().priorita < priradenie.hraci[i].getKocka().priorita) {
                najlepsiHrac = &priradenie.hraci[i];
            }

            
        } 
        for (int j = 0; j < 4; j++) {
            std::cout << priradenie.hraci[j].getKocka().hod;// << farbyKociek[priradenie.hraci[j].getKocka().priorita];
        }

        (*najlepsiHrac).plusVyhra();

      // for (int j = 0; j < 4; j++) {
       //    std::cout << priradenie.hraci[j].hodKockou() << " " << farbyKociek[priradenie.hraci[j].getKocka().priorita];
        //}

        //std::cout << ": " << najlepsiHrac->getMeno() << "-" << najlepsiHrac->getKocka().cislo << " " << farbyKociek[najlepsiHrac->getKocka().priorita] << std::endl;
       

    std::cout << "Vysledok:" << std::endl;

        //int maxHod = najvyssiHod(Peter, Pavol, Jozef, Milan);

        //std::cout << "\n" << Peter.hod << std::setw(12) << Pavol.hod << std::setw(12) << Jozef.hod << std::setw(12) << Milan.hod;

        //Hrac* vitaz = najvyssiHod(Peter, Pavol, Jozef, Milan);

       // std::cout << std::setw(12) << *vitaz << std::endl;

    }

    std::cout << "\nCelkove vyhry:" << std::endl;
    std::cout << priradenie.hraci[0].getMeno() << " " << priradenie.hraci[0].getVyhry() << std::endl;
    std::cout << priradenie.hraci[1].getMeno() << " " << priradenie.hraci[1].getVyhry() << std::endl;
    std::cout << priradenie.hraci[2].getMeno() << " " << priradenie.hraci[2].getVyhry() << std::endl;
    std::cout << priradenie.hraci[3].getMeno() << " " << priradenie.hraci[3].getVyhry() << std::endl;

    return 0;
}
