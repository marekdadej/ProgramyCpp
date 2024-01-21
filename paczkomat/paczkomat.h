#ifndef PACZKOMAT_H
#define PACZKOMAT_H

class Skrzynka {
private:
    float wysokosc;
    float szerokosc;
    bool czy_pelna;

public:
    Skrzynka(float wys, float szer);
    bool wlozPaczke(float wys, float szer);
    bool czyPelnaSkrzynka();
};

class Paczkomat {
private:
    static const int liczbaSkrzynek = 12;
    Skrzynka* skrzynki[liczbaSkrzynek];

public:
    Paczkomat();
    ~Paczkomat();
    void wlozPaczke(int ID_skrzynki, float wys, float szer);
    void wyswietlStanSkrzynek();
};

#endif  
