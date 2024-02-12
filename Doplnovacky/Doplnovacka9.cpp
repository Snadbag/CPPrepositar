#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


class Pole
{
private:
    int* dataInt = nullptr;
public:
    Pole(int pocet = 0) : dataInt(pocet>0?new int[pocet]:nullptr){}
    virtual ~Pole() { delete[] dataInt; } // pred deštruktór Pola treba pridať virtual
};

class PoleIntDouble : public Pole
{
private:
    double* dataDouble = nullptr;
public:
    PoleIntDouble(int pocet = 0) : Pole(pocet), dataDouble(pocet > 0 ? new double[pocet] : nullptr){}
    ~PoleIntDouble() { delete[] dataDouble; }
};

int main()
{
    Pole* p = new PoleIntDouble(10);
    delete p;

    _CrtDumpMemoryLeaks();
    return 0;
}