#include "Narrator.h"

Narrator::Narrator(Swiat* swiat) {

}

void Narrator::Relacjonuj_Unik(Organizm *Obronca, Organizm *Atakujacy) {
	Obronca->ToString();
	cout << "uniknal starcia z ";
	Atakujacy->ToString();
	cout << endl;
}

void Narrator::Relacjonuj_Rozmnozenie(Organizm *Rodzic1, Organizm *Rodzic2) {
	Rodzic1->ToString();
	cout << "i ";
	Rodzic2->ToString();
	cout << "rozmnozyly sie";
	cout << endl;
}

void Narrator::Relacjonuj_Jedzenie(Organizm *Zjadany, Organizm *Jedzacy) {
	Zjadany->ToString();
	cout << "zostal zjedzony przez ";
	Jedzacy->ToString();
	cout << endl;
}

void Narrator::Relacjonuj_Smierc(Organizm *Ofiara){
	Ofiara->ToString();
	cout << "zginal!";
	cout << endl;
}

void Narrator::Relacjonuj_Starcie(Organizm *Wygrany, Organizm * Przegrany) {
	Przegrany->ToString();
	cout << "zostal zabity przez ";
	Wygrany->ToString();
	cout << endl;

}

void Narrator::Relacjonuj_UmiejetnoscAktywna(int Czastrwania) {
	cout << "Umiejetnosc czlowieka aktywna jeszcze przez "<<Czastrwania<<" tur"<< endl;
}

void Narrator::Relacjonuj_Delay(int delay) {
	cout << "Umiejetnosc czlowieka odnowi sie za "<< delay<<" tur" << endl;
}