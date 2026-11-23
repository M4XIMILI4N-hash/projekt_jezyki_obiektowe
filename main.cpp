#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include "board.h"
#include "bot.h"
#include "human.h"

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
    srand(static_cast<unsigned int>(time(nullptr)));

    char tryb;
    int rozmiar, zaczyna, ruchy = 0;
    char znak;
    string imie1, imie2;

start:
    czyszczenieTerminal();
    cout << "Aby rozpoczac gre z botem wpisz: b" << endl;
    cout << "Aby rozpoczac gre z czlowiekiem wpisz: c" << endl;
    cout << "Aby wyjsc z programu wpisz cokolwiek innego" << endl;
    cin >> tryb;

    if (tryb == 'b') {
        cout << "Podaj swoja nazwe:" << endl;
        cin >> imie1;
        cout << "Podaj rozmiar planszy (3,4,5) oraz swoj znak 'X', 'O':" << endl;
        cin >> rozmiar >> znak;

        if (znak == 'x') znak = 'X';
        if (znak == 'o') znak = 'O';

        int max_r = rozmiar * rozmiar;
        Board plansza(rozmiar);
        Human gracz1(imie1, znak);
        Bot robot(znak);

        cout << "Losowanie rozpoczynajacego..." << endl;
        this_thread::sleep_for(700ms);

        zaczyna = rand() % 2;

        if (zaczyna == 0) {
            cout << "Zaczynasz jako pierwszy, " << gracz1.getNazwa() << "!" << endl;
        } else {
            cout << "Gre zaczyna bot!" << endl;
        }

        this_thread::sleep_for(700ms);
        czyszczenieTerminal();
        cout << plansza << endl;

        while (true) {
            if (zaczyna == 0) {
                gracz1.wykonajRuch(plansza);
                ruchy++;
                czyszczenieTerminal();
                cout << plansza << endl;

                if (plansza.koniec(gracz1.getZnak())) {
                    cout << "Gratulacje " << gracz1.getNazwa() << ", zwyciestwo!" << endl;
                    break;
                } else if (ruchy == max_r) {
                    cout << "Remis!" << endl;
                    break;
                } else {
                    zaczyna = 1;
                }
            } else {
                robot.wykonajRuch(plansza, rozmiar);
                ruchy++;
                czyszczenieTerminal();
                cout << plansza << endl;

                if (plansza.koniec(robot.getZnak())) {
                    cout << "Porazka :C" << endl;
                    break;
                } else if (ruchy == max_r) {
                    cout << "Remis!" << endl;
                    break;
                } else {
                    zaczyna = 0;
                }
            }
        }
    } else if (tryb == 'c') {
        cout << "Podaj rozmiar planszy (3,4,5):" << endl;
        cin >> rozmiar;
        cout << "Podaj nazwe Gracza 1 oraz jego znak 'X', 'O':" << endl;
        cin >> imie1 >> znak;

        if (znak == 'x') znak = 'X';
        if (znak == 'o') znak = 'O';
        char znak2 = (znak == 'X') ? 'O' : 'X';

        cout << "Podaj nazwe Gracza 2 (otrzyma znak '" << znak2 << "'):" << endl;
        cin >> imie2;

        int max_r = rozmiar * rozmiar;
        Board plansza(rozmiar);
        Human gracz1(imie1, znak);
        Human gracz2;
        gracz2.setNazwa(imie2);
        gracz2.setZnak(znak2);

        cout << "Losowanie rozpoczynajacego..." << endl;
        this_thread::sleep_for(700ms);

        zaczyna = rand() % 2;

        if (zaczyna == 0) {
            cout << "Gre zaczyna " << gracz1.getNazwa() << "!" << endl;
        } else {
            cout << "Gre zaczyna " << gracz2.getNazwa() << "!" << endl;
        }

        this_thread::sleep_for(700ms);
        czyszczenieTerminal();
        cout << plansza << endl;

        while (true) {
            if (zaczyna == 0) {
                gracz1.wykonajRuch(plansza);
                ruchy++;
                czyszczenieTerminal();
                cout << plansza << endl;

                if (plansza.koniec(gracz1.getZnak())) {
                    cout << "Gratulacje " << gracz1.getNazwa() << ", zwyciestwo!" << endl;
                    break;
                } else if (ruchy == max_r) {
                    cout << "Remis!" << endl;
                    break;
                } else {
                    zaczyna = 1;
                }
            } else {
                gracz2.wykonajRuch(plansza);
                ruchy++;
                czyszczenieTerminal();
                cout << plansza << endl;

                if (plansza.koniec(gracz2.getZnak())) {
                    cout << "Gratulacje " << gracz2.getNazwa() << ", zwyciestwo!" << endl;
                    break;
                } else if (ruchy == max_r) {
                    cout << "Remis!" << endl;
                    break;
                } else {
                    zaczyna = 0;
                }
            }
        }
    } else {
        return 0;
    }

    ruchy = 0;

    cout << "Czy chcesz rozpoczac kolejna rozgrywke? y/n" << endl;
    char pytanie;
    cin >> pytanie;

    if (pytanie == 'y' || pytanie == 'Y') {
        goto start;
    } else {
        return 0;
    }
}

