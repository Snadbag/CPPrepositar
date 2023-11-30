#include <fstream>
#include <iostream>
#include "hrac.h"

bool porovnajHracov(const Hrac& a, const Hrac& b) {
    return a.uzitocnostHraca() > b.uzitocnostHraca();
}