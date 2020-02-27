#include "WilczeJagody.h"


WilczeJagody::WilczeJagody() {

}

WilczeJagody::WilczeJagody(int x, int y) {
	gatunek = "WilczeJagody";
	wyglad = 'J';

	sila = 99;

	this->x = x;
	this->y = y;
}

WilczeJagody::WilczeJagody(FILE* plik) : Rosliny(plik) {
	gatunek = "WilczeJagody";
	wyglad = 'J';

}

bool WilczeJagody::kolizja(Swiat* swiat, Organizm* org) {

	org->Zgin(swiat);

	return true;
}

