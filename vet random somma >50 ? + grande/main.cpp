/*
Dopo aver riempito un vettore di 10 elementi utilizzando la funzione random con
numeri interi compresi tra 0 e 100, copiare i valori inferiori a 50 in un vettore
e quelli superiori in un altro vettore. Visualizzare entrambi i vettori. Poi fare la
somma degli elementi del primo vettore risultante e la somma degli elementi del secondo
vettore risultante e dire quale somma è maggiore.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int vett[10], piu50[10], meno50[10], somma1=0, somma2=0, j=0, y=0;
    srand(time(NULL));

    for(int i=0; i<=10; i++)
    {
        vett[i]=(rand()%100)+1;

        if(vett[i]>=50)
        {
            piu50[j]=vett[i];
            j++;
            somma1=somma1+piu50[j];
        }
        else
        {
            meno50[y]=vett[i];
            y++;
            somma2=somma2+meno50[y];
        }
    }


    for(int i=0; i<j; i++)
    {
        cout<<piu50[i]<<", ";
    }

    cout<<" "<<endl;

    for(int i=0; i<y; i++)
    {
        cout<<meno50[i]<<", ";
    }

    cout<<" "<<endl;

    if(somma1>somma2)
    {
        cout<<"la somma dei numeri maggiori di 50 e' la piu grande"<<endl;
    }
    if(somma1<somma2)
    {
        cout<<"la somma dei numeri minore di 50 e' la piu grande"<<endl;
    }
    if(somma1==somma2)
    {
        cout<<"le due somme sono uguali"<<endl;
    }

    return 0;
}
