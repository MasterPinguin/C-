/*
Riempire un vettore di N elementi, fare la somma e calcolare la media.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int vett[N], som=0, med;
    srand(time(NULL));

    for(int i=0; i<=N; i++)
    {
        vett[i]=(rand()%100)+1;
        som=som+vett[i];
    }

    med=som/N;

    cout<<"la somma e' di "<<som<<" e la media e' di "<<med<<endl;

    return 0;
}

