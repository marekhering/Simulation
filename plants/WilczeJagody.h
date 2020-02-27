#pragma once
#include "Rosliny.h"


class WilczeJagody : public Rosliny
{
private:


public:
	WilczeJagody();
	WilczeJagody(FILE* plik);
	WilczeJagody(int x, int y);

	bool kolizja(Swiat* swiat, Organizm* Obr) override;
};