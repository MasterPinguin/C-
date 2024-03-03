/*
Visualizzare un menù che consenta all'utente di scegliere un poligono
e calcolarne l'area.
In base alla scelta (triangolo, rettangolo, quadrato), il programma deve richiedere
i dati necessari al calcolo (base, altezza o lato).
Il programma finisce quando l'utente digita 'F'.
*/
#include <iostream>

using namespace std;

int main()
{
    char scelta;
    float base,altezza,area,lato,r;

    cout<<"scegli: "<<endl;
    cout<<"a-triangolo "<<endl;
    cout<<"b-rettangolo "<<endl;
    cout<<"c-quadrato "<<endl;
    cout<<"F-FINE "<<endl;

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
    while(scelta!='a' && scelta!='b' && scelta!='c' && scelta!='F');

    switch (scelta)
        {
        case 'a':
            cout<<"Hai scelto di calcolare l'area del triangolo"<<endl;
            cout<<"inserisci la base"<<endl;
            cin>>base;
            cout<<"inserisci l'altezza"<<endl;
            cin>>altezza;

            area=(base*altezza)/2;

            cout<<"l'area e'"<<area<<endl;

            break;

        case 'b':
            cout<<"Hai scelto di calcolare l'area del rettangolo"<<endl;
            cout<<"inserisci la base"<<endl;
            cin>>base;
            cout<<"inserisci l'altezza"<<endl;
            cin>>altezza;

            area=base*altezza;

            cout<<"l'area e'"<<area<<endl;

            break;

        case 'c':
            cout<<"Hai scelto di calcolare l'area del quadrato"<<endl;
            cout<<"inserisci il lato"<<endl;
            cin>>lato;

            area=lato*lato;

            cout<<"l'area e'"<<area<<endl;

            break;

        case 'F':
            cout<<"FINE"<<endl;
            break;
        }

    return 0;
}
