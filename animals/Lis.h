#pragma once
#include "Zwierze.h"


class Lis : public Zwierze
{
private:

	bool DobryWech(Swiat* swiat, int ruch);

public:
	Lis();
	Lis(FILE* plik);
	Lis(int x, int y);

	void akcja(Swiat* swiat, char ruchGracza) override;

};
