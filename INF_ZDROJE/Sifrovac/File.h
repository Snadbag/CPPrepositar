#pragma once

#include <fstream>
#include <vector>
#include "Osoba.h"

class File {
private:
    std::ifstream m_InputFile;
public:
    File(const char* input) : m_InputFile(input) {}
    ~File();

    auto GetVsetkyOsoby() -> std::vector<Osoba*>;

};
