#pragma once
#include <string>
#include "board.h"

using namespace std;

class Human {
private:
    std::string nazwa;
    char znak;

public:
    Human();
    Human(const string& nazwa, char znak);

    string getNazwa() const;
    void setNazwa(const string& nowaNazwa);

    char getZnak() const;
    void setZnak(char nowyZnak);

    void wykonajRuch(Board& plansza) const;
};