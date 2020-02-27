#include "Czlowiek.h"
#include "Narrator.h"

#define Gora 72
#define Dol 80
#define Prawo 77
#define Lewo 75

#define Specjalka 13

Czlowiek::Czlowiek() {

}

Czlowiek::Czlowiek(FILE* plik) : Zwierze(plik) {
	gatunek = "Czlowiek";
	wyglad = 'C';

	fread(&czastrwania, sizeof(int), 1, plik);
	fread(&delay, sizeof(int), 1, plik);

	cout << czastrwania << " " << delay;

}

Czlowiek::Czlowiek(int x, int y) {
	this->x = x;
	this->y = y;

	gatunek = "Czlowiek";
	wyglad = 'C';

	sila = 5;
	inicjatywa = 4;
	delay = 0;
	czastrwania = 0;
}

void Czlowiek::akcja(Swiat* swiat, char ruchGracza)
{
	if (this->GetZyje() == true) {
		ZwiekszWiek();

		int ruch = -1;
		
		if (ruchGracza == Gora && czySciana(swiat, x, y - 1) == false) ruch = 1;
		if (ruchGracza == Prawo && czySciana(swiat, x + 1, y) == false) ruch = 3;
		if (ruchGracza == Dol && czySciana(swiat, x, y + 1) == false) ruch = 5;
		if (ruchGracza == Lewo && czySciana(swiat, x - 1, y) == false) ruch = 7;

		if (ruch != -1)if (SprawdzPole(swiat, ruch, 1) == true)Rusz(swiat, ruch, 1);

		if (ruchGracza == Specjalka)UzyjUmiejetnosci();

		Calopalenie(swiat);
	}

	

}

void Czlowiek::Calopalenie(Swiat* swiat) {

	if (czastrwania > 0) {
		swiat->Relacjonuj()->Relacjonuj_UmiejetnoscAktywna(czastrwania);
		ZabijWszystkichDookola(swiat, 0);
		czastrwania--;
	}
	else {
		if (delay > 0) {
			swiat->Relacjonuj()->Relacjonuj_Delay(delay);
			delay--;
		}
	}
}

void Czlowiek::UzyjUmiejetnosci() {

	if (delay == 0) {
		czastrwania = 5;
		delay = 5;
	}
	else {
		cout << "Jeszcze nope";
	}

}


void Czlowiek::ZapiszOrganizmy(FILE* plik) {

	Zwierze::ZapiszOrganizmy(plik);
	fwrite(&czastrwania, sizeof(int), 1, plik);
	fwrite(&delay, sizeof(int), 1, plik);

}