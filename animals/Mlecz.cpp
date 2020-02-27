#include "Mlecz.h"

using namespace std;

Mlecz::Mlecz() {

}

Mlecz::Mlecz(int x, int y) {
	gatunek = "Mlecz";
	wyglad = 'M';
	this->x = x;
	this->y = y;

	sila = 0;
}

Mlecz::Mlecz(FILE* plik) : Rosliny(plik) {
	gatunek = "Mlecz";
	wyglad = 'M';
}


void Mlecz::akcja(Swiat* swiat, char ruchGracza)
{
	if (this->GetZyje() == true) {
		ZwiekszWiek();
		for (int i = 0; i < 3; i++) {
			this->Rozpyl(swiat);
		}
	}
}


