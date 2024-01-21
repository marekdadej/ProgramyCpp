#include <iostream>
#include <cstdlib>
#include <math.h>
#include "balonik.h"
using namespace std;

balonik::balonik(float sre, float wys, string nowy_kolor) {
  kolor = nowy_kolor;
  srednica = sre;
  wysokosc = wys;
}

float balonik::dodaj_srednice(float s) {
  if (s < 0) {
    cout << "\n\tNiepoprawna wartosc srednicy. Sprobuj jeszcze raz." << endl;
    return srednica;
  }
  srednica += s;
  return srednica;
}

float balonik::dodaj_wysokosc(float h) {
  if (h < 0) {
    cout << "\n\tNiepoprawna wartosc srednicy. Sprobuj jeszcze raz." << endl;
    return wysokosc;
  } 
  wysokosc += h;
  return wysokosc;
}

void balonik::wyswietl_balonik() {
  cout << "\n\tTu balonik " << kolor << " - mam " << srednica
       << " cm srednicy i jestem na wysokosci " << wysokosc << " m" << endl;
}

void pompuj(balonik &balonik, float powierzchnia) {
    float srednica = sqrt(powierzchnia / 3.14) * 2;
     balonik.dodaj_srednice(srednica);
  cout << "\n\tDopompowano balonik." << endl;
  }