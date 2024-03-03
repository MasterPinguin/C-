/*
Il programma legge due numeri e controlla se il primo è multiplo del secondo (usare il resto della divisione
%).
*/
#include <iostream>

using namespace std;

int a,b;
int main()
{
    cout << "inserire a" << endl;
    cin >> a;
    cout << "inserire b" << endl;
    cin >> b;
    if(a%b==0)
    {
    cout <<"b e multiplo di a"<<endl;
    }
    else
    {
    cout <<"b non e multiplo di a"<<endl;
    }
    return 0;
}
