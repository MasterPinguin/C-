// ordinamento di un vettore mediante il metodo di selezione (ricerca del minimo) #include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int maxdim = 10;
int dim, pmin;

//FUNZIONI
int dimensione_vettore()
{
    do
    {
        cout << "Inserire la dimensione del vettore (max="<<maxdim<<"): ";
        cin >> dim;
    }
    while ((dim < 1 ) || (dim > maxdim));

    return dim;
}

//FUNZIONI
void carica_vettore(int v[], int dimvet)
{
    srand (time(NULL));
    for (int i = 0; i < dimvet; ++i)
    {
        v[i]= (rand()%100);
    }
}

//FUNZIONI
void visualizza_vettore(int v[], int dimvet)
{
    cout<<"\nVisualizzazione vettore"<<endl;

    for (int i=0; i < dimvet; ++i)
    {
        cout << "\nL'elemento di posto " << i+1 << "...: " << v[i]<<endl;

    }

}

//FUNZIONI
void scambia(int &x, int &y)
{
    int temp;
    temp = x; x = y;
    y = temp;
}

//FUNZIONI
void ricerca_minimo(int v[], int dimvet, int posizione)
{
    int min;
    min = v[posizione];
    pmin = posizione;
    for (int j=posizione+1; j < dimvet; ++j )
    {
        if (min > v[j])
        {
            min = v[j]; pmin = j;
        }

    }
}

//FUNZIONI
void ordinamento_vettore(int v[], int dimvet)
{
    for (int i=0; i < dim ; ++i)
    {
        ricerca_minimo(v,dim,i);
        scambia(v[i],v[pmin]);
    }
}

//MAIN
int main (int argc, char *argv[])
{
    char quit;
    quit = '\0';
    int array[maxdim] = {0};
    while (quit != 'q')
    {
        dimensione_vettore();
        carica_vettore(array,dim);
        cout << "\n Vettore caricato : " << endl;
        visualizza_vettore(array,dim);
        ordinamento_vettore(array,dim);
        cout << "\n Vettore ordinato : " <<endl;
        visualizza_vettore(array,dim);
        cout << "Premere q per uscire ";
        cin >> quit;
    }

    return 0;
}
