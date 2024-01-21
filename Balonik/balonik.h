#include <iostream>
#include <cstdlib>
using namespace std;

class balonik {
private:
  string kolor;
  float wysokosc;
  float srednica;

public:
  balonik(float sre, float wys, string nowy_kolor);
  float dodaj_srednice(float s);
  float dodaj_wysokosc(float h); 
  void wyswietl_balonik();
};

 void pompuj(balonik &balonik, float powierzchnia);
