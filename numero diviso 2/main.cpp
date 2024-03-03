#include <iostream>

using namespace std;

int n,r;
int main()
{
    cout <<"inserisci n"<< endl;
    cin>>n;

    r=n%2;
    n=n/2;

    if(r=1)
    {
        n=n+0.5;
    }

    cout <<n<<endl;

    return 0;
}
