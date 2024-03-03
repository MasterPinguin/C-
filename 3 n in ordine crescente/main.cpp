/*
Il programma legge tre numeri e li mette in ordine crescente (usare gli operatori logici)
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
    if(a<b && a<c)
    {
        cout<<a<<endl;
        if(b<c)
        {
            cout<<b<<endl;
            cout<<c<<endl;
        }
        else
        {
             cout<<c<<endl;
             cout<<b<<endl;
        }
    }
    else
    {
        if(b<c && b<a)
        {
            cout<<b<<endl;
            if(a<c)
            {
                cout<<a<<endl;
                cout<<c<<endl;
            }
            else
            {
                cout<<c<<endl;
                cout<<a<<endl;
            }
        }
        else
        {
            cout<<c<<endl;
            if(a<b)
            {
                cout<<a<<endl;
                cout<<b<<endl;
            }
            else
            {
                cout<<b<<endl;
                cout<<a<<endl;
            }

        }
    }
    return 0;
