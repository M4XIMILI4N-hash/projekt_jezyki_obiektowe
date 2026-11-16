#include "board.h"
using namespace std;

#include "board.h"

using namespace std;

Board::Board(int wymiar) {
    if (wymiar != MALA && wymiar != SREDNIA && wymiar != DUZA) {
        throw invalid_argument("Bledny wymiar");
    }


    aktualny_rozmiar = static_cast<rozmiar>(wymiar);

    siatka = new char*[aktualny_rozmiar];
    for (int i = 0; i < aktualny_rozmiar; i++) {
        siatka[i] = new char[aktualny_rozmiar];
        for (int j = 0; j < aktualny_rozmiar; j++) {
            siatka[i][j] = ' ';
        }
    }
}


Board::~Board() {
    for (int i = 0; i < aktualny_rozmiar; i++) {
        delete[] siatka[i];
    }
    delete[] siatka;
}

ostream& operator<<(ostream& os, const Board& b) {
    for (int i = 0; i < b.aktualny_rozmiar; i++) {
        for (int j = 0; j < b.aktualny_rozmiar; j++) {
            os << " " << b.siatka[i][j] << " ";
            if (j < b.aktualny_rozmiar - 1) {
                os << "|"; 
            }
        }
        os << "\n";

        if (i < b.aktualny_rozmiar - 1) {
            for (int j = 0; j < b.aktualny_rozmiar; j++) {
                os << "---";
                if (j < b.aktualny_rozmiar - 1) os << "+";
            }
            os << "\n";
        }
    }
    return os;
}