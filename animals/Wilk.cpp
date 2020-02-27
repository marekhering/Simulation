#include "Wilk.h"

Wilk::Wilk() {

}

Wilk::Wilk(FILE* plik) : Zwierze(plik) {
	gatunek = "Wilk";
	wyglad = 'W';
}

Wilk::Wilk(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Wilk";
	wyglad = 'W';

	sila = 9;
	inicjatywa = 5;
}

