#include <iostream>

using namespace std;

class Pole
{
private:
	int pocet = 0;
	int* data = nullptr;
public:
	Pole(int poc)
		: pocet(poc), data(pocet > 0 ? new int[pocet] : nullptr)
	{
		if (pocet > 0)
		{
			for (int i = 0; i < pocet; i++)
					data[i] = 0;
		}
	}
	~Pole() { delete[] data; }
	
	friend ostream& operator<< (ostream& os, const Pole& p) // pridanie const a ptm & za Pole, býva aj varianta pridať friend
	{
		for (int i = 0; i < p.pocet; i++)
			os << p.data[i] << endl;
		return os;
	}
};

int main()
{
	Pole p(5);
	cout << p;
	return 0;
}