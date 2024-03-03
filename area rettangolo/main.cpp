/*
Scrivere un programma che dati in ingresso la base e l'altezza visualizzi a video
sulla stessa riga i valori inseriti e l'Area del Rettangolo.
*/

#include <iostream>

using namespace std;

int base,altezza,area;
int main()
{
    //dichiarazione delle variabili
    cout<<"inserire il valore della base: ";
    cin>>base;
    cout<<"inserire il valore dell'altezza: ";
    cin<<altezza;

    area=base*altezza;

    cout<<"il valore dell'area e': "<<area;
    return 0;
}
