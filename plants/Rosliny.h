#pragma once
#include "Organizm.h"

class Rosliny : public Organizm
{
protected:

	void Rozpyl(Swiat* swiat);

private:

	int szansaNaRozpylenie;


public:

	Rosliny();
	Rosliny(FILE *plik);

	void akcja(Swiat* swiat, char ruchGracza) override;
	bool kolizja(Swiat* swiat, Organizm* Obr) override;
	bool czyOdbilAtak(Organizm* atk) override;
	bool Ucieczka(Swiat* swiat) override;
	virtual void ZapiszOrganizmy(FILE* file) override;

	int Get_SzansaNaRozpylenie();

};