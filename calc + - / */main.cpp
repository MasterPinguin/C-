/*
Sviluppare un programma che simuli il funzionamento di una calcolatrice che fornisca
esclusivamente le 4 operazioni fondamentali (somma, sottrazione, moltiplicazione e
divisione).
1) Il programma dovrà permettere l’inserimento di due valori numerici a e b
2) Il programma dovrà permettere una scelta tra le quattro possibili operazioni (a+b oppure
a-b oppure…)
3) Il programma dovrà stampare il risultato finale
*/
#include <iostream>

using namespace std;

int main()
{
    int scelta;
    float a,b,r,ris;

    cout<<"MENU "<<endl;
    cout<<"1-SOMMA "<<endl;
    cout<<"2-DIFFERENZA "<<endl;
    cout<<"3-DIVISIONE "<<endl;
    cout<<"4-PRODOTTO "<<endl;
    cout<<"0-ESCI "<<endl;

    r=0;

    do
    {
       r++;
       if(r>1)
       {
           cout<<"re";
       }

       cout<<"inserisci la scelta:"<<endl;
       cin>>scelta;
    }
    while(scelta<=0 && scelta>=4);

    switch (scelta)
        {
        case 1:
            cout<<"Hai scelto di calcolare la somma"<<endl;
            cout<<"inserisci a"<<endl;
            cin>>a;
            cout<<"inserisci b"<<endl;
            cin>>b;

            ris=a+b;

            cout<<"a+b="<<ris<<endl;

            break;

        case 2:
            cout<<"Hai scelto di calcolare la differenza"<<endl;
            cout<<"inserisci a"<<endl;
            cin>>a;
            cout<<"inserisci b"<<endl;
            cin>>b;

            ris=a-b;

            cout<<"a-b="<<ris<<endl;
            break;

        case 3:
            cout<<"Hai scelto di calcolare la divisione"<<endl;
            cout<<"inserisci a"<<endl;
            cin>>a;
            cout<<"inserisci b"<<endl;
            cin>>b;

            ris=a/b;

            cout<<"a/b="<<ris<<endl;

            break;

        case 4:
            cout<<"Hai scelto di calcolare il prodotto "<<endl;
            cout<<"inserisci a"<<endl;
            cin>>a;
            cout<<"inserisci b"<<endl;
            cin>>b;

            ris=a*b;

            cout<<"axb="<<ris<<endl;

            break;

        case 0:
            cout<<"ESCI"<<endl;
            break;
        }

    return 0;
}
