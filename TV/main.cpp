/*
Verifica di laboratorio - ottobre 2022 - FILA B
Realizzare un programma per immagazzinare i dati di un televisore: casa, modello, pollici, anno, costo.
Implementare le seguenti funzioni:


1) Scrivere una funzione per caricare un vettore di n televisori dato come parametro.

2) Scrivere una funzione per la stampa di un vettore di n televisori (parametro).

3) Scrivere una funzione per ricercare  i televisori da più di 20 pollici.

4) Scrivere una funzione per visualizzare tutti i televisori  con un costo superiore ad un valore letto in input
   e passato come parametro.

5) Scrivere una funzione ritorna il televisore più vecchio e quello più nuovo memorizzati in un vettore, dopodichè si richiami la funzione stampa precedente.
*/
#include <iostream>
#include <unistd.h>

using namespace std;

struct tv
{
    string casa, modello;
	int pollici, anno;
    float costo;
};

//FUNZIONE
void carica(tv x[], int m)
{
	for(int i=0;i<m;i++)
	{
		cout<<" "<<endl;
		cout<<"inserisci la casa produttrice della TV "<<i+1<<":"<<endl;
		cin>>x[i].casa;
		cout<<"inserisci il modello della TV "<<i+1<<":"<<endl;
		cin>>x[i].modello;
		cout<<"inserisci i pollici della TV  "<<i+1<<":"<<endl;
		cin>>x[i].pollici;
		cout<<"inserisci l'anno della TV "<<i+1<<":"<<endl;
		cin>>x[i].anno;
        cout<<"inserisci il costo della TV "<<i+1<<":"<<endl;
		cin>>x[i].costo;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void stampa(tv x[], int m)
{
    cout<<"numero     casa     modello      pollici       anno       costo"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<" "<<endl;
		cout<<i+1<<"         "<<x[i].casa<<"        "<<x[i].modello<<"        "<<x[i].pollici<<"        "<<x[i].anno<<"        "<<x[i].costo<<endl;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void t1(tv x[], int m)
{
    bool n=true;

    cout<<"i televisori con piu' di 20 pollici sono: ";
    cout<<" "<<endl;

    for(int i=0;i<m;i++)
    {
        if(x[i].pollici > 20)
        {
            cout<<"numero     casa     modello      pollici       anno       costo"<<endl;
            cout<<" "<<endl;
            cout<<i+1<<"         "<<x[i].casa<<"        "<<x[i].modello<<"        "<<x[i].pollici<<"        "<<x[i].anno<<"        "<<x[i].costo<<endl;
            n=false;
        }
    }

    if(n==true)
    {
        cout<<"c'e' stato un errore non ci sono TV con piu' di 20 pollici"<<endl;
    }
    cout<<" "<<endl;
}

//FUNZIONE
void t2(tv x[], int m)
{
    int prezzo;
    bool n=true;

    cout<<"inserisci il costo della TV per poter poi visualizzare tutti i televisori a costo maggiore: ";
    cin>>prezzo;
    cout<<" "<<endl;

    for(int i=0;i<m;i++)
    {
        if(x[i].costo > prezzo)
        {
            cout<<"numero     casa     modello      pollici       anno       costo"<<endl;
            cout<<" "<<endl;
            cout<<i+1<<"         "<<x[i].casa<<"        "<<x[i].modello<<"        "<<x[i].pollici<<"        "<<x[i].anno<<"        "<<x[i].costo<<endl;
            n=false;
        }
    }

    if(n==true)
    {
        cout<<"non ci sono TV con costo maggiore a quello inserito"<<endl;
    }
    cout<<" "<<endl;
}

//FUNZIONE
int t3(tv x[], int m)
{
    int y[2];
    int min,magg;

    if(m < 2)
    {
        cout<<" "<<endl;
        cout<<"il programma non puo proseguire siccome c'e' solo un elemento ";
        cout<<" "<<endl;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(x[i].anno < min || i==0)
            {
                y[0]=i;
                min=x[i].anno;
            }
            if(x[i].anno > magg || i==0)
            {
                y[1]=i;
                magg=x[i].anno;
            }
        }
    }

    return y[2];
}

//MAIN
int main()
{
    int n, k[2];
    char scelta;

    cout<<"inserisci il numero di televisori su cui vuoi operare ";
    cin>>n;

	tv v[n], z[2];

    do
    {
        cout<<"1) carica i dati dei televisori "<<endl;
        cout<<"2) stampa i dati dei televisori "<<endl;
        cout<<"3) trova i televisori con più di 20 pollici "<<endl;
        cout<<"4) trova i televisori con un costo superiore a quello dato in input "<<endl;
        cout<<"5) trova i televisori piu nuovi e vecchi "<<endl;
        cout<<"6) ESCI"<<endl;

        cout<<"Inseri la tua sciscelta [1-6]:"<<endl;
        cin>>scelta;


        switch (scelta)
            {
            case '1':
                cout<<"Hai scelto la funzionalita' uno"<<endl;

                cout<<"inserisci i dati dei televisori ";
                carica(v,n);

                break;

            case '2':
                cout<<"Hai scelto la funzionalita' due"<<endl;

                stampa(v,n);

                break;

            case '3':
                cout<<"Hai scelto la funzionalita' tre"<<endl;

                t1(v,n);

                break;

            case '4':
                cout<<"Hai scelto la funzionalita' quattro"<<endl;

                t2(v,n);

                break;
            
            case '5':
                cout<<"Hai scelto la funzionalita' cinque"<<endl;

                k[2]=t3(v,n);
                z[0]=v[k[0]];
                z[1]=v[k[1]];
                stampa(z,2);

                break;

            default:
                cout<<"Attenzione scelta sbagliata!!!!!"<<endl;
            }

    }
    while(scelta!='6');

    return 0;

}