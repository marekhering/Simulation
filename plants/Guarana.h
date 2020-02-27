#pragma once
#include "Rosliny.h"


class Guarana : public Rosliny
{
private:


public:
	Guarana();
	Guarana(FILE* plik);
	Guarana(int x, int y);

	bool kolizja(Swiat* swiat, Organizm* Obr) override;
};