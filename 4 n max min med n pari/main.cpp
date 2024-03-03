#include <iostream>

using namespace std;

//FUNZIONE
int max(int a,int b,int c,int d)
{
    int x=0,y=0,z=0;
    if(a>b)
		{
			x=a;
		}
	else
		{
			x=b;
		}
	if(c>d)
		{
			y=c;
		}
	else
		{
			y=d;
		}
	if(x>y)
		{
			z=x;
		}
	else
		{
			z=y;
		}
	return z;
}
 
//FUNZIONE
int min(int a,int b,int c,int d)
{
    int x=0,y=0,z=0;
    if(a<b)
		{
			x=a;
		}
	else
		{
			x=b;
		}
	if(c<d)
		{
			y=c;
		}
	else
		{
			y=d;
		}
	if(x<y)
		{
			z=x;
		}
	else
		{
			z=y;
		}
	return z;
}

//FUNZIONE
int med(int a,int b,int c,int d)
{
    int z=0;
    z=(a+b+c+d)/4;
	return z;
}

//FUNZIONE
int pari(int a,int b,int c,int d)
{
    int z=0;
    if(a%2==0)
		{
			z++;
		}
    if(b%2==0)
		{
			z++;
		}
	if(c%2==0)
		{
			z++;
		}
	if(d%2==0)
		{
			z++;
		}
	return z;
}

//FUNZIONE
void coso()
{ 
    cout<<"    *********   "<<endl;
    cout<<"  *           * "<<endl;
    cout<<" *  O       O  *"<<endl;
    cout<<"  *     –     * "<<endl;
    cout<<"    *********   "<<endl;
    return ;
}

//MAIN
int main()
{
    int a,b,c,d,x;
    cout<<"inserisci i 4 numeri uno per volta:"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    
    x=max(a,b,c,d);
    cout<<"il numero maggiore e :"<<x<<endl;
    x=min(a,b,c,d);
    cout<<"il numero minore e :"<<x<<endl;
    x=med(a,b,c,d);
    cout<<"il numero medio e :"<<x<<endl;
    x=pari(a,b,c,d);
    cout<<"i numeri pari sono :"<<x<<endl;
    
    coso();

    return 0;
}
