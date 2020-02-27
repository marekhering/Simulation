#pragma once
#include "Swiat.h"
#include "Organizm.h"

class Narrator
{
public:

	Narrator(Swiat* swiat);

	void Relacjonuj_Starcie(Organizm *Wygrany, Organizm * Przegrany);
	void Relacjonuj_Unik(Organizm *Obronca,Organizm * Atakujacy);
	void Relacjonuj_Rozmnozenie(Organizm *Rodzic1, Organizm * Rodzic2);
	void Relacjonuj_Jedzenie(Organizm *Zjadany, Organizm *Jedzacy);
	void Relacjonuj_Smierc(Organizm *Ofiara);
	void Relacjonuj_UmiejetnoscAktywna(int Czastrwania);
	void Relacjonuj_Delay(int delay);

};