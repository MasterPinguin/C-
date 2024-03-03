/*
Scrivere un programma che dopo aver caricato un vettore di N componenti, con N<= 10, calcoli il prodotto delle componenti di posto pari e la somma di quelle dispari.
*/

#include <iostream>

using namespace std;

int main()
{
    int vett[10],i,r,p,s;

    for(i=1;i<=10;i++)
    {
        cout<<"inseire il valore dell'elemento "<<i<<" del vettore"<<endl;
        cin>>vett[i];
    }

    p=1;
    s=0;

    for(i=1;i<=10;i++)
    {
        r=vett[i]%2;

        if(r!=1)
        {
            p=p*vett[i];
        }
        else
        {
            s=s+vett[i];
        }

    }

    cout<<"il prodotto tra i numeri pari : "<<p<<endl;

    cout<<"la somma tra i numeri dispari : "<<s<<endl;

    return 0;
}
