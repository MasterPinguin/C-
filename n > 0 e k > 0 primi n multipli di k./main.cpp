/*
Letti due interi n > 0 e k > 0 stampa i primi n multipli di k.
*/
#include <iostream>

using namespace std;

int n,i,k,ris;
int main()
{
    do
    {
        cout<<"inserisci k "<<endl;
        cin>>k;
    }
    while(k<0);

    do
    {
        cout<<"inserisci il numero dei primi numeri multipli di k che vuoi vedere "<<endl;
        cin>>n;
    }
    while(n<0);


    for(i=2;i<n+2;i++)
    {
        ris=k*i;
        cout<<ris<<" ";
    }

    return 0;
}
