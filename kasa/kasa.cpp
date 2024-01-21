#include <cstdlib>
#include <iostream>
using namespace std;

class Kasa {
private:
  bool otwarta;
  int banknoty[5];
  int monety[3];
  int monety_gr[6];

public:
  Kasa() {
    otwarta = false;
    for (int i = 0; i < 5; i++) {
      banknoty[i] = 0;
    }
    for (int i = 0; i < 3; i++) {
      monety[i] = 0;
    }
    for (int i = 0; i < 6; i++) {
      monety_gr[i] = 0;
    }
  }

  void otworz() {
      otwarta = true;
       cout << "\n\tKasa zostala otwarta!" << endl;
  }

  void zamknij() {
    otwarta = false;
    cout << "\n\tKasa zostala zamknieta!" << endl;
  }

  void wyswietl_stan_kasy() {
    if (!otwarta) {
      cout << "\n\tStan kasy wynosi: Kasa jest zamknieta - otworz kase!"
           << endl;
      return;
    }

    int suma1 = 0;

    suma1 += banknoty[0] * 200;
    suma1 += banknoty[1] * 100;
    suma1 += banknoty[2] * 50;
    suma1 += banknoty[3] * 20;
    suma1 += banknoty[4] * 10;
    suma1 += monety[0] * 5;
    suma1 += monety[1] * 2;
    suma1 += monety[2] * 1;

    float suma_gr = 0 / 100;

    suma_gr += monety_gr[0] * 50;
    suma_gr += monety_gr[1] * 20;
    suma_gr += monety_gr[2] * 10;
    suma_gr += monety_gr[3] * 5;
    suma_gr += monety_gr[4] * 2;
    suma_gr += monety_gr[5] * 1;

    float suma = suma1 + (suma_gr / 100);

    cout << "\n\tStan kasy wynosi: " << suma << " zł " << endl;
  }

  void wyswietl_zawartosc() {
    if (!otwarta) {
      cout << "\n\tW kasie znajduje sie: Kasa jest zamknieta - otworz kase!"
           << endl;
      return;
    }
    cout << "\n\tW kasie znajduje sie:" << endl;
    cout << "\n  - banknoty:";
    cout << " " << banknoty[0] << " po 200 zl,";
    cout << " " << banknoty[1] << " po 100 zl,";
    cout << " " << banknoty[2] << " po 50 zl,";
    cout << " " << banknoty[3] << " po 20 zl,";
    cout << " " << banknoty[4] << " po 10 zl" << endl;
    cout << "  - monety zl:";
    cout << " " << monety[0] << " po 5 zl,";
    cout << " " << monety[1] << " po 2 zl,";
    cout << " " << monety[2] << " po 1 zl" << endl;
    cout << "  - monety gr:";
    cout << " " << monety_gr[0] << " po 50 gr,";
    cout << " " << monety_gr[1] << " po 20 gr,";
    cout << " " << monety_gr[2] << " po 10 gr,";
    cout << " " << monety_gr[3] << " po 5 gr,";
    cout << " " << monety_gr[4] << " po 2 gr,";
    cout << " " << monety_gr[5] << " po 1 gr" << endl;
  }

  void dodaj_banknoty(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    int index = -1;
    switch (nominal) {
    case 200:
      index = 0;
      cout << "\n\tIlosc banknotow 200 zlotych: ";
      cin >> ilosc;
      break;
    case 100:
      index = 1;
      cout << "\n\tIlosc banknotow 100 zlotych: ";
    cin >> ilosc;
      break;
    case 50:
      index = 2;
      cout << "\n\tIlosc banknotow 50 zlotych: ";
    cin >> ilosc;
      break;
    case 20:
      index = 3;
      cout << "\n\tIlosc banknotow 20 zlotych: ";
    cin >> ilosc;
      break;
    case 10:
      index = 4;
      cout << "\n\tIlosc banknotow 10 zlotych: ";
    cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }
    banknoty[index] += ilosc;
    return;
  }

  void dodaj_monety(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }
    int index = -1;
    switch (nominal) {
    case 5:
      index = 0;
       cout << "\n\tIlosc monet 5 zlotych: ";
      cin >> ilosc;
      break;
    case 2:
      index = 1;
       cout << "\n\tIlosc monet 2 zlotych: ";
      cin >> ilosc;
      break;
    case 1:
      index = 2;
       cout << "\n\tIlosc monet 1 zlotych: ";
      cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    monety[index] += ilosc;
    return;
  }

  void dodaj_monety_gr(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }
    int index = -1;
    switch (nominal) {
    case 50:
      index = 0;
      cout << "\n\tIlosc monet 50 groszy: ";
      cin >> ilosc;
      break;
    case 20:
      index = 1;
      cout << "\n\tIlosc monet 20 groszy: ";
      cin >> ilosc;
      break;
    case 10:
      index = 2;
      cout << "\n\tIlosc monet 10 groszy: ";
      cin >> ilosc;
      break;
    case 5:
      index = 3;
      cout << "\n\tIlosc monet 5 groszy: ";
      cin >> ilosc;
      break;
    case 2:
      index = 4;
      cout << "\n\tIlosc monet 2 groszy: ";
      cin >> ilosc;
      break;
    case 1:
      index = 5;
      cout << "\n\tIlosc monet 1 groszy: ";
      cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    monety_gr[index] += ilosc;
    return;
  }

  void usun_banknoty(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }
    int index = -1;
    switch (nominal) {
   case 200:
      index = 0;
      cout << "\n\tIlosc banknotow 200 zlotych: ";
      cin >> ilosc;
      break;
    case 100:
      index = 1;
      cout << "\n\tIlosc banknotow 100 zlotych: ";
    cin >> ilosc;
      break;
    case 50:
      index = 2;
      cout << "\n\tIlosc banknotow 50 zlotych: ";
    cin >> ilosc;
      break;
    case 20:
      index = 3;
      cout << "\n\tIlosc banknotow 20 zlotych: ";
    cin >> ilosc;
      break;
    case 10:
      index = 4;
      cout << "\n\tIlosc banknotow 10 zlotych: ";
    cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    if (banknoty[index] < ilosc) {
      cout << "\n\tBrak wystarczajacej ilosci banknotow o nominale " << nominal
           << " zl" << endl;
      return;
    }
    banknoty[index] -= ilosc;
    return;
  }

  void usun_monety(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }
    int index = -1;
    switch (nominal) {
    case 5:
      index = 0;
       cout << "\n\tIlosc monet 5 zlotych: ";
      cin >> ilosc;
      break;
    case 2:
      index = 1;
       cout << "\n\tIlosc monet 2 zlotych: ";
      cin >> ilosc;
      break;
    case 1:
      index = 2;
       cout << "\n\tIlosc monet 1 zlotych: ";
      cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    if (monety[index] < ilosc) {
      cout << "\n\tNie ma wystarczajacej ilosci monet w kasie!" << endl;
      return;
    }
    monety[index] -= ilosc;
    return;
  }

  void usun_monety_gr(int nominal, int ilosc) {
    if (!otwarta) {
      cout << "\n\tKasa jest zamknieta - otworz kase!" << endl;
      return;
    }
    if (ilosc < 0) {
      cout << "\n\tNiepoprawna ilosc!" << endl;
      return;
    }

    int index = -1;
    switch (nominal) {
    case 50:
      index = 0;
      cout << "\n\tIlosc monet 50 groszy: ";
      cin >> ilosc;
      break;
    case 20:
      index = 1;
      cout << "\n\tIlosc monet 20 groszy: ";
      cin >> ilosc;
      break;
    case 10:
      index = 2;
      cout << "\n\tIlosc monet 10 groszy: ";
      cin >> ilosc;
      break;
    case 5:
      index = 3;
      cout << "\n\tIlosc monet 5 groszy: ";
      cin >> ilosc;
      break;
    case 2:
      index = 4;
      cout << "\n\tIlosc monet 2 groszy: ";
      cin >> ilosc;
      break;
    case 1:
      index = 5;
      cout << "\n\tIlosc monet 1 groszy: ";
      cin >> ilosc;
      break;
    }
    if (index == -1) {
      return;
    }
    if (monety_gr[index] < ilosc) {
      cout << "\n\tNie ma wystarczajacej ilosci monet w kasie!" << endl;
      return;
    }
    monety_gr[index] -= ilosc;
    return;
  }
};

int main() {
  Kasa kasa;
  int wybor, ilosc;

  do {
    cout << "\n\t\tMenu glowne:" << endl;
    cout << "\n\t1. Otworz kase" << endl;
    cout << "\t2. Zamknij kase" << endl;
    cout << "\t3. Wyswietl zawartosc kasy" << endl;
    cout << "\t4. Dodaj banknoty" << endl;
    cout << "\t5. Dodaj monety zlotowe" << endl;
    cout << "\t6. Dodaj monety groszowe" << endl;
    cout << "\t7. Usun banknoty" << endl;
    cout << "\t8. Usun monety zlotowe" << endl;
    cout << "\t9. Usun monety groszowe" << endl;
    cout << "\t10. Podlicz stan kasy" << endl;
    cout << "\t11. Wyjdz" << endl;
    cout << "\n\t\tTwoj wybor: ";
    cin >> wybor;

    switch (wybor) {
    case 1:
      kasa.otworz();
      break;
    case 2:
      kasa.zamknij();
      break;
    case 3:
      kasa.wyswietl_zawartosc();
      break;
    case 4:
    kasa.dodaj_banknoty(200, ilosc);
    kasa.dodaj_banknoty(100, ilosc);
    kasa.dodaj_banknoty(50, ilosc);
    kasa.dodaj_banknoty(20, ilosc);
    kasa.dodaj_banknoty(10, ilosc);
  break;
    case 5:
      kasa.dodaj_monety(5, ilosc);
      kasa.dodaj_monety(2, ilosc);
      kasa.dodaj_monety(1, ilosc);
      break;
    case 6:
      kasa.dodaj_monety_gr(50, ilosc);
      kasa.dodaj_monety_gr(20, ilosc);
      kasa.dodaj_monety_gr(10, ilosc);
      kasa.dodaj_monety_gr(5, ilosc);
      kasa.dodaj_monety_gr(2, ilosc);
      kasa.dodaj_monety_gr(1, ilosc);
      break;
    case 7:
      kasa.usun_banknoty(200, ilosc);
      kasa.usun_banknoty(100, ilosc);
      kasa.usun_banknoty(50, ilosc);
      kasa.usun_banknoty(20, ilosc);
      kasa.usun_banknoty(10, ilosc);
      break;
    case 8:
      kasa.usun_monety(5, ilosc);
      kasa.usun_monety(2, ilosc);
      kasa.usun_monety(1, ilosc);
      break;
    case 9:
      kasa.usun_monety_gr(50, ilosc);
      kasa.usun_monety_gr(20, ilosc);
      kasa.usun_monety_gr(10, ilosc);
      kasa.usun_monety_gr(5, ilosc);
      kasa.usun_monety_gr(2, ilosc);
      kasa.usun_monety_gr(1, ilosc);
      break;
    case 10:
      kasa.wyswietl_stan_kasy();
      break;
    case 11:
      cout << "\n\t\tKoniec programu." << endl;
      break;
    default:
      cout << "\n\tNiepoprawny wybor. Sprobuj jeszcze raz." << endl;
    }
  } while (wybor != 11);

  cout << endl;
  return 0;
}