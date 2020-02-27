#include "Zolw.h"

Zolw::Zolw() {

}

Zolw::Zolw(FILE* plik) : Zwierze(plik) {
	gatunek = "Zolw";
	wyglad = 'Z';
}

Zolw::Zolw(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Zolw";
	wyglad = 'Z';

	sila = 2;
	inicjatywa = 1;
}



void Zolw::akcja(Swiat* swiat, char ruch)
{
	if (this->GetZyje() == true) {
		ZwiekszWiek();

		int los = rand() % 4;

		if (los == 0) {
			int ruch = this->WylosujPustePole(swiat, this->x, this->y, 0, 1);
			if (this->SprawdzPole(swiat, ruch, 1) == true)Rusz(swiat, ruch, 1);

		}
	}
}

bool Zolw::czyOdbilAtak(Organizm* atk) {

	if(atk->GetSila()<5)return true;
	else return false;
}

