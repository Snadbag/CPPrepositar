#include <cstdio>

class VynimkaA
{
public:
	virtual void Oznam() { printf("A\n"); } // pridanie virtual pred t�to met�du

};

class VynimkaB : public VynimkaA
{
public:
	void Oznam() { printf("B\n"); }

};

void Fun(int typ)
{
	switch (typ)
	{
	case 0:	throw VynimkaA(); break;
	case 1:	throw VynimkaB(); break;
	}

}

int main()
{
	for (int i = 0; i < 2; i++)
	{
		try
		{
			Fun(i);
		}
		catch (VynimkaA& ex)
		{
			ex.Oznam();
		}

	}
	return 0;
}