/*
Dopo aver caricato in memoria un array di numeri interi con 20 componenti, contare le componenti che hanno valore superiore a 5.
*/

#include <iostream>

using namespace std;

int main()
{
    int vett[20],i,n;

    for(i=1;i<=20;i++)
    {
        cout<<"inseire il valore dell'elemento "<<i<<" del vettore"<<endl;
        cin>>vett[i];
    }

    n=0;

    for(i=1;i<=20;i++)
    {

        if(vett[i]<5)
        {
            n++;
        }

    }

    cout<<"i numeri contenuti nell array superiori a 5 sono: "<<n<<endl;

    return 0;
}
