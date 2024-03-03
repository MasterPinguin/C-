/*
Risolvere un’equazione di primo grado
*/
#include <iostream>

using namespace std;

int a,b,x;
int main()
{
    cout<<"ax+b=0 inserire valore di a: ";
    cin>>a;
    cout<<"inserire valore di b: ";
    cin>>b;

    x=-b/a;

    cout<<"x="<<x;
    return 0;
}
