/*
1) Data in input l'etˆ di uno studente, visualizzare a video "sei maggiorenne" o "sei minorenne";
*/
#include <iostream>

using namespace std;

int eta;
int main()
{
    cout << "inserisci l'eta'"<<endl;
    cin>>eta;

    if(eta<18)
    {
        cout << "sei minorenne"<<endl;
    }
    else
    {
        cout << "sei maggiorenne" << endl;
    }

    return 0;
}
