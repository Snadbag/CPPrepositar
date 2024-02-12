#include <cstdio>

class VynimkaA
{
public:
    void Oznam() { printf("A\n"); }
};

class VynimkaB : public VynimkaA
{
public:
    void Oznam() { printf("B\n"); }
};

class VynimkaC : public VynimkaB
{
public:
    void Oznam() { printf("C\n"); }
};

void Fun(int typ)
{
    switch (typ)
    {
    case 0: throw VynimkaA(); break;
    case 1: throw VynimkaB(); break;
    case 2: throw VynimkaC(); break;
    }
}

// Doplnené catch blocky v maine aby sa zachytili všetky 3 výnimky
int main()
{
    for (int i = 0; i < 3; i++)
    {
        try
        {
            Fun(i);
        }
        catch (VynimkaC& vynimka)
        {
            vynimka.Oznam();
        }
        catch (VynimkaB& vynimka)
        {
            vynimka.Oznam();
        }
        catch (VynimkaA& vynimka)
        {
            vynimka.Oznam();
        }

    }
    return 0;
}