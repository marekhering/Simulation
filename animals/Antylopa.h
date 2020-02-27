#pragma once
#include "Zwierze.h"


class Antylopa : public Zwierze
{
private:


public:
	Antylopa();
	Antylopa(FILE* plik);
	Antylopa(int x, int y);

	void akcja(Swiat* swiat, char ruch) override;
	bool Ucieczka(Swiat* swiat) override;

};
