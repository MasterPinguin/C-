/*
Scrivere un programma che riempia un vettore di 10 elementi di tipo int. Alla fine, visualizzare a video i dati memorizzati nel vettore.
*/
#include <iostream>

using namespace std;

int main()
{
    int vett[10],i;

    for(i=1;i<=10;i++)
    {
        cout<<"inseire il valore dell'elemento "<<i<<" del vettore"<<endl;
        cin>>vett[i];
    }

    for(i=1;i<=10;i++)
    {
        cout<<vett[i]<<endl;
    }

    return 0;
}
