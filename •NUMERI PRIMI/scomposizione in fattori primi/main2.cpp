#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double n,x,R,esp;
int main()
{
    cout << "inserire numero da scomporre in fattori primi: " << endl;
    cin>>n;
    x=1;
    
    while(n!=1){
        do{
            x++;
            R=fmod(n, x);
        }while(R!=0);
        
        esp=0;
        
        do{
            n=n/x;
            R=fmod(n, x);
            esp++;
        }while(R==0);
        
        cout << fixed << setprecision(0);
        
        cout<<x<<"^"<<esp<<endl;
    }
    return 0;
}