#include <cstdlib>
#include <iostream>
#include <string>
#include "balonik.h"
using namespace std;


int main() {
  int wybor;
  float s, h, p;
  balonik *wybrany_balonik = nullptr;

  do {
    cout << "\n\t\tMenu glowne:" << endl;
    cout << "\n\t1. Wybierz kolor balonika" << endl;
    cout << "\t2. Dodaj srednice balonika" << endl;
    cout << "\t3. Dodaj wysokosc balonika" << endl;
    cout << "\t4. Wyswietl stan balonika" << endl;
    cout << "\t5. Pompuj balonik" << endl;
    cout << "\t6. Wyjdz" << endl;
    cout << "\n\t\tTwoj wybor: ";
    cin >> wybor;

    switch (wybor) {
    case 1:
      int kolor;
      cout << "\n\t1. Balonik czerwony" << endl;
      cout << "\t2. Balonik zielony" << endl;
      cout << "\t3. Balonik niebieski" << endl;
      cout << "\n\t\tTwoj wybor: ";
      cin >> kolor;
      switch (kolor) {
      case 1:
        wybrany_balonik = new balonik(0, 0, "czerwony");
        break;
      case 2:
        wybrany_balonik = new balonik(0, 0, "zielony");
        break;
      case 3:
        wybrany_balonik = new balonik(0, 0, "niebieski");
        break;
      default:
        cout << "\n\tNiepoprawny wybor. Sprobuj jeszcze raz." << endl;
        break;
      }
      break;
    case 2:
      if (wybrany_balonik != nullptr) {
        cout << "\n\tPodaj srednice balonika w cm: ";
        cin >> s;
        while (s < 0) {
            cout << "\n\tNiepoprawna wartosc srednicy. Podaj wartosc wieksza od zera: ";
            cin >> s;
        }
        wybrany_balonik->dodaj_srednice(s);
      } else {
        cout << "\n\tNie wybrales jeszcze balonika. Wybierz balonik przed dodaniem srednicy."
             << endl;
      }
      break;
    case 3:
      if (wybrany_balonik != nullptr) {
        cout << "\n\tPodaj wysokosc balonika w metrach: ";
        cin >> h;
        while (h < 0) {
            cout << "\n\tNiepoprawna wartosc wysokosci. Podaj wartosc wieksza od zera: ";
            cin >> h;
        }
        wybrany_balonik->dodaj_wysokosc(h);
      } else {
        cout << "\n\tNie wybrales jeszcze balonika. Wybierz balonik przed dodaniem wysokosci." << endl;
      }
      break;
    case 4:
      if (wybrany_balonik != nullptr) {
        wybrany_balonik->wyswietl_balonik();
      } else {
        cout << "\n\tNie wybrales jeszcze balonika. Wybierz balonik przed wyswietleniem stanu." << endl;
      }
      break;
    case 5:
     if (wybrany_balonik != nullptr) {
        cout << "\n\tIle dm3 powietrza chcesz dodac do balonika: ";
        cin >> p;
       while (p < 0) {
            cout << "\n\tNiepoprawna wartosc powietrza. Podaj wartosc wieksza od zera: ";
            cin >> p;
        }
        pompuj(*wybrany_balonik, p);
      } else {
        cout << "\n\tNie wybrales jeszcze balonika. Wybierz balonik przed dodaniem powietrza." << endl;
      }
      break;
    case 6:
      cout << "\n\t\tKoniec programu." << endl;
      break;
    default:
      cout << "\n\tNiepoprawny wybor. Sprobuj jeszcze raz." << endl;
    }
  } while (wybor != 6);

  if (wybrany_balonik != nullptr) {
    delete wybrany_balonik;
  }

  cout << endl; return 0;
}