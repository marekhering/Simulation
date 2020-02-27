#pragma once
#include "Zwierze.h"


class Zolw : public Zwierze
{
private:


public:
	Zolw();
	Zolw(FILE* plik);
	Zolw(int x, int y);

	void akcja(Swiat* swiat, char ruch) override;
	bool czyOdbilAtak(Organizm* atk) override;
}; 
