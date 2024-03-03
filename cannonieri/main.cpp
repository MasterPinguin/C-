/*
Scrivere un programma per memorizzare i cannonieri della serie A, i dati rilevanti sono 
il nome, la squadra, e il numero di gol segnati. Fornire le seguenti funzionalità:

1- Inserimento di almeno 5 cannonieri

2- Stampa dei cannonieri in classifica

3- Modifica del numero di gol

*/
#include <iostream>
#include <unistd.h>

using namespace std;

struct cann
{
    string nome, sq;
	int gol;
};

//FUNZIONE
void carica(cann x[5])
{
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<"inserisci il nome del cannoniere "<<i+1<<":";
		cin>>x[i].nome;
		cout<<"inserisci la squadra del cannoniere "<<i+1<<":";
		cin>>x[i].sq;
		cout<<"inserisci i gol del cannoniere "<<i+1<<":";
		cin>>x[i].gol;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void stampa(cann x[5])
{
    cout<<"numero     nome     squadra      gol"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<i+1<<"        "<<x[i].nome<<"       "<<x[i].sq<<"       "<<x[i].gol<<endl;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void gol(cann x[5])
{
		for(int i=0;i<5;i++)
	{
		cout<<"reinserisci i gol del cannoniere "<<i+1<<":";
		cin>>x[i].gol;
	}
	
	cout<<" "<<endl;
}

//MAIN
int main()
{
	cann v[5];
    
    cout<<"inserisci i valori delle case ";
	carica(v);
	stampa(v);
	gol(v);

}