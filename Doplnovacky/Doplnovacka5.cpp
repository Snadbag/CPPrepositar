#include <iostream>
using namespace std;
class Osoba
{
private:
	string meno = nullptr;
public:
	Osoba(const char* pmeno)
		: meno(pmeno)
	{
	}
	void Vypis()
	{
		cout << meno << endl;
	}
};

class DospelaOsoba : public Osoba // pred Osobu pridať public
{
private:
	int vek = 18;
public:
	DospelaOsoba(const char* pmeno, int pvek = 18)
		: Osoba(pmeno), vek(pvek)
	{}
};

int main()
{
	DospelaOsoba clovek("Rene Novak");
	clovek.Vypis();
	return 0;
}