class Obdlznik {
	int stranaA = 0;
	int stranaB = 0;
public:
	Obdlznik(int pStranaA, int pStranaB)
		: stranaA(pStranaA), stranaB(pStranaB)
	{
	}
	Obdlznik() = default; // treba doplniť tento riadok aby bol kód skompilovateľný
};

int main()
{
	Obdlznik pole[10];
	return 0;
}