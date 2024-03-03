/*
Dato un vettore di 6 elementi visualizzare il valore massimo e tutti gli elementi del vettore.
*/

#include <iostream>

using namespace std;

int main()
{
    int vett[5], x;

        for(int i=0;i<=5;i++)
    {
        cout<<"inserisci il valore "<<i<<" del vettore:"<<endl;
        cin>>vett[i];
    }

    cout<<" "<<endl;

    for(int i=0;i<=5;i++)
    {
        cout<<"elemento "<<i<<" del vettore: "<<vett[i]<<endl;
    }

    x=vett[0];

    for(int i=0;i<=5;i++)
    {
        if(vett[i]>x)
        {
            x=vett[i];
        }
    }
    cout<<"l'elemento maggiore del vettore  : "<<x;

    return 0;
}
