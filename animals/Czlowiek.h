#pragma once
#include "Zwierze.h"


class Czlowiek : public Zwierze
{
private:

	int delay;
	int czastrwania;

	void UzyjUmiejetnosci();

public:
	Czlowiek();
	Czlowiek(FILE* plik);
	Czlowiek(int x, int y);

	void akcja(Swiat* swiat, char ruchGracza) override;
	void Calopalenie(Swiat* swiat);
	void ZapiszOrganizmy(FILE* plik) override;

};
