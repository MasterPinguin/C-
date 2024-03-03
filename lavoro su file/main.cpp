/*
Dato il file di testo dante.txt scrivere un programma con le seguenti funzioni.

1- Dato un carattere in input conta le occorrenze.

2- Crea il file "copia.txt" copia di dante.txt.

3- Stampa il numero di caratteri contenuto nel testo.

4- Scrive un file "dispari.txt" contene solo le righe dispari di del file input.

5- Dati due caratteri in input sostituisce tutte le occorrenze del primo con il secondo e 
salva sul file "sostituto.txt".
*/
#include <iostream>
#include <fstream>
using namespace std;

//FUNZIONE
int numOcc(char x)
{
    string riga;
    int y=0;
    
    ifstream dante ("dante.txt");
    if(dante.is_open())
    {
        while (getline(dante,riga))
        {
            for(int i=0;i<riga.length();i++)
            {
                if(riga[i]==x)
                {
                    y++;
                }
            }
        }
        dante.close();
    }
    else cout<<"apertura file fallita";
    return y;
}

//FUNZIONE
void copia()
{
    string riga;
    
    ifstream dante ("dante.txt");
    ofstream copia ("copia.txt");
    if(dante.is_open())
    {
        while (getline(dante, riga))
        {
            copia<<riga<<endl;
        }
        dante.close();
    }
    else cout<<"apertura file fallita";
    copia.close();
}

//FUNZIONE
int numChar()
{
    string riga;
    int z=0;
    
    ifstream dante ("dante.txt");
    if(dante.is_open())
    {
        while(getline(dante, riga))
        {
            z=z+riga.length();
        }
    }
    else cout<<"apertura file fallita";
    dante.close();
    return z;
}

//FUNZIONE
void rigDisp()
{
    string riga;
    
    ofstream dispari ("dispari.txt");
    ifstream dante ("dante.txt");
    if(dante.is_open())
    {
        for(int i=0; getline(dante,riga); i++)
        {
            if(i%2==1)
            {
                dispari<<riga<<endl;
            }
        }
        
        dante.close();
    }
    else cout<<"apertura file fallita";
    dispari.close();
}

//FUNZIONE
void Sost(char a, char b)
{
    string riga;
    
    ofstream sostituto ("sostituto.txt");
    ifstream dante ("dante.txt");
    if (dante.is_open())
    {
        while(getline(dante,riga))
        {
            for(int i=0; i<riga.length(); i++)
            {
                if(riga[i]==a)
                {
                    riga[i]=b;
                    
                }
                
            }
            sostituto<<riga<<endl;
        }
        dante.close();
    }
    else cout<<"apertura file fallita";
    sostituto.close();
}

//MAIN
int main()
{
    char x, a, b;
    
    cout<<"inserisci il carattere da ricercare: " << endl;
    cin>>x;
    
    cout<<"il carattere è presente "<< numOcc(x) <<" volte" << endl;

    cout<<"i caratteri presenti nel testo sono "<<numChar()<<endl;

    cout<<"inserisci il carattere da sostituire: " << endl;
    cin>>a;
    cout<<"inserisci il carattere sostituto: " << endl;
    cin>>b;
    
    copia();
    rigDisp();
    Sost(a, b);

    return 0;
}