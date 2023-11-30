#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<vec> nacitajVeci(const std::string& nazovSuboru) {
    std::vector<vec> veci;
    std::ifstream subor(nazovSuboru);

    if (!subor.is_open()) {
        std::cerr << "Neda sa otvorit: " << nazovSuboru << std::endl;
        return veci;
    }

    std::string vecA, vecB; // tu poradie nevadi
    int vecC;
    while (subor >> vecB >> vecA >> vecC) { // tu poradie radí
        veci.emplace_back(vecB, vecA, vecC);
    }

    subor.close();
    return veci;
}