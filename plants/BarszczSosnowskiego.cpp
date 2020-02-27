#include "BarszczSosnowskiego.h"
#include "Zwierze.h"


BarszczSosnowskiego::BarszczSosnowskiego() {

}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) {
	gatunek = "BarszczSosnowskiego";
	wyglad = 'B';

	sila = 10;

	this->x = x;
	this->y = y;
}

BarszczSosnowskiego::BarszczSosnowskiego(FILE* plik) : Rosliny(plik) {
	gatunek = "BarszczSosnowskiego";
	wyglad = 'B';
}



bool BarszczSosnowskiego::kolizja(Swiat* swiat, Organizm* org) {
	org->Zgin(swiat);
	return true;
}

void BarszczSosnowskiego::akcja(Swiat* swiat, char ruchGracza) {

	if (this->GetZyje() == true) {
		ZwiekszWiek();
		Rozpyl(swiat);
		ZabijWszystkichDookola(swiat, 1);
	}
}

