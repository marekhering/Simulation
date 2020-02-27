#include "Owca.h"

Owca::Owca() {

}

Owca::Owca(FILE* plik) : Zwierze(plik) {
	gatunek = "Owca";
	wyglad = 'O';
}


Owca::Owca(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Owca";
	wyglad = 'O';

	sila = 4;
	inicjatywa = 4;
}




