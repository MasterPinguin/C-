#include <iostream>

using namespace std;

int a,b;
int main()
{
    cout << "inserire a" << endl;
    cin >> a;
    cout << "inserire b" << endl;
    cin >> b;

    if(a=b)
    {
        cout <<"a e uguale a b"<< endl;
    }
    else
    {
        if(a>b)
        {
            cout <<"a maggiore di b"<<endl;
        }
        else
        {
            cout <<"b maggiore di a"<<endl;
        }
    }
    return 0;
}
