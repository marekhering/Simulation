#include "Lis.h"

Lis::Lis() {

}

Lis::Lis(FILE* plik) : Zwierze(plik) {
	gatunek = "Lis";
	wyglad = 'L';
}

Lis::Lis(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Lis";
	wyglad = 'L';

	sila = 3;
	inicjatywa = 7;
}

void Lis::akcja(Swiat* swiat, char ruchGracza)
{

	if (this->GetZyje() == true) {
		ZwiekszWiek();

		int ruch = WylosujPustePole(swiat, this->x, this->y, 0, 1);
		if (DobryWech(swiat, ruch) == true) {
		
			if (SprawdzPole(swiat, ruch, 1) == true)Rusz(swiat, ruch, 1);

		}
	}
}


bool Lis::DobryWech(Swiat *swiat, int ruch) {

	Organizm* org = NULL;

	for (int i = 0; i < swiat->GetIloscOrganizmow(); i++) {

		if (ruch == 0)if (swiat->GetOrganizm(i)->GetX() == x - 1 && swiat->GetOrganizm(i)->GetY() == y - 1)org = swiat->GetOrganizm(i);
		if (ruch == 1)if (swiat->GetOrganizm(i)->GetX() == x && swiat->GetOrganizm(i)->GetY() == y - 1)org = swiat->GetOrganizm(i);
		if (ruch == 2)if (swiat->GetOrganizm(i)->GetX() == x + 1 && swiat->GetOrganizm(i)->GetY() == y - 1)org = swiat->GetOrganizm(i);
		if (ruch == 3)if (swiat->GetOrganizm(i)->GetX() == x + 1 && swiat->GetOrganizm(i)->GetY() == y)org = swiat->GetOrganizm(i);
		if (ruch == 4)if (swiat->GetOrganizm(i)->GetX() == x + 1 && swiat->GetOrganizm(i)->GetY() == y + 1)org = swiat->GetOrganizm(i);
		if (ruch == 5)if (swiat->GetOrganizm(i)->GetX() == x && swiat->GetOrganizm(i)->GetY() == y + 1)org = swiat->GetOrganizm(i);
		if (ruch == 6)if (swiat->GetOrganizm(i)->GetX() == x - 1 && swiat->GetOrganizm(i)->GetY() == y + 1)org = swiat->GetOrganizm(i);
		if (ruch == 7)if (swiat->GetOrganizm(i)->GetX() == x - 1 && swiat->GetOrganizm(i)->GetY() == y)org = swiat->GetOrganizm(i);
	}

	if (org != NULL) {

		if (org->GetSila() > this->sila && org->GetGatunek() != this->GetGatunek()) {
			return false;			
		}
		else return true;
	}
	return true;
}