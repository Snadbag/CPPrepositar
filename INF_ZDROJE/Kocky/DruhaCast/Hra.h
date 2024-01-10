#pragma once
#include "Hrac.h"
#include <vector>

class Hra
{
private:
	std::vector<Hrac> hraci;

public:
	Hra();
	~Hra();

	void dajHracomKocky();
	void hraj();
};