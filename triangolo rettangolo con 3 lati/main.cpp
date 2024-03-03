/*
Scrivere un programma che legge i lati di un triangolo e dice se questo è un triangolo rettangolo.
*/
#include <iostream>

using namespace std;

float l1,l2,l3,i,c1,c2,y;
int main()
{
    cout << "inserire numero l1" << endl;
    cin>>l1;
    cout << "inserire numero l2" << endl;
    cin>>l2;
    cout << "inserire numero l3" << endl;
    cin>>l3;

    if(l1>l2)
    {
        if(l1>l3)
        {
            i=l1;
            c1=l2;
            c2=l3;
        }
        else
        {
            i=l3;
            c1=l2;
            c2=l1;
        }
    }
    else
    {
        if(l2>l3)
        {
            i=l2;
            c1=l1;
            c2=l3;
        }
        else
        {
            i=l3;
            c1=l2;
            c2=l1;
        }
    }
    y=sqrt(c1^2+c2^2);
    if(y==i)
    {
        cout<<"il triangolo e' un triangolo rettangolo"<<endl;
    }
    else
    {
        cout<<"il triangolo non e' un triangolo rettangolo"<<endl;
    }
    return 0;
}
