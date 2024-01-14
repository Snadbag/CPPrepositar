// SKsk2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
class Pole
{
private:
    int pocet = 0;
    int* data = nullptr; // bolo treba dat nullptr ako posledny
public:
    Pole(int poc)
        : pocet(poc), data(pocet > 0 ? new int[pocet] : nullptr)
    {
        if (pocet > 0) {
            for (int i = 0; i < pocet; i++)
                data[i] = 0;
        }

    }
    ~Pole() { delete[] data; }
    ostream& operator<< (ostream& os) // Pole& p nedava zmysel
    {
        for (int i = 0; i < pocet; i++)// p.pocet tu nema co robit
            os << data[i] << endl;
        return os;
    }
};

int main()
{
    Pole p(5);
    p << cout;// cout << p bol zle, return 0 netreba
}