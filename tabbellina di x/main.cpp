/*
Dato un numero in input visualizzare la sua tabellina.
*/
#include <iostream>

using namespace std;

int n,i,d;
int main()
{
    cout<<"inserisci il numero del quale vuoi la tabballina"<<endl;
    cin>>n;
    d=0;

    for(i=0;i<10;i++)
    {

        d=d+n;
        cout <<d<<",";
    }
    return 0;
}
