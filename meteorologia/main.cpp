/*
Sviluppare un programma per la gestione di una stazione meterologica. Il programma 
deve essere in grado di gestire i seguenti dati:

Giorno
Mese
Temperatura
Umidità (da 0 a 100)
Luogo
Vengono effettuate N rilevazioni.

Sviluppare le seguenti funzionalità:

Salvataggio su file di testo
Lettura da file
*/
#include <iostream>
#include <fstream> 
#include <unistd.h>

using namespace std;

struct meteo
{
    string l;
	int g,m,t,u;
};

//FUNZIONE
void carica(meteo x[], int n)
{
    bool K=false;
    
	for(int i=0;i<n;i++)
	{
	    cout<<endl;
		cout<<" "<<i+1<<":"<<endl;
		cout<<"inserisci il luogo della misurazione :";
		cin>>x[i].l;
		do
		{
		    if(K==true) cout<<"non esiste il giorno "<<x[i].g<<" reinserisci :"<<endl;
		    else cout<<"inserisci inserisci il giorno della misurazione :";
		    cin>>x[i].g;
		    K=true;
		}
		while(x[i].g>31 || x[i].g<1);
		K=false;
		do
		{
		    if(K==true) cout<<"non esiste il mese "<<x[i].m<<" reinserisci :"<<endl;
		   	else cout<<"inserisci il mese della misurazione :";
		    cin>>x[i].m;
		    K=true;
		}
		while(x[i].m>12 || x[i].m<1);
		K=false;
		cout<<"inserisci la temperatura misurata :";
		cin>>x[i].t;
		do
		{
		    if(K==true) cout<<"l'umidita' varia il suo valore da 0 a 100, "<<x[i].u<<" non e' compreso in questo intervallo, reinserisci : "<<endl;
		   	else cout<<"inserisci l'umidita' misurata :";
		    cin>>x[i].u;
		    K=true;
		}
		while(x[i].u>100 || x[i].u<0);
		K=false;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void stampa(meteo x[], int n)
{
    cout<<"numero     luogo     giono      mese      temperatura     umidita'"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<endl;
		cout<<i+1<<"        "<<x[i].l<<"       "<<x[i].g<<"       "<<x[i].m<<"       "<<x[i].t<<"       "<<x[i].u<<endl;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void salvataggio(meteo x[], int n)
{
	ofstream mioFile0 ("Dati.txt");
	mioFile0<<n<<endl;
    for(int i=0 ; i<n; i++) mioFile0<<x[i].g<<" "<<x[i].m<<" "<<x[i].t<<" "<<x[i].u<<" "<<x[i].l<<" "<<endl;
    mioFile0.close();
}

//MAIN
int main()
{
	int k=2,m,k2=1;
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
            mioFile>>m;
            meteo v[m];
            for(int y=0 ; y<m; y++) mioFile>>v[y].g>>v[y].m>>v[y].t>>v[y].u>>v[y].l;
            mioFile.close();
            
            stampa(v,m);
            
            k1=false;
            do
            {
                if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
                
                cout<<"Vuoi salvare i dati? (1) Si (2) No "<<endl;
                cin >> k2;
                k2=true;
            }while(k2<1 || k2>2);
            
            if(k2==1)
            {
                salvataggio(v,m);
            }
        }
        else mioFile.close();
    }
    if(k==2)
    {
        cout<<"i dati di quanti luoghi vuoi caricare ? "<<endl;
        cin>>m;
        
        meteo v[m];
        	
        cout<<"inserisci i valori: ";
        carica(v,m);
        
        stampa(v,m);
	
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
            salvataggio(v,m);
        }
    }
	
}