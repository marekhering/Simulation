#include "Rosliny.h"

#define SZANSANAROZPYLENIE 5


Rosliny::Rosliny()
{
	inicjatywa = 0;
	sila = 0;
	szansaNaRozpylenie = SZANSANAROZPYLENIE;
}

Rosliny::Rosliny(FILE* plik) : Organizm(plik)
{
	szansaNaRozpylenie = SZANSANAROZPYLENIE;
}


void Rosliny::akcja(Swiat* swiat, char ruchGracza)
{
	if (this->GetZyje() == true) {
		ZwiekszWiek();
		Rozpyl(swiat);
	}
}

void Rosliny::Rozpyl(Swiat* swiat) {

	int rozmnazanie = 1 + rand() % 100;

	if (rozmnazanie <= szansaNaRozpylenie && this->GetWiek() > 1) {
		int pozycja = WylosujPustePole(swiat, this->x, this->y, 1, 1);

		this->StworzOrganizmNaPozycji(swiat, this, this->x, this->y, pozycja);

	}

}

bool Rosliny::czyOdbilAtak(Organizm* atk) {
	return false;
}

bool Rosliny::Ucieczka(Swiat* swiat) {
	return false;
}

bool Rosliny::kolizja(Swiat* swiat, Organizm* Obr) {

	return true;
}


int Rosliny::Get_SzansaNaRozpylenie() {
	return szansaNaRozpylenie;
}

void Rosliny::ZapiszOrganizmy(FILE* plik) {
	Organizm::ZapiszOrganizmy(plik);
}