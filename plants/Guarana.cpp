#include "Guarana.h"


Guarana::Guarana() {

}

Guarana::Guarana(int x, int y) {
	gatunek = "Guarana";
	wyglad = 'G';

	this->x = x;
	this->y = y;
}

Guarana::Guarana(FILE* plik) : Rosliny(plik) {
	gatunek = "Guarana";
	wyglad = 'G';
}


bool Guarana::kolizja(Swiat* swiat, Organizm* org) {

	org->ZwiekszSile(3);

	return true;
}

