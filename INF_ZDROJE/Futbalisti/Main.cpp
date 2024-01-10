#include <iostream>
#include <sstream>
#include <algorithm>

#include "futbalista.h"
#include "File.h"

int main(int argc, char** argv) {
    //if (argc != 1) {
        //std::cerr << "Invalid arguments provided.\n";
        //return EXIT_FAILURE;
    //}

    const char* inputFileName = argv[1];

    auto file = new File(inputFileName);

    auto futbalisti = file->GetVsetkychFutbalistov();
    std::sort(futbalisti.begin(), futbalisti.end(), Futbalista::PorovnajPodlaUzitocnosti);

    for (const auto& futbalista : futbalisti) {
        std::stringstream output;
        output.setf(std::ios::fixed);
        output.precision(2);

        output << futbalista->GetMeno() << " "
            << futbalista->GetPriezvisko() << " <"
            << futbalista->GetPocetZltychKariet() << "> "
            << futbalista->GetUzitocnost() << " "
            << futbalista->GetCelkovyPocetOdohranychMinut() << " ["
            << futbalista->GetPocetZapasov() << "]-"
            << futbalista->GetOdohranyCasVypis();

        output << "\n";

        std::cout << output.str();
    }

    for (auto futbalista : futbalisti) {
        delete futbalista;
    }
    delete file;
    return 0;
}