#include <iostream>
#include <sstream>

#include "Futbalista.h"
#include "FileIO.h"
#include <random>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Invalid arguments provided.\n";
        return EXIT_FAILURE;
    }

    std::srand(std::time(nullptr));

    const char* inputFileName = argv[1];
    const char* outputFileName = "output.txt";

    auto fileIO = new FileIO(inputFileName, outputFileName);

    auto Futbalisti = fileIO->GetVsetkychFutbalistov();
    std::sort(Futbalisti.begin(), Futbalisti.end(), Futbalista::PorovnajPodlaUzitocnosti);

    for (const auto& Futbalista : Futbalisti) {
        std::stringstream output;
        //output.precision(3);

        output << Futbalista->GetMeno() << " "
            << Futbalista->GetPriezvisko() << " "
            << "<" << Futbalista->GetPocetZltychKariet() << "> "
            << Futbalista->GetUzitocnostHraca() << " "
            << Futbalista->GetOdohrateMinuty() << " ["
            << Futbalista->GetPocetZapasov() << "] "
            << "- ";

            for (auto i = 0; i < Futbalista->GetPocetZapasov(); ++i) {
            output << Futbalista->GetMinutyZapasov()[i] << " ";
        }
        output << "\n";

        std::cout << output.str();
        fileIO->Zapis(output.str());
    }

    for (auto Futbalista : Futbalisti) {
        delete Futbalista;
    }

    delete fileIO;
    return 0;
}