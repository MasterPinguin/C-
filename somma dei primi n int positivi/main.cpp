/*
Calcolare la somma dei primi n numeri interi positivi
*/
#include <iostream>

using namespace std;

int n,i,ris;
int main()
{
    cout<<"inserisci il numero di numeri primi interi che vui vedere addizionati"<<endl;
    cin>>n;
    ris=0;

    for(i=0;i<n+1;i++)
    {
        ris=ris+i;
    }

    cout<<ris<<endl;
    return 0;
}
