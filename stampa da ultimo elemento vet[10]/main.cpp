/*
Continuo esercizio 1. Visualizzare a video gli elementi del vettore partendo dall’ultima posizione.
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

    for(i=10;i>=1;i=i-1)
    {
        cout<<vett[i]<<endl;
    }

    return 0;
}
