#pragma once 
#include <iostream>
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
        Bot(int rozmiar, char znak);
        ~Bot();
        char getZnak() const;
        void wykonajRuch(int& wiersz, int& kolumna) const;

};