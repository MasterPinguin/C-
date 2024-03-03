/*
I dati sugli stipendi di 5 dipendenti nei primi 3 mesi
dell’anno sono organizzati in una matrice, il numero di riga indica il numero del dipendente,
il numero di colonna indica il mese. Calcolare la somma degli stipendi pagati al secondo dipendente.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int n, ris=0, mat[5][3];

    cout<<"    Mese:         1    2    3 "<<endl;

    for(int i=0 ; i<=4 ; i++)
    {
        cout<<"dipendente "<<i+1<<":  ";
        for(int j=0 ; j<=2 ; j++)
        {
            mat[i][j]=((rand())%1000)+1000;
            cout<<mat[i][j]<<", ";
        }
        cout<<" "<<endl;
    }
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"la somma dello stipendio del dipendente 2 e' di: ";

    for(int j=0 ; j<=2 ; j++)
    {
        ris=ris+mat[1][j];
    }

    cout<<ris;


    return 0;
}
