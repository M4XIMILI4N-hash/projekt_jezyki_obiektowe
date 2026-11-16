#include <iostream>
#include "board.cpp"

using namespace std;

int main(){
    string start; 
    int rozmiar;

    cout << "Aby rozpocząć gre z botem wpisz: y";
    cin >> start; 
    
    if (start == "y"){
        cout << "Podaj rozmiar planszy (3,4,5)";
        cin >> rozmiar;
    };





    return 0;
}