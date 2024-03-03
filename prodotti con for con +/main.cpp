/*
Scrivere un algoritmo che calcoli il prodotto di due numeri (assumendo come nota l’addizione).
*/
#include <iostream>

using namespace std;

int n1,n2,i,x;
int main()
{
    cout << "inserisci i due numeri da moltiplicare" << endl;
    cin>>n1;
    cin>>n2;

    for(i=0;i<n1;i++)
    {
        x=x+n2;
    }
    cout<<x<<endl;

    return 0;
}
