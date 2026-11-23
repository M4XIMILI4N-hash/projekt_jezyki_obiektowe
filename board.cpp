#include <iostream>
#include <cstdlib>
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

bool Board::czy_wolne(int w, int k) const{
    if ((w < aktualny_rozmiar and k < aktualny_rozmiar) and (siatka[w][k] == ' ')){
        return true;
    }else{
        return false;
    }
}

bool Board::postaw_znak(int w, int k, char znak){
    if(czy_wolne(w,k)){
        siatka[w][k] = znak;
        return true; 
    }else{
        return false;
    }
}

bool Board::koniec(char znak){
    bool status = true;
    for(int w=0; w<aktualny_rozmiar; w++){    //wiersze 
        status = true;
        for(int k = 0; k<aktualny_rozmiar; k++){
            if(siatka[w][k] != znak){
                status = false;
                break;
            }
        }
        if (status == true){
            return status;
        }
    }

    for(int k = 0; k < aktualny_rozmiar; k++){ //kolumny 
        status = true;
        for(int w = 0; w < aktualny_rozmiar; w++){
            if(siatka[w][k] != znak){
                status = false;
                break;
            }
        }
        if (status == true){
            return status;
        }
    }

    status = true;
    for(int wk = 0; wk < aktualny_rozmiar; wk++){ //skos od lewego do prawego 
        if(siatka[wk][wk] != znak){
            status = false;
            break;
        }
    }
    if(status == true){
        return status;
    }

    status = true; 
    for(int wk = 0; wk < aktualny_rozmiar; wk++){ //skos prawy lewy 
        if(siatka[wk][aktualny_rozmiar-1-wk] != znak){
            status = false;
            break;
        }
    }

    return status;
}

void Board::cofnij_ruch(int w, int k) {
    if (w >= 0 && w < aktualny_rozmiar && k >= 0 && k < aktualny_rozmiar) {
        siatka[w][k] = ' ';
    }
}