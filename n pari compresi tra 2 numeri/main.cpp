/*
Scrivere un algoritmo che acquisito in input un numero intero N maggiore di 1 stampi,
a video tutti i numeri pari compresi tra 1 e N.
*/
#include <iostream>

using namespace std;

int r,N,i;
int main()
{
     r=0;
    do
    {
       r++;
       if(r>1)
       {
           cout<<"re";
       }

       cout<<"inserisci il numero N:"<<endl;
       cin>>N;
    }
    while(N<=1);

    for(i=1;i<=N;i++)
    {
        r=i%2;

        if(r==0)
        {
            cout<<i<<", ";
        }

    }

    return 0;
}
