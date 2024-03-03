#include<iostream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>   
using namespace std;

struct giocatore
{
    int pos;
    string nome;
};

int casuale()//funzione per il random
{
    int numero;
    numero = rand() % 6 + 1;
    return numero;
}


int main()
{
    srand(time(NULL));//comando per il random

    giocatore a, b;
    a.pos = 0;
    b.pos = 0;
    int turno = 1;
    int estrazione = 0;
    int scelta2;
    
    cout<<"Benvenuti nel gioco dell'oca a due giocatori! Sono entusiasta di offrirvi questa versione"<<endl;
    cout<<"del gioco. Con questo gioco potrete divertirvi, giocando comodamente sul pc."<<endl;
    cout<<"Non vedo l'ora di vedere chi raggiungerà per primo la casella finale e vincerà!\n"<<endl;
    
    ifstream mioFile("Oca.txt");
    if (mioFile.is_open())
    {
        do
        {   
            cout<<"Scegli tra le 2 opzioni:"<<endl;
            cout<<"1. Riprendere la partita precedente "<<endl;
            cout<<"2. Iniziare una nuova partita "<<endl;
            cin >> scelta2;

        }while(scelta2<1 || scelta2>2);
        
        if(scelta2==1)
        {
            mioFile>>turno;
            mioFile>>a.nome>>a.pos;
            mioFile>>b.nome>>b.pos;
            mioFile.close();
        }
        else
        {
            mioFile.close();

            cout<<"Inserire il nickname del primo giocatore"<<endl;
            cin>>a.nome;
            cout<<"Inserire il nickname del secondo giocatore"<<endl;
            cin>>b.nome;
        }
    }
    else
    {
        cout<<"Inserire il nickname del primo giocatore"<<endl;
        cin>>a.nome;
        cout<<"Inserire il nickname del secondo giocatore"<<endl;
        cin>>b.nome;
    }
    
    while (a.pos <50 && b.pos < 50)
    {
        // SALVATAGGIO 
        ofstream mioFile1 ("Oca.txt");
        mioFile1<<turno<<" "<<endl;
        mioFile1<<a.nome<<" "<<a.pos<<" "<<endl;
        mioFile1<<b.nome<<" "<<b.pos<<" "<<endl;
        mioFile1.close();

        int scelta;
        cout << "|-----------TURNO "<<turno <<"------------|" <<endl;
        
        do
        {
            cout<<a.nome<<", Premi 1 per tirare i dadi"<<endl;
            cin>>scelta;
        }
        while (scelta!=1);
        
        estrazione = casuale();
        a.pos += estrazione;
        cout << "Il giocatore "<<a.nome<<" tira: " << estrazione << " va a: "<<a.pos << endl;
        
        do
        {
            cout<<b.nome<<", Premi 1 per tirare i dadi"<<endl;
            cin>>scelta;
        }
        while (scelta!=1);
        
        estrazione = casuale();
        b.pos += estrazione;
        cout << "Il giocatore "<<b.nome<<" tira: " << estrazione << " va a: "<<b.pos << endl;
        cout << "|------------------------------|" <<endl;
        turno++;
        cout << endl;
    }

    cout << endl;
    if (a.pos >= 50)
        cout <<"Il giocatore " <<a.nome<< " ha vinto!"<< endl;

    if (b.pos >= 50)
        cout <<"Il giocatore " <<b.nome<< " ha vinto!"<< endl;
    return 0 ;
}