#pragma once
#include "Hrac.h"
#include "Balicek.h"
#include <vector>

class Hra
{
private:
	std::vector<Hrac> hraci;

public:
	Hra();
	~Hra();

	void dajHracomKarty();
	void hraj();
};