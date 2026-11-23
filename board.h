#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Board{

    private: 

        enum rozmiar
        {
            MALA = 3,
            SREDNIA = 4,
            DUZA = 5
        };

        rozmiar aktualny_rozmiar;

        char** siatka;

    public:

        Board(int wymiar);

        ~Board();

        friend ostream& operator<<(ostream& os, const Board& b);

        void cofnij_ruch(int w, int k);
        
        bool czy_wolne(int w, int k) const;

        bool postaw_znak(int w, int k, char znak);

        bool koniec(char znak);

};