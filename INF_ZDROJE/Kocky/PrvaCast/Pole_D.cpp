#include <iostream>

using namespace std;

class Pole
{
private:
	int* data = nullptr;
	int pocet = 0;	
public:
	Pole() {
	}
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

	friend ostream& operator<< (ostream& os, Pole& p)
	{
		for (int i = 0; i < p.pocet; i++)
			os << p.data[i] << endl;
		return os;
	}
};