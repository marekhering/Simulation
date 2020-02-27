#pragma once
#include "Rosliny.h"


class BarszczSosnowskiego : public Rosliny
{
private:


public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(FILE* plik);
	BarszczSosnowskiego(int x, int y);

	bool kolizja(Swiat* swiat, Organizm* Obr) override;
	void akcja(Swiat* swiat, char ruchGracza) override;

};