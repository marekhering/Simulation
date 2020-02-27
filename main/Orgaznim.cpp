#include "Organizm.h"
#include "Zwierze.h"
#include "Narrator.h"


Organizm::Organizm() {
	zyje = true;
	wiek = 0;
}

Organizm::Organizm(FILE *plik) {

	fread(&sila, sizeof(int), 1, plik);
	fread(&inicjatywa, sizeof(int), 1, plik);
	fread(&x, sizeof(int), 1, plik);
	fread(&y, sizeof(int), 1, plik);
	fread(&wiek, sizeof(int), 1, plik);


	zyje = true;
}



int Organizm::WylosujPustePole(Swiat* swiat, int x, int y, bool bezKolizji, int zasieg) {

	bool *tab = new bool[8];
	int pozycja = -1;
	int los;
	int ilePustych = 0;

	ZnajdzPuste(swiat, tab, this->x, this->y, bezKolizji, zasieg);

	for (int i = 0; i < 8; i++) ilePustych += tab[i];

	if (ilePustych > 0) {
		los = 1 + rand() % ilePustych;

		for (int i = 0, n = 1; i < 8; i++) {

			if (tab[i] == 1) {
				if (n == los) {
					pozycja = i;
					break;
				}
				n++;
			}
		}
	}

	delete tab;

	return pozycja;
	
}

void Organizm::ZnajdzPuste(Swiat* swiat, bool tab[8], int x, int y, bool bezKolizji, int zasieg) {
	
	for (int i = 0; i < 8; i++) tab[i] = 1;

	tab[0] = czyPuste(swiat, x - zasieg, y - zasieg, bezKolizji);
	tab[1] = czyPuste(swiat, x, y - zasieg, bezKolizji);
	tab[2] = czyPuste(swiat, x + zasieg, y - zasieg, bezKolizji);
	tab[3] = czyPuste(swiat, x + zasieg, y, bezKolizji);
	tab[4] = czyPuste(swiat, x + zasieg, y + zasieg, bezKolizji);
	tab[5] = czyPuste(swiat, x, y + zasieg, bezKolizji);
	tab[6] = czyPuste(swiat, x - zasieg, y + zasieg, bezKolizji);
	tab[7] = czyPuste(swiat, x - zasieg, y, bezKolizji);

}

void Organizm::StworzOrganizmNaPozycji(Swiat* swiat, Organizm* org, int x, int y, int pozycja) {

	if (pozycja != -1) {
		if (pozycja == 0)swiat->StworzOrganizm(org, x - 1, y - 1);
		else if (pozycja == 1)swiat->StworzOrganizm(org, x, y - 1);
		else if (pozycja == 2)swiat->StworzOrganizm(org, x + 1, y - 1);
		else if (pozycja == 3)swiat->StworzOrganizm(org, x + 1, y);
		else if (pozycja == 4)swiat->StworzOrganizm(org, x + 1, y + 1);
		else if (pozycja == 5)swiat->StworzOrganizm(org, x, y + 1);
		else if (pozycja == 6)swiat->StworzOrganizm(org, x - 1, y + 1);
		else if (pozycja == 7)swiat->StworzOrganizm(org, x - 1, y);

	}

}

bool Organizm::czySciana(Swiat* swiat, int x, int y) {

	if (x >= swiat->GetRozmiar_X() + 1 || y >= swiat->GetRozmiar_Y() + 1 || y <= 0 || x <= 0)return true;
	else return false;
}

void Organizm::ZabijWszystkichDookola(Swiat* swiat, bool TylkoRosliny) {
	for (int i = 0; i < swiat->GetIloscOrganizmow(); i++) {
		if (abs(swiat->GetOrganizm(i)->GetX() - this->GetX()) <= 1 && abs(swiat->GetOrganizm(i)->GetY() - this->GetY()) <= 1 && this!=swiat->GetOrganizm(i)) {
			if (TylkoRosliny == 1) {
				if (dynamic_cast<Zwierze*>(swiat->GetOrganizm(i)) != nullptr) {
					
					swiat->GetOrganizm(i)->Zgin(swiat);
				}
			}
			else {
				swiat->GetOrganizm(i)->Zgin(swiat);
			}
		}
	}

}


bool Organizm::czyPuste(Swiat* swiat, int x, int y, bool bezKolizji)
{
	if (czySciana(swiat, x, y) == true)return false;
	if (bezKolizji == true) {
		for (int i = 0; i < swiat->GetIloscOrganizmow(); i++)
		{
			if (swiat->GetOrganizm(i)->x == x && swiat->GetOrganizm(i)->y == y)return false;
		}
	}
	return true;
}

Organizm* Organizm::ZnajdzOrganizm(Swiat* swiat, int x, int y)
{
	Organizm* org;
	for (int i = 0; i < swiat->GetIloscOrganizmow(); i++) {
		if (swiat->GetOrganizm(i)->GetX() == x && swiat->GetOrganizm(i)->GetY() == y) {
			org = swiat->GetOrganizm(i);
			return org;
		}
	}
	return NULL;
}

void Organizm::ZapiszOrganizmy(FILE* plik) {

	fwrite(&wyglad, sizeof(char), 1, plik);
	fwrite(&sila, sizeof(int), 1, plik);
	fwrite(&inicjatywa, sizeof(int), 1, plik);
	fwrite(&x, sizeof(int), 1, plik);
	fwrite(&y, sizeof(int), 1, plik);
	fwrite(&wiek, sizeof(int), 1, plik);
}




void Organizm::rysowanie(Swiat* swiat)
{
	swiat->gotoxy(x, y);
	cout << this->wyglad;
}

void Organizm::ToString() {
	cout << gatunek << "(" << x << "," << y << ") ";
}

string Organizm::GetGatunek() {
	return gatunek;
}


void Organizm::Zgin(Swiat* swiat) {
	zyje = false;
	if (dynamic_cast<Zwierze*>(this) != nullptr) {
		swiat->Relacjonuj()->Relacjonuj_Smierc(this);
	}	
}


bool Organizm::GetZyje() {
	return zyje;
}

int Organizm::GetSila() {
	return sila;
}

void Organizm::ZwiekszSile(int x) {
	sila += x;
}

int Organizm::GetInicjatywa() {
	return inicjatywa;
}

void Organizm::SetX(int x) {
	this->x = x;
}

void Organizm::SetY(int y) {
	this->y = y;
}

int Organizm::GetX() {
	return x;
}

int Organizm::GetY() {
	return y;
}

void Organizm::ZwiekszWiek() {
	wiek++;
}

int Organizm::GetWiek() {
	return wiek;
}


Organizm::~Organizm() {

}