class Pole
{
private:
    int pocet = 0;
    int* data = nullptr;  // prehodiť poradie argumentov
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
};

int main()
{
    Pole p(5); // správne zátvorky
    return 0;
}