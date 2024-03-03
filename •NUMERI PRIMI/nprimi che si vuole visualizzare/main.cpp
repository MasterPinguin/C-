#include <iostream>

using namespace std;

int m,n,c,x,r,y,g,vett[10000];
int main()
{
    cout << "inserisci il numero dei numeri primi che vuoi visualizzare" << endl;
    cin>>m;
    n=1;
    c=0;
    while(c!=m-2){
        do{

        y=n/2;
        n++;
        x=1;

            do{
                x++;
                r=n%x;
            }
            while(r!=0 && x!=y);

            if(r!=0){ g=1;}
            else{ g=0;}
        }while(g==0);

        vett[c]=n;
        c++;
    }

    cout<< 1 <<", "<< 2;

    for(c=0;c!=m-2;c++)
    {
       cout<<", "<<vett[c];
    }

    return 0;
}
