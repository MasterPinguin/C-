/*
Realizzare un programma in C++ che permetta di visualizzare il seguente menù utilizzando i vettori:

MENU
1)  Caricamento del vettore (utilizzando la funzione random)
2)  Ordinamento del vettore
3)  Stampa del vettore
4)  Ricerca di un elemento del vettore
5)  Somma degli elementi del vettore
6)  Esci
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int scelta, vett[10], som=0, N=10, i, j, y, n = 101, x=0;
    bool ce = false;


    do
    {
    cout<<" "<<endl;
    cout<<"MENU "<<endl;
    cout<<"1)  Caricamento del vettore (utilizzando la funzione random) "<<endl;
    cout<<"2)  Ordinamento del vettore "<<endl;
    cout<<"3)  Stampa del vettore "<<endl;
    cout<<"4)  Ricerca di un elemento del vettore"<<endl;
    cout<<"5)  Somma degli elementi del vettore "<<endl;
    cout<<"6)  Esci"<<endl;

    cout<<"Inserisci scelta [1-6]:"<<endl;
    cin>>scelta;

    switch (scelta)
        {
        case 1:

            srand(time(NULL));

            for(i=0 ; i<=10 ; i++)
            {
            	vett[i]=(rand()%100)+1;

            }
            break;

        case 2:
            N=10;

            for(j=0 ; j<=N ; j++)
             {
                for(i=N-1; i>=j ; i--)
                {
                    if(vett[i]>vett[i+1])
                    {
                        y=vett[i];
                        vett[i]=vett[i+1];
                        vett[i+1]=y;
                    }

                }
            }


            break;

        case 3:

            for(i=0 ; i<=10 ; i++)
            {
            	cout<<vett[i]<<", ";

            }
            break;

        case 4:

            n=101;
            while(n>100)
            {
                n=0;
                cout<<"inserisci l'elemento da ricercare nel vettore: ";
                cin>>n;
            }

            for(int i=0; i<=10; i++)
            {
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

            break;

        case 5:

            for(i=0 ; i<=10 ; i++)
            {
            	som=som+vett[i];
            }
            cout<<"La somma e' di:"<<som<<endl;
            som=0;
            break;

        case 6:

            break;

        default:

            cout<<"Attenzione scelta errata!!!"<<endl;
        }

    }
    while(scelta!=6);


    return 0;
}
