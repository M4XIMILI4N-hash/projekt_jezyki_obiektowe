#include <iostream>
#include <cstdlib>
#include "bot.h"

using namespace std; 



Bot::Bot(int rozmiar, char znak){

    if(znak == 'X'){
        znak = 'O';
    }else{
        znak = 'X';
    }
}




