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

void Bot::wykonajRuch(Board& plansza, int rozmiar) const {
    char mojZnak = getZnak();

    for (int w = 0; w < rozmiar; w++) {
        for (int k = 0; k < rozmiar; k++) {
            if (plansza.postaw_znak(w, k, mojZnak)) {
                if (plansza.koniec(mojZnak)) {
                    return;
                }
                plansza.cofnij_ruch(w, k);
            }
        }
    }

    int wiersz, kolumna;
    do {
        wiersz = rand() % rozmiar;
        kolumna = rand() % rozmiar;
    } while (!plansza.postaw_znak(wiersz, kolumna, mojZnak));
}




