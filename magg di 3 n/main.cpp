/*
Dati 3 numeri interi visualizzare il maggiore.
*/
#include <iostream>

using namespace std;

int a,b,c;
int main()
{
    cout << "inserire numero 1" << endl;
    cin>>a;
    cout << "inserire numero 2" << endl;
    cin>>b;
    cout << "inserire numero 3" << endl;
    cin>>c;
    if(a>b)
    {
        if(a>c)
        {
            cout<<a<<endl;
        }
        else
        {
             cout<<c<<endl;
        }
    }
    else
    {
        if(b>c)
        {
            cout<<b<<endl;
        }
        else
        {
             cout<<c<<endl;
        }
    }
    return 0;
}
