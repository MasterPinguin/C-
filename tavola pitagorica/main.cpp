/*
Costruire la tavola pitagorica per i numeri da 0 a 10.
*/

#include <iostream>

using namespace std;

int main()
{
    int mat[11][11];

    for(int i=0 ; i<=10 ; i++)
    {
        for(int j=0 ; j<=10 ; j++)
        {
            mat[i][j]=i*j;
            cout<<mat[i][j]<<" ";
            if(mat[i][j]<10)
            {
                cout<<"  ";
            }
            if(mat[i][j]>=10 && mat[i][j]<100)
            {
                cout<<" ";
            }
        }
        cout<<" "<<endl;
        cout<<" "<<endl;
    }


    return 0;
}
