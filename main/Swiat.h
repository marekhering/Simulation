#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <string>


using namespace std;

class Organizm;
class Narrator;


class Swiat
{
private:

	bool Blad = false;

	int rozmiar_X ;
	int rozmiar_Y ;

	vector <Organizm *> organizmy;
	Narrator* narrator;

	void Legenda();
	void WczytajGre();
	void ZapiszGre();
	void UsunKursor();
	void StartoweOrganizmy();
	void StworzCzlowieka();
	bool Menu();
	void LosujPole(int& x, int& y);
	void wykonajTure(char ruch);
	void WyczyscSwiat();

	void WczytajOrganizmy(FILE* plik);
	int NajwyzszaInicjatywa();

	int ZrobRuch();


public:

	Swiat();

	void SetRozmiar_X(int x);
	void SetRozmiar_Y(int y);
	int GetRozmiar_X();
	int GetRozmiar_Y();

	int GetIloscOrganizmow();

	Organizm* GetOrganizm(int i);
	Narrator* Relacjonuj();

	void rysujSwiat();
	void Graj();
	void StworzOrganizm(Organizm* org, int x, int y);
	void UsunMartweOrganizmy();
	void UsunOrganizm(Organizm* org);
	
	void gotoxy(int x, int y);

	~Swiat();
};
