#pragma once

#include "Swiat.h"

class Organizm {

protected:

	string gatunek;
	char wyglad;
	int sila;
	int inicjatywa;
	int x;
	int y;
	bool zyje;
	int delay;
	int czastwrania;
	int wiek;

	int WylosujPustePole(Swiat* swiat, int x, int y, bool bezKolizji, int zasieg);
	void StworzOrganizmNaPozycji(Swiat* swiat, Organizm* org, int x, int y, int pozycja);
	
	bool czySciana(Swiat* swiat, int x, int y);
	Organizm* ZnajdzOrganizm(Swiat* swiat, int x, int y);
	void ZabijWszystkichDookola(Swiat* swiat, bool TylkoRosliny);
	void ZnajdzPuste(Swiat* swiat, bool tab[8], int x, int y, bool bezKolizji, int zasieg);
	
public:

	Organizm();
	Organizm(FILE *plik);

	virtual void akcja(Swiat* swiat,char ruchGracza) = 0;
    virtual bool kolizja(Swiat* swiat, Organizm* Obr) = 0;
	virtual bool czyOdbilAtak(Organizm* atk) = 0;
	virtual bool Ucieczka(Swiat* swiat) = 0;
	virtual void ZapiszOrganizmy(FILE* plik);
	bool czyPuste(Swiat *swiat, int x, int y, bool bezKolizji);

	void rysowanie(Swiat* swiat);
	void ToString();
	string GetGatunek();

	void Zgin(Swiat* swiat);
	bool GetZyje();

	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

	void ZwiekszWiek();
	void ZwiekszSile(int x);

	int GetWiek();
	int GetSila();
	int GetInicjatywa();


	~Organizm();
};