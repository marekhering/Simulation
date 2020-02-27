#pragma once
#include "Rosliny.h"


class Mlecz : public Rosliny
{
private:


public:
	Mlecz();
	Mlecz(FILE* plik);
	Mlecz(int x, int y);

	void akcja(Swiat* swiat, char ruchGracza) override;
}; 
