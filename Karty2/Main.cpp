#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <iterator>
#include <tuple>

int main()
{
    // Define a tuple to represent a card with an int and a char
    std::tuple<int, char> karta;
    // Vector to represent a deck of cards
    std::vector<std::tuple<int, char>> balik;

    // Array of player names and an array to store their scores
    std::string hraci[4]{ "Peter", "Pavol", "Jozef", "Milan" };
    int skore[4]{ 0,0,0,0 };

    // Populate the deck with cards for each player
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            karta = std::make_pair(j + 1, i + 65);
            balik.push_back(karta);
        }
    }

    // Seed for the random shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Shuffle the deck using a random engine
    std::shuffle(balik.begin(), balik.end(), std::default_random_engine(seed));

    // Vector to represent the current round of cards
    std::vector<std::tuple<int, char>> kolo;

    // Iterate through each round (kolo)
    for (int kola = 0; kola < 8; kola++)
    {
        // Display the cards in the current round for each player
        for (int i = 0; i < 4; i++)
        {
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            kolo.push_back(balik.at(i));
        }

        // Sort the cards in the current round
        std::sort(std::begin(kolo), std::end(kolo));

        // Find the player with the lowest card in the current round
        auto it = std::find(balik.begin(), balik.end(), kolo.at(0));
        int index = 0;
        // If the element was found, determine the index
        if (it != balik.end())
        {
            index = it - balik.begin();
        }
        else {
            std::cout << "chyba" << std::endl;
        }
        // Display the winner of the round
        std::cout << ": " << hraci[index] << " " << std::get<0>(balik.at(index)) << std::get<1>(balik.at(index)) << std::endl;

        // Update the score of the winning player
        skore[index]++;

        // Remove the used cards from the deck
        for (int i = 0; i < 4; i++)
        {
            balik.erase(balik.begin());
        }

        // Clear the current round vector for the next iteration
        kolo.clear();
    }

    // Display the final scores
    std::cout << std::endl << "Vysledok:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << hraci[i] << ": " << skore[i] << std::endl;
    }
}
