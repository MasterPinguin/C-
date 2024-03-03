/*
Carica un vettore di N componenti, con N <= 10, poi memorizza le componenti in un nuovo
vettore nellÕordine inverso. Stampa il vettore cos“ ottenuto.
*/

#include <iostream>

using namespace std;

int main()
{
    int vett[9], vett2[9], x;

        for(int i=0;i<=9;i++)
    {
        cout<<"inserisci il valore "<<i<<" del vettore:"<<endl;
        cin>>vett[i];
    }

    x=0;

        for(int i=9;i>=0;i--)
    {
        vett2[x]=vett[i];
        x++;
    }

    cout<<" "<<endl;
    cout<<"primo vettore "<<endl;

    for(int i=0;i<=9;i++)
    {
        cout<<vett[i]<<"  ";
    }

    cout<<" "<<endl;
    cout<<"secondo vettore "<<endl;

    for(int i=0;i<=9;i++)
    {
        cout<<vett2[i]<<"  ";
    }
    return 0;
}
