/*
Scrivere un programma che calcoli l'area del triangolo
*/

#include <iostream>

using namespace std;

float area,base,altezza;
int main()
{
    cout<<"inserire il valore della base";
    cin>>base;
    cout<<"inserire il valore dell'altezza";
    cin>>altezza;

    area=(base*altezza)/2;

    cout<<"l'area e': "<<area;
    return 0;
}
