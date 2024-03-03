/*
Es 1. Definire una struct casa per memorizzare i dati delle case da parte di 
un’agenzia immobiliare, ogni casa è caratterizzata da un numero intero di metri quadri,
dalla classe energetica (definita da una lettera, dove la A rappresenta la casa a minor
consumo energetico la F quella a maggior consumo) e dal costo in migliaia di euro.
Chiedere all’utente i dati di cinque case e poi dire qual è quella col minor costo
al metro quadro e quella con la migliore classe energetica (in caso di parità di livello
di classe energetica si riporti quella più grande).
*/
#include <iostream>
#include <unistd.h>

using namespace std;

struct casa
{
	int mq, costo;
	string consumo;
};

//FUNZIONE
void carica(casa x[5])
{
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<"inserisci i metri quadrati della casa "<<i+1<<":";
		cin>>x[i].mq;
		cout<<"inserisci il costo della casa "<<i+1<<":";
		cin>>x[i].costo;
		do
		{
		cout<<"inserisci A per una casa a minor consumo energetico e F per una a maggior consumo per la casa "<<i+1<<":";
		cin>>x[i].consumo;
		}
		while(x[i].consumo!="A" && x[i].consumo!="F");
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void minorcosto(casa x[5])
{
    int cxmq,X,y;
	for(int i=0;i<5;i++)
	{
        cxmq=x[i].costo/x[i].mq;
        
        if(i==0)
		{
			X=cxmq;
		}
		
		if(cxmq<=X)
		{
			X=cxmq;
			y=i+1;
		}
		
	}
	cout<<"la casa con il minor costo per metro quadrato e':"<<y<<" con un costo di:"<<X<<"a metro quadrato"<<endl;

}

//FUNZIONE
void migliorenergia(casa x[5])
{
	int max,migl;
	for(int i=0;i<5;i++)
	{
        if(i==0)
		{
			max=x[i].mq;
		}
		
		if(x[i].mq>=max)
		{
			max=x[i].mq;
			
			if(x[i].consumo=="A")
			{
			    migl=i;
			}
		}
		
	}
	cout<<"la casa con la migliore classe energetica e':"<<migl;
}

//MAIN
int main()
{
	casa v[5];
    
    cout<<"inserisci i valori delle case ";
	carica(v);
	minorcosto(v);
	migliorenergia(v);

}