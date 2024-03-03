/*
Dopo aver caricato in memoria una matrice di interi quadrata di ordine n
(con n inserito da tastiera non superiore a 10),
sommare gli elementi della diagonale principale.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int n, ris=0;

    do
    {
        cout<<"inserire i valori N della matrice";
        cin>>n;
    }
    while(n>10);

    int mat[n][n];

    srand(time(NULL));

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            mat[i][j]=((rand())%100)+1;
        }
    }

    for(int i=0 ; i<=n ; i++)
    {
        ris=ris+mat[i][i];
    }

    cout<<ris;


    return 0;
}
