#include <iostream>

using namespace std;

int esp,y;
float n,x;
int main()
{
    esp=0;
    y=0;
    do
    {
       y++;
       if(y>1)
       {
           cout<<"Re";
       }
       else
       {
            cout<<"I";
       }

       cout<<"nserisci in numero da semplificare:"<<endl;
       cin>>n;
    }
    while(n<1);

    x=n;

    while(x>=10)
    {
        x=x/10;
        esp=esp+1;
    }

    cout<<x<<"•10^"<<esp<<endl;

    return 0;
}
