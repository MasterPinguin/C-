/*
Scrivere un programma che dati in ingresso il raggio calcoli l'area e il perimetro
del cerchio.
*/

#include <iostream>

using namespace std;

float raggio,perimetro,area,preferenza;
int main()
{
    cout<<"inserire il valore del raggio";
    cin>>raggio;
    cout<<"inserisci 1 se vuoi fare eseguire al programma prima l'are che il perimetro";
    cin>>preferenza;
    if(preferenza==1)
    {

    area=raggio^2*3,14;

    cout<<"l'area e': "<<area;

    perimetro=2*raggio*3,14;

    cout<<"il perimetro e': "<<perimetro;
    }
    else
    {

    perimetro=2*raggio*3,14;

    cout<<"il perimetro e': "<<perimetro;

     area=raggio^2*3,14;

    cout<<"l'area e': "<<area;
    }
    return 0;
}
