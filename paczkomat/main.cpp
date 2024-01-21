#include <iostream>
#include "paczkomat.h"
using namespace std;

int main() {
  Paczkomat paczkomat;

  int wybor;
  int ID_skrzynki;
  float wysokosc, szerokosc;

  do {
    cout << "\n\t\t===== MENU =====" << endl;
    cout << "\n\t1. Włóż paczkę" << endl;
    cout << "\t2. Wyświetl stan skrzynek" << endl;
    cout << "\t3. Wyjście" << endl;
    cout << "\n\tWybierz opcję: ";
    cin >> wybor;

    switch (wybor) {
    case 1: {
      cout << "\n\tPodaj numer skrzynki (1 - 12): ";
      cin >> ID_skrzynki;
      if (ID_skrzynki < 1 || ID_skrzynki > 12) {
        cout << "\n\tNieprawidłowy numer skrzynki." << endl;
        break;
      }
      cout << "\n\tPodaj wymiary paczki (wysokość szerokość): ";
      cin >> wysokosc >> szerokosc;
      paczkomat.wlozPaczke(ID_skrzynki - 1, wysokosc, szerokosc);
      break;
    }
    case 2: {
      paczkomat.wyswietlStanSkrzynek();
      break;
    }
    case 3: {
      cout << "\n\t\tKoniec programu." << endl;
      break;
    }
    default: {
      cout << "\n\tNiepoprawny wybor. Sprobuj jeszcze raz." << endl;
    }
    }
  } while (wybor != 3);

  cout << endl;
  return 0;
}
