/*
Letti due interi n > 0 e k > 0 stampa il risultato della sommatoria k+k^2+k^3...+k^n.
*/
#include <iostream>

using namespace std;

int n,i,k,ris,som;
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
        cout<<"inserisci n "<<endl;
        cin>>n;
    }
    while(n<0);

    ris=1;
    som=0;

    for(i=0;i<n;i++)
    {
        ris=ris*k;
        som=som+ris;
    }

    cout<<som<<endl;

    return 0;
}
