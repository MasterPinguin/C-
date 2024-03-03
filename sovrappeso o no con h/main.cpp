/*
L�utente inserisce il proprio peso e il programma dice se � in sovrappeso o normopeso (ovvero con peso
maggiore uguale a 70 kg si � in sovrappeso).
*/
#include <iostream>

using namespace std;

float peso;
int main()
{
    cout << "Inserisci il tuo peso" << endl;
    cin>>peso;
    if(peso>=70)
    {
        cout<<"sei in sovrappeso"<< endl;
    }
    else
    {
         cout<<"sei in normopeso"<< endl;
    }
    return 0;
}
