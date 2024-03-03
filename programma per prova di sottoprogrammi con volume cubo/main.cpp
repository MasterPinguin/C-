#include <iostream>
using namespace std;

float cubo(float c)
{
   return c*c*c;
}

int main ()
{
    float lato;
    float c;

    cout<<"Inserisci il lato del cubo, calcolero' il volume:\n";
    cin>>lato;

    c=cubo(lato);
    cout<<c;
}
