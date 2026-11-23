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
    int rozmiar, zaczyna, w, k, ruchy = 0; 
    char znak;

    cout << "Aby rozpoczac gre z botem wpisz: y" << endl;
    cin >> start; 
    
    if (start == "y"){
        cout << "Podaj rozmiar planszy (3,4,5) oraz swoj znak 'X', 'O'" << endl;
        cin >> rozmiar >> znak;
    };

    int max_r = rozmiar*rozmiar;

    Board plansza(rozmiar);

    Bot robot(znak);

    cout << "Losowanie rozpoczynajacego..."; 

    zaczyna = rand()%2;

    if ((zaczyna) == 0){
        cout << "Zaczynasz jako pierwszy!";
        zaczyna = 0;
    }else{
        cout << "Gre zaczyna bot!" << endl;
        zaczyna = 1;
    }

    while(true){

        if (zaczyna == 0){

            cout << "Podaj wspolrzedne swojego ruchu w formacie 'Wiersz Kolumna -> np. 2 2'" << endl;
            cin >> w >> k;
            plansza.postaw_znak(w,k,znak);
            ruchy++;
            czyszczenieTerminal();
            cout << plansza;

            if (plansza.koniec(znak) == true){

                cout << "Gratulacje, zwyciestwo!";
                break;

            }else if(ruchy == max_r){

                cout << "Remis!" << endl;
                break;

            }else{
                zaczyna = zaczyna + 1;
            }
            

        }else if(zaczyna == 1){

            czyszczenieTerminal();
            robot.wykonajRuch(plansza, rozmiar);
            ruchy++;
            cout << plansza << endl;

            if (plansza.koniec(robot.getZnak()) == true){

                cout << "porazka :C" << endl;
                break;

            }else if(ruchy == max_r){
                cout << "Remis!" << endl;
                break;

            }else{
                zaczyna = zaczyna - 1; 
            }
        }
    }

    ruchy = 0;

    return 0;
}