#include <iostream>
#include "paczkomat.h"
using namespace std;

Skrzynka::Skrzynka(float wys, float szer) {
    wysokosc = wys;
    szerokosc = szer;
    czy_pelna = false;
}

bool Skrzynka::wlozPaczke(float wys, float szer) {
    if (czy_pelna) {
        cout << "\n\tSkrzynka jest już zajęta." << endl;
        return false;
    } else {
        if (wys <= wysokosc && szer <= szerokosc) {
            czy_pelna = true;
            cout << "\n\tPaczka została umieszczona w skrzynce." <<endl;
            return true;
        } else {
           cout << "\n\tPaczka jest za duża, nie zmieści się w skrzynce." << endl;
            return false;
        }
    }
}

bool Skrzynka::czyPelnaSkrzynka() {
    return czy_pelna;
}

Paczkomat::Paczkomat() {
    for (int i = 0; i < liczbaSkrzynek; i++) {
        if (i < 4) {
            skrzynki[i] = new Skrzynka(20.0f, 30.0f);  
        } else if (i < 8) {
            skrzynki[i] = new Skrzynka(30.0f, 40.0f);  
        } else {
            skrzynki[i] = new Skrzynka(40.0f, 50.0f); 
        }
    }
}

Paczkomat::~Paczkomat() {
    for (int i = 0; i < liczbaSkrzynek; i++) {
        delete skrzynki[i];
    }
}

void Paczkomat::wlozPaczke(int ID_skrzynki, float wys, float szer) {
    if (ID_skrzynki >= 0 && ID_skrzynki < liczbaSkrzynek) {
        if (skrzynki[ID_skrzynki]->wlozPaczke(wys, szer)) {
            cout << "\n\tOperacja zakończona sukcesem." << endl;
        } else {
            cout << "\n\tOperacja nieudana." << endl;
        }
    } else {
        cout << "\n\tNieprawidłowy numer skrzynki." << endl;
        return; 
    }
}


void Paczkomat::wyswietlStanSkrzynek() {
    for (int i = 0; i < liczbaSkrzynek; i++) {
        cout << "\n\tSkrzynka " << i + 1 << ": ";
        if (skrzynki[i]->czyPelnaSkrzynka()) {
            cout << "\tzajęta" << endl;
        } else {
            cout << "\twolna" << endl;
        }
    }
}
