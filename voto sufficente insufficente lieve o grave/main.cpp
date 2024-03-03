/*
Scrivere un programma che legge un voto e dice se insufficiente o sufficiente e se è insufficiente distingue
tra gravemente insufficiente (minore o uguale a 4) o insufficiente ovvero compreso tra 4 (escluso) e 6
(escluso).
*/
#include <iostream>

using namespace std;

int voto;
int main()
{
    cout << "inserisci il voto" << endl;
    cin>>voto;
    if(voto>6)
    {
        cout<<"sufficente"<<end;
    }
    else
    {
        if(voto<4)
        {
            cout<<"gravemente insufficente"<<endl;
        }
        else
        {
            cout<<"insufficente"<<endl;
        }
    }
    return 0;
}
