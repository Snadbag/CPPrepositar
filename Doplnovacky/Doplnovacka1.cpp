// Pridanie delete do deštruktóra lebo sa inicializuje iba 1 hodnota

#include <iostream>
using namespace std;

class Data
{
private:
    int* data = nullptr;
public:
    Data(int val) : data(new int(val))
    {
    }
    ~Data() {
        delete data;
    }
    int getData() {
        return *data; 
    }
};

int main()
{
    Data D1(5), D2(2);
    cout << D1.getData() << endl << D2.getData() << endl;
    return 0;
}