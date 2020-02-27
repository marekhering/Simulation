#include "Antylopa.h"

Antylopa::Antylopa() {

}

Antylopa::Antylopa(FILE* plik) : Zwierze(plik) {
	gatunek = "Antylopa";
	wyglad = 'A';
}

Antylopa::Antylopa(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Antylopa";
	wyglad = 'A';

	sila = 4;
	inicjatywa = 4;
}

void Antylopa::akcja(Swiat* swiat, char ruch)
{
	if (this->GetZyje() == true) {
		ZwiekszWiek();
			int ruch = this->WylosujPustePole(swiat, this->x, this->y, 0, 2);
			if (this->SprawdzPole(swiat, ruch, 2) == true)Rusz(swiat, ruch, 2);

	}
}

bool Antylopa::Ucieczka(Swiat* swiat) {

	int los = rand() % 2;

	if(los == 1)return false;
	else {

		int ruch = this->WylosujPustePole(swiat, this->x, this->y, 0, 1);
		if (this->SprawdzPole(swiat, ruch, 1) == true)Rusz(swiat, ruch, 1);

	}

}

