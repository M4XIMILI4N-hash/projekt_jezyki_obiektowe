#pragma once 
#include <iostream>
#include "board.h"
#include <stdexcept>




class Bot{
    private: 
        int rozmiar_planszy;
        enum postac{
           X = 'X',
           O = 'O'
        };
        postac znak_bota;
    public: 
        Bot(char znak);
        ~Bot() = default;
        char getZnak() const;
        void wykonajRuch(Board& plansza,int rozmiar) const;
};
