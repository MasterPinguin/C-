/*
Fare un programma che legge i coefficienti a,b,c di unÕequazione di secondo grado e ne calcola le soluzioni,
quando possibile (fare gli opportuni controlli). Utilizzare la libreria #include <math.h> per calcolare la
radice quadrata sqrt(n).
*/
#include <math.h>

using namespace std;

float a,b,c,d,x1,x2,x;
int main()
{
    cout << "inserire coefficente a" << endl;
    cin>>a;
    cout << "inserire coefficente b" << endl;
    cin>>b;
    cout << "inserire coefficente c" << endl;
    cin>>c;
    cout<<a<<"x^2 "<<b<<"x "<<c<<"= 0"<<endl;

    d=(b^2)-4*a*c;
    if(d>=0)
    {
        if(d>0)
        {
            x1=(-b+sqrt(d))/(2*a);
            x2=(-b-sqrt(d))/(2*a);
            cout<<"il risultato e' ["<<x1<<", "<<x2<<"]"<<endl;
        }
        else
        {
            x=(-b)/(2*a);
            cout<<"il risultato e' ["<<x<<"]"<<endl;
        }
    }
    else
    {
        cout<<"impossibile"<<endl;
    }
    return 0;
}
