#include "Zwierze.h"
#include "Rosliny.h"
#include "Narrator.h"

Zwierze::Zwierze() {

}

Zwierze::Zwierze(FILE* plik) : Organizm(plik) {

}

void Zwierze::akcja(Swiat* swiat, char ruchGracza)
{

	if (this->GetZyje() == true) {
		ZwiekszWiek();

		int ruch = WylosujPustePole(swiat, this->x, this->y, 0, 1);
		if (SprawdzPole(swiat, ruch, 1) == true)Rusz(swiat, ruch, 1);

	}
}


void Zwierze::Rusz(Swiat* swiat, int ruch, int zasieg) {

	if (ruch == 0) {
		this->x -= zasieg;
		this->y -= zasieg;
	}
	else if (ruch == 1) {
		this->y -= zasieg;
	}
	else if (ruch == 2) {
		this->x += zasieg;
		this->y -= zasieg;
	}
	else if (ruch == 3) {
		this->x += zasieg;
	}
	else if (ruch == 4) {
		this->x += zasieg;
		this->y += zasieg;
	}
	else if (ruch == 5) {
		this->y += zasieg;
	}
	else if (ruch == 6) {
		this->x -= zasieg;
		this->y += zasieg;
	}
	else if (ruch == 7) {
		this->x -= zasieg;
	}
}



bool Zwierze::SprawdzPole(Swiat* swiat, int ruch, int zasieg) {

	Organizm* Obr = NULL;

	if (ruch == 0) {
		if (czyPuste(swiat, x - zasieg, y - zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x - zasieg, y - zasieg);
		}
	}
	else if (ruch == 1) {
		if (czyPuste(swiat, x, y - zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x , y - zasieg);
		}
	}
	else if (ruch == 2) {
		if (czyPuste(swiat, x + zasieg, y - zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x + zasieg, y - zasieg);
		}
	}
	else if (ruch == 3) {
		if (czyPuste(swiat, x + zasieg, y ,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x + zasieg, y);
		}
	}
	else if (ruch == 4) {
		if (czyPuste(swiat, x + zasieg, y + zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x + zasieg, y + zasieg);
		}
	}
	else if (ruch == 5) {
		if (czyPuste(swiat, x, y + zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x, y + zasieg);
		}
	}
	else if (ruch == 6) {
		if(czyPuste(swiat, x - zasieg, y + zasieg,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x - zasieg, y + zasieg);
		}
	}
	else if (ruch == 7) {
		if(czyPuste(swiat, x - zasieg, y,1)) return true;
		else
		{
			Obr = ZnajdzOrganizm(swiat, x - zasieg, y);
		}
	}

	if (Obr != NULL) {
		return kolizja(swiat, Obr);
	}
	else return true;

}

bool Zwierze::czyOdbilAtak(Organizm* atk) {
	return false;
}

bool Zwierze::Ucieczka(Swiat* swiat) {
	return false;
}

void Zwierze::Rozmnoz(Swiat* swiat, Organizm* DrugiRodzic) {
	if (DrugiRodzic->GetWiek() > 5 && this->GetWiek() > 5) {
		int pozycja = WylosujPustePole(swiat, this->x, this->y, 1, 1);
		this->StworzOrganizmNaPozycji(swiat, this, this->x, this->y, pozycja);
	}
}

void Zwierze::ZapiszOrganizmy(FILE* plik) {
	Organizm::ZapiszOrganizmy(plik);
}


bool Zwierze::kolizja(Swiat* swiat, Organizm* Obr) { 

	if (Obr->GetZyje() == true) {

		if (Obr->GetGatunek() == this->GetGatunek()) {
			Rozmnoz(swiat, Obr);
			swiat->Relacjonuj()->Relacjonuj_Rozmnozenie(this, Obr);
			return false;
		}
		else {
			if (dynamic_cast<Zwierze*>(Obr) != nullptr)
			{
				if (Obr->czyOdbilAtak(this) == false) {
					if (Obr->Ucieczka(swiat) == false) {
						if (this->Ucieczka(swiat) == false) {
							if (Obr->GetSila() > this->GetSila()) {
								swiat->Relacjonuj()->Relacjonuj_Starcie(Obr, this);
								this->Zgin(swiat);
							}
							else {
								swiat->Relacjonuj()->Relacjonuj_Starcie(this, Obr);
								Obr->Zgin(swiat);
							}
						}
						else {
							swiat->Relacjonuj()->Relacjonuj_Unik(this, Obr);
						}
					}
					else {
						swiat->Relacjonuj()->Relacjonuj_Unik(Obr, this);
					}
				}
				else {
					return false;
				}
			}
			else if (dynamic_cast<Rosliny*>(Obr) != nullptr)
			{
				swiat->Relacjonuj()->Relacjonuj_Jedzenie(Obr, this);
				Obr->kolizja(swiat, this);
				Obr->Zgin(swiat);
			}
		}
	}
	return true;

}