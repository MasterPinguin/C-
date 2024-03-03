/*
Scrivere un programma per memorizzare i cannonieri della serie A, i dati rilevanti sono 
il nome, la squadra, e il numero di gol segnati. Fornire le seguenti funzionalità:

1- Inserimento di almeno 5 cannonieri

2- Stampa dei cannonieri in classifica

3- Modifica del numero di gol

Consentire il salvataggio della classifica e l'aggiornamento della stessa.
*/
#include <iostream>
#include <fstream> 
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
	int k=2;
	bool k1;
	
	ifstream mioFile("Dati.txt");
    if (mioFile.is_open())
    {
        k1=false;
        do
        {
            if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
            
            cout<<"Vuoi recuperare i deti precedenti? (1) Si (2) No "<<endl;
            cin >> k;
            k1=true;
        }while(k<1 || k>2);
        if(k==1)
        {
            for(int y=0 ; y<5; y++) mioFile>>v[y].nome>>v[y].sq>>v[y].gol;
            mioFile.close();
        }
        else mioFile.close();
    }
    if(k==2)
    {
        cout<<"inserisci i valori: ";
        carica(v);
    }
	
	stampa(v);
	gol(v);
	
	k1=false;
    do
    {
        if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
        
        cout<<"Vuoi salvare i dati? (1) Si (2) No "<<endl;
        cin >> k;
        k1=true;
    }while(k<1 || k>2);
    
    if(k==1)
    {
        ofstream mioFile0 ("Dati.txt");
        for(int y=0 ; y<5; y++) mioFile0<<v[y].nome<<" "<<v[y].sq<<" "<<v[y].gol<<" "<<endl;
        mioFile0.close();
    }
	
}