#pragma once

#include <fstream>
#include <vector>
#include "Futbalista.h"

class File {
private:
    std::ifstream m_InputFile;
public:
    File(const char* input) : m_InputFile(input) {}
    ~File();

    auto GetVsetkychFutbalistov() -> std::vector<Futbalista*>;
   
};
