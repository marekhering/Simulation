#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
protected:

	void Rusz(Swiat* swiat, int ruch, int zasieg);
	bool SprawdzPole(Swiat* swiat, int ruch, int zasieg);
	void Rozmnoz(Swiat* swiat, Organizm* DrugiRodzic);


public:

	Zwierze();
	Zwierze(FILE* file);

	void akcja(Swiat* swiat, char ruchGracza) override;
	bool kolizja(Swiat* swiat, Organizm* Obr) override;
	bool czyOdbilAtak(Organizm* atk) override;
	bool Ucieczka(Swiat* swiat) override;
	virtual void ZapiszOrganizmy(FILE* plik) override;

};