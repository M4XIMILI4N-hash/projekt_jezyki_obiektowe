#include <iostream>
#include <cstdlib>
#include "board.h"
#include "bot.h"

using namespace std;

void czyszczenieTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main(){
    string start; 
    int rozmiar, zaczyna; 
    char znak;

    cout << "Aby rozpoczac gre z botem wpisz: y" << endl;
    cin >> start; 
    
    if (start == "y"){
        cout << "Podaj rozmiar planszy (3,4,5) oraz swoj znak 'X', 'O'" << endl;
        cin >> rozmiar >> znak;
    };

    Board plansza(rozmiar);

    cout << plansza << endl;

    cout << "Losowanie rozpoczynajacego..."; 

    if ((rand() % 2) == 0){
        cout << "Zaczynasz jako pierwszy!";
        zaczyna = 0;
    }else{
        cout << "Gre zaczyna bot!";
        zaczyna = 1;
    }

    while(true){




        

        
    }



    return 0;
}