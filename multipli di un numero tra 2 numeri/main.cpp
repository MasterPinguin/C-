/*
Dopo aver inserito due valori numerici interi (num_1, num_2) verificando che il primo
sia inferiore al secondo, chiedere in input un terzo numero (num_3) compreso
tra num_1 e num_2 ( num_1 < num_3 < num_2) e visualizzare tutti i multipli del terzo numero
compresi tra i primi due numeri inseriti.
*/
#include <iostream>

using namespace std;

int n1,n2,n3,i;
int main()
{
    i=0;
    do
    {
       i++;
       if(i>1)
       {
           cout<<"re";
       }

       cout<<"inserisci il numero n1 minore di n2:"<<endl;
       cin>>n1;
       if(i>1)
       {
           cout<<"re";
       }
       cout<<"inserisci il numero n2 maggione di n1:"<<endl;
       cin>>n2;
    }
    while(n1>n2);

    i=0;

    do
    {
       i++;
       if(i>1)
       {
           cout<<"re";
       }

       cout<<"inserisci un numero compreso tra n1 e n2:"<<endl;
       cin>>n3;
    }
    while(n3<n1 && n3>n2);

    for(i=n3; i>n1 && i<n2; i=i+n3)
    {
        cout<<i<<", ";
    }

    return 0;
}
