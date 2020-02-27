#include "Swiat.h"
#include "Narrator.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Wilk.h"
#include "Owca.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "Zolw.h"
#include "Lis.h"
#include "Czlowiek.h"
#include "Antylopa.h"

Swiat::Swiat()
{
	srand(time(NULL));

	UsunKursor();
	if (Menu() == true) {
	StworzCzlowieka();
	StartoweOrganizmy();
	}
}


void Swiat::Graj() {

	if (Blad == false) {

		char ruch = ' ';

		do{		
			system("cls");

			if (ruch != 'o' && ruch != 'z') {
				wykonajTure(ruch);
				UsunMartweOrganizmy();
			}
			rysujSwiat();
			ruch = ZrobRuch();

			if (ruch == 'o')WczytajGre();
			if (ruch == 'z')ZapiszGre();

		} while (ruch != 'q');

		if (ruch == 'q') {
			system("cls");
			cout << "Do zobaczenia"<<endl;
			system("PAUSE");
		}
	}
	else {

		cout << endl << endl << "Za maly rozmiar planszy (min.10)" << endl;
		Sleep(1000);

	}

}

void Swiat::StartoweOrganizmy() {
	Wilk wilk;
	Owca owca;
	Lis lis;
	Zolw zolw;
	Antylopa antylopa;
	Trawa trawa;
	Mlecz mlecz;
	Guarana guarana;
	WilczeJagody wilczejagody;
	BarszczSosnowskiego barszczsosnowskiego;


	int Pozycja_X;
	int Pozycja_Y;

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&wilk, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&wilk, Pozycja_X, Pozycja_Y);

	
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&owca, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&owca, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&owca, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&lis, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&lis, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&lis, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&zolw, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&zolw, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&zolw, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&antylopa, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&antylopa, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&antylopa, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&trawa, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&trawa, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&trawa, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&mlecz, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&mlecz, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&guarana, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&guarana, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&wilczejagody, Pozycja_X, Pozycja_Y);
	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&wilczejagody, Pozycja_X, Pozycja_Y);

	LosujPole(Pozycja_X, Pozycja_Y); StworzOrganizm(&barszczsosnowskiego, Pozycja_X, Pozycja_Y);


}

void Swiat::UsunKursor() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccur;
	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	ccur.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &ccur);
}

void Swiat::StworzOrganizm(Organizm* org, int x, int y) {

	if (dynamic_cast<Trawa*>(org) != nullptr) {
		org = new Trawa(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Mlecz*>(org) != nullptr) {
		org = new Mlecz(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Wilk*>(org) != nullptr) {
		org = new Wilk(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Owca*>(org) != nullptr) {
		org = new Owca(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<WilczeJagody*>(org) != nullptr) {
		org = new WilczeJagody(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Guarana*>(org) != nullptr) {
		org = new Guarana(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<BarszczSosnowskiego*>(org) != nullptr) {
		org = new BarszczSosnowskiego(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Zolw*>(org) != nullptr) {
		org = new Zolw(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Lis*>(org) != nullptr) {
		org = new Lis(x, y);
		organizmy.push_back(org);
	}
	else if (dynamic_cast<Antylopa*>(org) != nullptr) {
		org = new Antylopa(x, y);
		organizmy.push_back(org);
	}
}


void Swiat::StworzCzlowieka() {
	Organizm* org = new Czlowiek(rozmiar_X/2,rozmiar_Y/2);	
	organizmy.push_back(org);
}


void Swiat::rysujSwiat()
{
	gotoxy(0,0);
	for (int i = 0; i <= rozmiar_Y + 1; i++) {
		for (int j = 0; j <= rozmiar_X + 1; j++) {		
			if (i == 0 || j == 0 || j == rozmiar_X + 1 || i == rozmiar_Y + 1)
			{
				cout << char(219);
			}
			else cout << " " ;

		}
		cout << endl;
	}

	for (int i = 0; i < organizmy.size(); i++)
	{
		organizmy[i]->rysowanie(this);
	}

	Legenda();

}

void Swiat::wykonajTure(char ruch)
{
	gotoxy(0, GetRozmiar_Y() + 3);

	int max = NajwyzszaInicjatywa();
	do {
		for (int i = 0; i < organizmy.size(); i++)
		{
			if(organizmy[i]->GetInicjatywa() == max)organizmy[i]->akcja(this,ruch);
		}
		max--;
	} while (max >= 0);
}

int Swiat::ZrobRuch() {
	int ruch = _getch();

	if (ruch == 224) {
		ruch = _getch();
		return ruch;
	}
	return ruch;
}

void Swiat::Legenda() {

	gotoxy(rozmiar_X + 9, 3);
	cout << "Legenda: ";
	gotoxy(rozmiar_X + 8, 5);
	cout << "Strzalki:	Poruszanie sie";
	gotoxy(rozmiar_X + 8, 6);
	cout << "ENTER:	Specjalna Umiejetnosc";
	gotoxy(rozmiar_X + 8, 7);
	cout << "Z:		Zapis";
	gotoxy(rozmiar_X + 8, 8);
	cout << "O:		Odczyt";
	gotoxy(rozmiar_X + 8, 9);
	cout << "Q:		Wyjscie";
}


bool Swiat::Menu() {

	int Szerokosc, Wysokosc;
	string Powitanie = "Witaj w symulatorze Wirtualnego Swiata";
	string PodajSzerokosc = "Podaj szerokosc twojej planszy (min. 10) : ";
	string PodajWysokosc = "Podaj wysokosc twojej planszy (min. 10) : ";

	gotoxy(8, 4);
	for (int i = 0; i < Powitanie.size(); i++) {
		cout << Powitanie[i];
		Sleep(30);    
	}

	gotoxy(6, 6);
	for (int i = 0; i < PodajSzerokosc.size(); i++) {
		cout << PodajSzerokosc[i];
		Sleep(20);      
	}
	cin >> Szerokosc;

	gotoxy(6, 8);
	for (int i = 0; i < PodajWysokosc.size(); i++) {
		cout << PodajWysokosc[i];
		Sleep(20);
	}
	cin >> Wysokosc;


	for (int i = 0; i < 10; i++) {
		gotoxy(10, 10);
		if (i % 3 == 0)cout << "Tworzenie.  ";
		if (i % 3 == 1)cout << "Tworzenie.. ";
		if (i % 3 == 2)cout << "Tworzenie...";
		Sleep(100);    
	}

	if (Szerokosc >= 10 && Wysokosc >= 10)
	{
		this->SetRozmiar_X(Szerokosc);
		this->SetRozmiar_Y(Wysokosc);

	}
	else
	{
		Blad = true;
		return false;
	}

	return true;

}

void Swiat::LosujPole(int& x, int& y) {
	Organizm* org = NULL;
	do {
		x = 1 + rand() % this->GetRozmiar_X();
		y = 1 + rand() % this->GetRozmiar_Y();
	} while (org->czyPuste(this, x, y, 1) == false);
}

void Swiat::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

int Swiat::NajwyzszaInicjatywa() {
	int max = 0;
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->GetInicjatywa() > max)max = organizmy[i]->GetInicjatywa();
	}
	return max;
}

void Swiat::UsunMartweOrganizmy() {
	int ilosc = this->GetIloscOrganizmow();
	for (int i = ilosc - 1; i >= 0; i--) {
		if (this->GetOrganizm(i)->GetZyje() == false) {
			UsunOrganizm(this->GetOrganizm(i));
			organizmy.erase(organizmy.begin() + i);
		}
	}
}

void Swiat::ZapiszGre() {
	string nazwa;
	system("CLS");
	gotoxy(1, 1);
	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> nazwa;
	nazwa += ".txt";

	FILE* plik = fopen(&nazwa[0], "wb");
	if (plik != NULL && nazwa.size() > 0)
	{
		fwrite(&rozmiar_X, sizeof(int), 1, plik);
		fwrite(&rozmiar_Y, sizeof(int), 1, plik);

		for (int i = 0; i < organizmy.size(); i++) {
			GetOrganizm(i)->ZapiszOrganizmy(plik);
		}


		fclose(plik);
	}
	else {
		cout << endl << "  Nie mozna utworzyc pliku" << endl;
		Sleep(2000);
	}
}


void Swiat::WczytajGre() {
	string nazwa;
	Organizm* org = NULL;
	system("CLS");
	gotoxy(1, 1);
	cout << "Podaj nazwe pliku do wczytania: ";
	cin >> nazwa;
	nazwa += ".txt";

	FILE* plik = fopen(&nazwa[0], "rb");
	if (plik != NULL)
	{
		WyczyscSwiat();
		fread(&rozmiar_X, sizeof(int), 1, plik);
		fread(&rozmiar_Y, sizeof(int), 1, plik);
		WczytajOrganizmy(plik);

		fclose(plik);
	}
	else {
		cout << endl <<"  Nie ma takiego pliku" << endl;
		Sleep(2000);
	}
	
}

void Swiat::WyczyscSwiat() {
	int ilosc = this->GetIloscOrganizmow();
	for (int i = ilosc - 1; i >= 0; i--) {
		UsunOrganizm(this->GetOrganizm(i));
		organizmy.erase(organizmy.begin() + i);
	}
	organizmy.clear();
}

void Swiat::WczytajOrganizmy(FILE* plik) {
	char gat;
	Organizm *org;

	while (!feof(plik)) {
		org = NULL;
		fread(&gat, sizeof(char), 1, plik);
		if (feof(plik))return;

		if (gat == 'T') org = new Trawa(plik);
		else if (gat == 'M') org = new Mlecz(plik);
		else if (gat == 'G') org = new Guarana(plik);
		else if (gat == 'J') org = new WilczeJagody(plik);
		else if (gat == 'B') org = new BarszczSosnowskiego(plik);
		else if (gat == 'O') org = new Owca(plik);
		else if (gat == 'W') org = new Wilk(plik);
		else if (gat == 'L') org = new Lis(plik);
		else if (gat == 'Z') org = new Zolw(plik);
		else if (gat == 'A') org = new Antylopa(plik);
		else if (gat == 'C') org = new Czlowiek(plik);

		

		if (org != NULL)organizmy.push_back(org);

	}
}

void Swiat::UsunOrganizm(Organizm *org) { 
	delete org;
}

Narrator* Swiat::Relacjonuj() {
	return narrator;
}

int Swiat::GetIloscOrganizmow() {
	int a = organizmy.size();
	return a;
}


void Swiat::SetRozmiar_X(int x) {
	this->rozmiar_X = x;
}

void Swiat::SetRozmiar_Y(int y) {
	this->rozmiar_Y = y;
}

int Swiat::GetRozmiar_X() {
	return rozmiar_X;
}

int Swiat::GetRozmiar_Y() {
	return rozmiar_Y;
}

Organizm* Swiat::GetOrganizm(int i) {
	return organizmy[i];
}

Swiat::~Swiat() {
	
	WyczyscSwiat();

}