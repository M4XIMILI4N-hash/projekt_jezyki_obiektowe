#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include "board.h"
#include "bot.h"

using namespace std;
using namespace std::chrono_literals;

void czyszczenieTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main() {
    string start;
    int rozmiar, zaczyna, w, k, ruchy = 0;
    char znak;

start:
    cout << "Aby rozpoczac gre z botem wpisz: y" << endl;
    cin >> start;

    if (start == "y") {
        cout << "Podaj rozmiar planszy (3,4,5) oraz swoj znak 'X', 'O'" << endl;
        cin >> rozmiar >> znak;
    } else {
        return 0;
    }

    int max_r = rozmiar * rozmiar;

    Board plansza(rozmiar);

    Bot robot(znak);

    cout << "Losowanie rozpoczynajacego..." << endl;

    this_thread::sleep_for(700ms);

    zaczyna = rand() % 2;

    if ((zaczyna) == 0) {
        cout << "Zaczynasz jako pierwszy!" << endl;
        zaczyna = 0;
    } else {
        cout << "Gre zaczyna bot!" << endl;
        zaczyna = 1;
    }

    this_thread::sleep_for(700ms);

    while (true) {
        if (zaczyna == 0) {
            cout << "Podaj wspolrzedne swojego ruchu w formacie 'Wiersz Kolumna -> np. 2 2'" << endl;
            cin >> w >> k;

            if (plansza.postaw_znak(w, k, znak)) {
                ruchy++;
                czyszczenieTerminal();
                cout << plansza << endl;

                if (plansza.koniec(znak)) {
                    cout << "Gratulacje, zwyciestwo!" << endl;
                    break;
                } else if (ruchy == max_r) {
                    cout << "Remis!" << endl;
                    break;
                } else {
                    zaczyna = 1;
                }
            } else {
                cout << "Pole jest zajete lub poza zakresem! Sprobuj jeszcze raz." << endl;
            }
        } else if (zaczyna == 1) {
            czyszczenieTerminal();
            robot.wykonajRuch(plansza, rozmiar);
            ruchy++;
            cout << plansza << endl;

            if (plansza.koniec(robot.getZnak()) == true) {
                cout << "porazka :C" << endl;
                break;
            } else if (ruchy == max_r) {
                cout << "Remis!" << endl;
                break;
            } else {
                zaczyna = zaczyna - 1;
            }
        }
    }

    ruchy = 0;

    cout << "Czy chcesz rozpoczac kolejna rozgrywke? y/n" << endl;

    char pytanie;

    cin >> pytanie;

    if (pytanie == 'y') {
        goto start;
    } else {
        return 0;
    }
}