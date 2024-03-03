/*
Scrivere un programma che dopo aver riempito una matrice NxM (con N e M acquisiti da tastiera),
visualizzi a video gli elementi della matrice.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int N, M;

    cout<<"inserire i valori N della matrice";
    cin>>N;
    cout<<"inserire i valori M della matrice";
    cin>>M;

    int mat[N][M];

    srand(time(NULL));

    for(int i=0 ; i<=N ; i++)
    {
        for(int j=0 ; j<=M ; j++)
        {
            mat[i][j]=((rand())%100)+1;
            cout<<mat[i][j]<<", ";
        }
        cout<<" "<<endl;
    }


    return 0;
}
