/*
Calcola i vettori somma e differenza di due vettori di N componenti con N <= 10.
*/

#include <iostream>

using namespace std;

int main()
{
    int vett[9], vett2[9], dif, som, x, y;

    x=0;
    y=0;
        for(int i=0;i<=9;i++)
    {
        cout<<"inserisci il valore "<<i<<" del vettore:"<<endl;
        cin>>vett[i];
        x=x+vett[i];
    }

        for(int i=0;i<=9;i++)
    {
        cout<<"inserisci il valore "<<i<<" del vettore:"<<endl;
        cin>>vett2[i];
        y=y+vett2[i];
    }

    som=x+y;
    dif=x-y;

    cout<<"la somma dei 2 vettori e' di: "<<som<<endl;
    cout<<"la differenza dei 2 vettori e' di: "<<dif<<endl;

    return 0;
}

