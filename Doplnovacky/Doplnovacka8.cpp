// velmi komplexná úloha kde pôvodne bolo VynimkaBase, pridal sa virtual pred deštruktór
// A niekde sa pridali try a naopak niekde sa odstránili


#include <iostream>

class VynimkaA {
public:
    virtual void Oznam() { printf("A\n"); }
};

class VynimkaB : public VynimkaA {
public:
    void Oznam() { printf("B\n"); }
};

class VynimkaC : public VynimkaB {
public:
    void Oznam() { printf("C\n"); }
};

void Fun(int typ)
{
    try
    {
        switch (typ)
        {
        case 0: throw VynimkaA(); break;
        case 1: throw VynimkaB(); break;
        case 2: throw VynimkaC(); break;
        }
    }
    catch (VynimkaA& ex)
    {
        ex.Oznam();
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        Fun(i);
    }
}