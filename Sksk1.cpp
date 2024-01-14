// Sksk1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

class Pole
{
private:
    unsigned aVelkost = 0;
    int* aData = nullptr;
public:
    Pole(unsigned velkost)
        :aVelkost(velkost),
        aData(aVelkost > 0 ? new int[aVelkost] : nullptr) {}
    ~Pole() { delete[] aData; }

};

void Fun(Pole* p)// vyuzitia pointera .1
{

}

int main()
{
    Pole pole(100);
    Fun(&pole);//.2
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
