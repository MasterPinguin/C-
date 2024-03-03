/*
Il programma legge tre numeri e li mette in ordine crescente (usare gli operatori logici)
*/
#include <iostream>

using namespace std;

int vett[3];
int x;
int main()
{
    for (int i=0; i<3; i++)
    {
        cout << "inserisci un numero" << endl;
        cin>>vett[i];
    }
    for (int i=0; i<2; i++)
    {
        x=vett[0];

        if(vett[0]>vett[1])
        {
            vett[0]=vett[1];
            vett[1]=x;
        }
        x=vett[1];

        if(vett[1]>vett[2])
        {
            vett[1]=vett[2];
            vett[2]=x;
        }
    }

    return 0;
}
