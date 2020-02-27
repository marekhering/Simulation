#include "Trawa.h"


Trawa::Trawa() {

}

Trawa::Trawa(FILE* plik) : Rosliny(plik) {
	gatunek = "Trawa";
	wyglad = 'T';
}

Trawa::Trawa(int x, int y) {
	gatunek = "Trawa";
	wyglad = 'T';
	this->x = x;
	this->y = y;

	sila = 0;
}


