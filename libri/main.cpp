/*
Es 2. Definire la struct Libro contenente titolo, autore, prezzo e numero di pagine.
Scrivere le funzioni per caricare 5 libri, per stampare l'elenco dei libri,
per cercare un libro dato il titolo.
*/
#include <iostream>
#include <unistd.h>

using namespace std;

struct libro
{
    string titolo,autore;
	int prezzo, pag;
};

//FUNZIONE
void carica(libro x[5])
{
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<"inserisci il titolo del libro "<<i+1<<":"<<endl;
		cin>>x[i].titolo;
		cout<<"inserisci l' autore del libro "<<i+1<<":"<<endl;
		cin>>x[i].autore;
		cout<<"inserisci il prezzo del libro "<<i+1<<":"<<endl;
		cin>>x[i].prezzo;
		cout<<"inserisci il numero di pagine del libro "<<i+1<<":"<<endl;
		cin>>x[i].pag;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void stampa(libro x[5])
{
    cout<<"numero     titolo     autore      costo       pagine"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<i+1<<"        "<<x[i].titolo<<"       "<<x[i].autore<<"       "<<x[i].prezzo<<"       "<<x[i].pag<<endl;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void cerca(libro x[5])
{
    string y;
    int n=0;
    do
    {
        n=0;
        cout<<"inserisci il titolo del libro ricercato ";
        cin>>y;
        for(int i=0;i<5;i++)
    	{
    	    if(y==x[i].titolo)
    	    {
    	        cout<<"numero     titolo     autore      costo       pagine"<<endl;
    	        cout<<" "<<endl;
		        cout<<i+1<<"        "<<x[i].titolo<<"       "<<x[i].autore<<"       "<<x[i].prezzo<<"       "<<x[i].pag<<endl;
		        n++;
    	    }
    	}
    }
    while(n==0);
}

//MAIN
int main()
{
	libro v[5];
    
    cout<<"inserisci i valori deli libri ";
	carica(v);
	stampa(v);
	cerca(v);

}