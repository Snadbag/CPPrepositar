#include <cstdio>

class Stvorec
{
    int obsah = 0;
    int strana = 0;
public:
    Stvorec(int pdlzka = 0) : strana(pdlzka), obsah(pdlzka * pdlzka) {} // = 0 za pdlzka
    Stvorec(Stvorec* pStvorec) {} // pridanie tohoto riadku
};

int main()
{
    Stvorec pole = new Stvorec[10];
    return 0;
}