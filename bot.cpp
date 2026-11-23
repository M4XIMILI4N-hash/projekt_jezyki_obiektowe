#include <iostream>
#include <cstdlib>
#include "bot.h"
#include "board.h"

using namespace std;

Bot::Bot(char znak) {
    if (znak == 'X') {
        znak_bota = O;
    } else {
        znak_bota = X;
    }
}

char Bot::getZnak() const {
    return static_cast<char>(znak_bota);
}

void Bot::wykonajRuch(Board& plansza,int rozmiar) const {
    int wiersz, kolumna;
    do {
        wiersz = rand() % rozmiar;
        kolumna = rand() % rozmiar;
    } while (!plansza.postaw_znak(wiersz, kolumna, getZnak()));
}




