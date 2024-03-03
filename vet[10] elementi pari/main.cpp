/*
Scrivere un programma che riempito un vettore di 10 elementi, visualizzi a video gli elementi di posizione pari.
*/
#include <iostream>

using namespace std;

int main()
{
    int vett[10],i,r;

    for(i=1;i<=10;i++)
    {
        cout<<"inseire il valore dell'elemento "<<i<<" del vettore"<<endl;
        cin>>vett[i];
    }

    for(i=1;i<=10;i++)
    {
        r=vett[i]%2;

        if(r!=1)
        {
            cout<<vett[i]<<endl;
        }

    }

    return 0;
}
