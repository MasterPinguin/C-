/*
I dati sugli incassi di 3 reparti di un grande magazzino nei primi 6 mesi dell’anno
sono organizzati in una matrice, il numero di riga indica il numero del reparto,
il numero di colonna indica il mese. Calcolare l’incasso totale del mese di aprile.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int n, ris=0, mat[3][6];

    cout<<"   Mese:   Gennaio Febbraio Marzo  Aprile  Maggio  Giugno "<<endl;

    for(int i=0 ; i<=2 ; i++)
    {
        cout<<"reparto "<<i+1<<":  ";
        for(int j=0 ; j<=5 ; j++)
        {
            mat[i][j]=((rand())%3000)+2000;
            cout<<mat[i][j]<<",   ";
        }
        cout<<" "<<endl;
    }
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"l'incasso totale di Aprile e' di: ";

    for(int j=0 ; j<=2 ; j++)
    {
        ris=ris+mat[j][3];
    }

    cout<<ris;


    return 0;
}
