#include <iostream>

using namespace std;

int main()
{
    int mat[3][5], x=0, i, j;
    for(i=0; i<3; i++)
    {
        cout << " --------------" << endl;
        for(j=0; j<5; j++)
        {
            mat[i][j]=++x;
            cout << "|" << mat[i][j];

            if(x<10)
            {
                cout << " ";
            }

        }
        cout << "|" << endl;
    }
     cout << " --------------" << endl;


    for(i=0; i<2; i++)
    {
        for(j=0; j<5; j++)
        {
            x=mat[2-i][4-j];
            mat[2-i][4-j]=mat[i][j];
            mat[i][j]=x;
        }
    }

    cout << "" << endl;
    cout << "" << endl;

    for(i=0; i<3; i++)
    {
        cout << " --------------" << endl;
        for(j=0; j<5; j++)
        {
            cout << "|" << mat[i][j];
            if(mat[i][j]<10)
            {
                cout << " ";
            }

        }
        cout << "|" << endl;
    }
     cout << " --------------" << endl;

    return 0;
}
