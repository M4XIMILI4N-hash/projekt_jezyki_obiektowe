#include <iostream>
#include "human.h"

using namespace std;

Human::Human() : nazwa("Gracz"), znak('X') {}

Human::Human(const string& nazwa, char znak) : nazwa(nazwa), znak(znak) {}

string Human::getNazwa() const {
    return nazwa;
}

void Human::setNazwa(const string& nowaNazwa) {
    nazwa = nowaNazwa;
}

char Human::getZnak() const {
    return znak;
}

void Human::setZnak(char nowyZnak) {
    znak = nowyZnak;
}

void Human::wykonajRuch(Board& plansza) const {
    int w, k;
    cout << nazwa << " (" << znak << "), podaj wspolrzedne w formacie 'Wiersz Kolumna' (np. 1 1):" << endl;
    cin >> w >> k;

    while (!plansza.postaw_znak(w, k, znak)) {
        cout << "Pole jest zajete lub poza zakresem! Sprobuj jeszcze raz:" << endl;
        cin >> w >> k;
    }
}