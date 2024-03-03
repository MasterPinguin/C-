/*
Dato un vettore di 15 elementi, inserire un numero da tastiera e controllare se
esiste nel vettore. In caso affermativo, contare quante volte compare all’interno
del vettore e visualizzare a video la risposta e l’eventuale numero di volte che compare.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int vett[15], n = 101, x=0;
    bool ce = false;
    srand(time(NULL));

    while(n>100)
    {
        n=0;
        cout<<"inserisci l'elemento da ricercare nel vettore: ";
        cin>>n;
    }

    for(int i=0; i<=15; i++)
    {
        vett[i]=(rand()%100)+1;

        if (vett[i]==n)
        {
            ce = true;
            x++;
        }
    }



    cout<<" "<<endl;

    if(ce == true)
    {
        cout<<"Nel vettore e' persente il numero "<<n<<", "<<x<<" volte "<<endl;
    }
    else
    {
        cout<<"Nel vettore non e' presente l'elemento "<<n<<endl;
    }

    return 0;
}

