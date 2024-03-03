#include <iostream>

using namespace std;

//FUNZIONE
int input(int &h, int &m, int &s)
{
    do
    {
        cout<<"inserisci le ore"<<endl;
        cin>>h;
    }
    while(h>24 || h<0);

    do
    {
        cout<<"inserisci i minuti"<<endl;
        cin>>m;
    }
    while(m>60 || m<0);
    
    do
    {
        cout<<"inserisci i secondi"<<endl;
        cin>>s;
    }
    while(s>60 || s<0);

    return 0;
}

//FUNZIONE
int tempo()
{
    int h,m,s,z;
    
    input(h, m, s);

    z=(h*3600)+(m*60)+s;

    return z;
}

//FUNZIONE
int diff()
{
    int a,b,z;

    cout<<"inserisci due numeri di cui si dovra' trovare la differenza"<<endl;

    cout<<"inserisci il primo tempo"<<endl;
    a=tempo();
    cout<<"inserisci il secondo tempo"<<endl;
    b=tempo();

    if(a>=b)
    {
        z=a-b;
    }
    else
    {
        z=b-a;
    }
    
    cout<<"la differenza e' di "<<z<<endl;

    return z;
}

//FUNZIONE
int diffMazNott()
{
    int a, b=86400,z;
    cout<<"inserisci il numero di cui bisognera' trovare quanto mnca a mezzanotte"<<endl;
    a=tempo();
    z=b-a;

    cout<<"a mezzanotte mancano "<<z<<" secondi "<<endl;

    return z;
}

//MAIN
int main()
{
    int A,B,Z;

    cout<<"inserisci due numeri di cui si dovra' verificare quale e' il maggiore"<<endl;

    cout<<"inserisci il primo tempo"<<endl;
    A=tempo();
    cout<<"inserisci il secondo tempo"<<endl;
    B=tempo();

    if(A>B)
    {
        cout<<"il primo tempo inserito e' maggiore del secondo"<<endl;
    }
    else
    {
        if(A==B)
        {
            cout<<"i due tempi inseriti sono uguali"<<endl;
        }
        else
        {
            cout<<"il secondo tempo inserito e' maggiore del primo"<<endl;
        }
    }

    diff();
    
    diffMazNott();

    return 0;
}
