#include <iostream>

using namespace std;

int n,g,x,b,t,i,y,R,esp,r[100000],a[1000000],c[1000000];
int main()
{
    cout << "inserire numero da scomporre in fattori primi: " << endl;
    cin>>n;
    g=0;
    x=1;
    b=n;
    t=0;

    while(!(b==1)){
        do{
            do{
                i=0;
                x++;
                y=0;

                do{
                    y++;
                    r[i]=x%y;
                    i++;
                }while(!(y==x));

                for(i=0;i<y;i++){
                    if(r[i]==0){ g++;}
                }
            }while(g!=g);

            R=b%x;
        }while(R!=0);

        esp=0;

        do{
            b=b/x;
            R=b%x;
            esp++;
        }while(R==0);

        a[t]=x;
        c[t]=esp;
        t++;
    }

    for(i=0;i!=t;i++){
        cout<<a[i]<<"^"<<c[i]<<endl;
    }

    return 0;
}
