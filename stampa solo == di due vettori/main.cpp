/*
Dopo aver riempito 2 vettori di N elementi, verifica se i due array sono uguali,
in altre parole se alla stessa posizione in entrambi gli array corrisponde
lo stesso contenuto. Restituisci la risposta.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int vett1[10], vett2[10], meno50[10];
    bool uguali;
    uguali = true;
    srand(time(NULL));

    for(int i=0; i<=10; i++)
    {
        vett1[i]=(rand()%100)+1;

        vett2[i]=(rand()%100)+1;

        if (vett1[i]!=vett2[i])
        {
            uguali=false;
        }
    }



    cout<<" "<<endl;

    if(uguali == false)
    {
        cout<<" NON SONO UGUALI "<<endl;
    }
    else
    {
        cout<<" SONO UGUALI "<<endl;
    }

    return 0;
}

