#pragma once

#include <fstream>
#include <vector>
#include "Futbalista.h"

class FileIO {
private:
    std::ifstream m_InputFile;
    std::ofstream m_OutputFile;
public:
    FileIO(const char* input, const char* output) : m_InputFile(input), m_OutputFile(output) {}
    ~FileIO();

    auto GetVsetkychFutbalistov() -> std::vector<Futbalista*>;
    auto Zapis(const std::string& output) -> void;
};
