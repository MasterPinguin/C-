/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <fstream> 

using namespace std;

int main()
{
    string riga;
    int vett[5], i=0, x;
    
    //lettura dal file
    ifstream mioFile ("SCOPA.txt");
    if (mioFile.is_open())
    {
        //assegno a ogni cella un valore nel vettore prendendolo dal file
        mioFile>>x;
        for(int i=0; i<5; i++) mioFile>>vett[i];
        mioFile.close();
    }
    else
    {
        cout<< "inserisci i numeri"<<endl;
        for(int i=0; i<5; i++) cin>>vett[i];
        
        //scrivo nel vettore il valore di ogni cella
        ofstream mioFile1 ("SCOPA.txt");
        for(int i=0; i<5; i++) mioFile1<<vett[i]<<" ";
    }
    
    cout<<" "<<x<<endl;
    
    for(int i=0; i<5; i++) cout<<vett[i]<<" ";

    return 0;
}
