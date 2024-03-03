#include <iostream>
#include <unistd.h>

using namespace std;

struct alunno
{
	string nome,cognome;
	int ita,sto,mat;
	float media;
};

//FUNZIONE
void carica(alunno x[5])
{
	for(int i=0;i<5;i++)
	{
		cout<<" "<<endl;
		cout<<"inserisci il voto di italiano di "<<x[i].nome<<" "<<x[i].cognome<<":";
		cin>>x[i].ita;
		cout<<"inserisci il voto di storia di "<<x[i].nome<<" "<<x[i].cognome<<":";
		cin>>x[i].sto;
		cout<<"inserisci il voto di matematica di "<<x[i].nome<<" "<<x[i].cognome<<":";
		cin>>x[i].mat;
		
		x[i].media=(x[i].ita+x[i].sto+x[i].mat)/3;
	}
	
	cout<<" "<<endl;
	
}

//FUNZIONE
void stampa(alunno x[5])
{
	for(int i=0;i<5;i++)
	{
	    cout<<" "<<endl;
	    sleep(2);
		cout<<"pagella di "<<x[i].nome<<" "<<x[i].cognome<<":"<<endl;
		cout<<"voto di italiano:"<<x[i].ita<<endl;
		cout<<"voto di storia:"<<x[i].sto<<endl;
		cout<<"voto di matematica:"<<x[i].mat<<endl;
		if(x[i].media<6)
		{
			cout<<"la media e' insufficente':";
		}
		else
		{
            cout<<"la media e' sufficente':";
		}
		cout<<x[i].media<<endl;
		
	}

}

//MAIN
int main()
{
	alunno v[5];
	for(int i=0;i<5;i++)
	{
		cout<<"inserisci il nome dell alunno "<<i+1<<":";
		cin>>v[i].nome;
		cout<<"inserisci il cognome dell alunno "<<i+1<<":";
		cin>>v[i].cognome;
	}
	
	carica(v);
	stampa(v);

}