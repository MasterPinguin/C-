/*TRIS*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//FUNZIONE
void out(char m [3][3])
{
    int x,y;
    cout<<" "<<endl;
    for(x=0; x<3; x++)
    {
        cout<<"  ";
        for(y=0; y<3; y++)
        {
            cout<<m [x][y];
            if(y!=2)
            {
                cout<<" | ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<" "<<endl;
        if(x!=2)
        {
            cout<<" -----------"<<endl;
        }
        else
        {
            cout<<" "<<endl;
        }
    }
    return;
}

//FUNZIONE
int Win(char m [3][3])
{
    int x,y;
    int v=0;

    //controllo colonne
    for(x=0; x<3; x++)
    {
        if(m[x][0]!=' ' && m[x][0]==m[x][1] && m[x][1]==m[x][2])
        {
            v=m[x][0];
        }
     }

    //controllo righe
    for(y=0; y<3; y++)
    {
        if (m[0][y]!=' ' && m[0][y]==m[1][y] && m[1][y]==m[2][y])
        {
            v=m[0][y];
        }
    }

    //controllo diagonali
    if(m[0][0]!=' ' && m[0][0]==m[1][1] && m[1][1]==m[2][2])
    {
        v=m[0][0];
    }
    else if (m[0][2]!=' ' && m[0][2]==m[1][1] && m[1][1]==m[2][0])
    {
        v=m[0][2];
    }

    //1 se ha vinto X, 2 se ha vinto O, 0 se ne X ne O
    if (v=='X' || v=='O')
    {
        if (v=='X')
        {
            v=1;
        }
        else
        {
            v=2;
        }
    }

    return v;
}

//FUNZIONE
int W(int v)
{

    switch(v)
                {
                case 2:
                    cout<<"VINCE IL GIOCATORE O"<<endl;
                    break;
                case 1:
                    cout<<"VINCE IL GIOCATORE X"<<endl;
                    break;
                case 0:
                    cout<<"NE VINTI NE VINCITORI PAREGGIO"<<endl;
                    break;
                }
    return 0;
}

//MAIN
int main()
{
    int scelta, v=0, i, j, g=0, G, x, y, c=1, t, m=0;
    char mat[3][3];

    do
    {
        cout<<"___  __   .   __"<<endl;
        cout<<" |   |_)  |  (_"<<endl;
        cout<<" |   | \\  |  __)"<<endl;
        cout<<" "<<endl;
        cout<<"INSERISCI SCELTA DI GIOCO "<<endl;
        cout<<"1-DUE GIOCATORI "<<endl;
        cout<<"2-GIOCATORE SINGOLO-MODALITA' EASY"<<endl;
        cout<<"3-GIOCATORE SINGOLO-MODALITA' HARD"<<endl;
        cout<<"4-GIOCATORE SINGOLO-MODALITA' IMPOSSIBILE"<<endl;
        cout<<"0-ESCI "<<endl;
        cin>>scelta;

        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                mat[i][j]= ' ';
            }
        }
        v=0;
        g=0;

        switch (scelta)
        {
        case 1:
            cout<<"INIZIO PARTITA A DUE GIOCATORI "<<endl;
            for(i=1; i<=9 && v==0 ; i++)
            {
                    G=(g)%2;
                    out(mat);

                    do
                    {
                        cout<<"Giocatore";
                        if(G==0)
                        {
                            cout<<'O'<<endl;
                        }
                        else
                        {
                            cout<<'X'<<endl;
                        }
                        cout<<"Inserisci il numero della cella da 1 a 9:"<<endl;
                        cin>>x;
                    }
                    while(x>9 && x<1);

                    if(x<=3)
                    {
                        y=x-1;
                        if(mat[0][y]!=' ')
                        {
                            cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                            c=0;
                        }
                    }
                    if(x<=6 && x>=4)
                    {
                        y=x-4;
                        if(mat[1][y]!=' ')
                        {
                            cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                            c=0;
                        }
                    }
                    if(x<=9 && x>6)
                    {
                        y=x-7;
                        if(mat[2][y]!=' ')
                        {
                            cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                            c=0;
                        }
                    }
                    if(c==1)
                    {
                        if(G==0)
                        {
                            if(x<=3)
                            {
                                y=x-1;
                                mat[0][y]='O';
                            }
                            if(x<=6 && x>3)
                            {
                                y=x-4;
                                mat[1][y]='O';
                            }
                            if(x<=9 && x>6)
                            {
                                y=x-7;
                                mat[2][y]='O';
                            }
                            g++;
                        }
                        else
                        {
                            if(x<=3)
                            {
                                y=x-1;
                                mat[0][y]='X';
                            }
                            if(x<=6 && x>=4)
                            {
                                y=x-4;
                                mat[1][y]='X';
                            }
                            if(x<=9 && x>6)
                            {
                                y=x-7;
                                mat[2][y]='X';
                            }
                            g++;
                        }
                    }
                    c=1;

                    if(g>4)
                    {
                        v=Win(mat);
                    }
                }
            out(mat);
            W(v);
            break;

        case 2:
            cout<<"INIZIO PARTITA A GIOCATORE SINGOLO-MODALITA' EASY"<<endl;
            for(j=0; j<9 && v==0 ; j++)
            {
                    G=(g)%2;

                    srand(time(NULL));

                    if(G==0)
                    {
                        out(mat);
                        do
                        {
                            cout<<"Giocatore X :"<<endl;
                            cout<<"Inserisci il numero della cella da 1 a 9:"<<endl;
                            cin>>x;
                        }
                        while(x>9 && x<1);

                        if(x<=3)
                        {
                            y=x-1;
                            if(mat[0][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=6 && x>=4)
                        {
                            y=x-4;
                            if(mat[1][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=9 && x>6)
                        {
                            y=x-7;
                            if(mat[2][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(c==1)
                        {
                            if(x<=3)
                            {
                                y=x-1;
                                mat[0][y]='X';
                            }
                            if(x<=6 && x>=4)
                            {
                                y=x-4;
                                mat[1][y]='X';
                            }
                            if(x<=9 && x>6)
                            {
                                y=x-7;
                                mat[2][y]='X';
                            }
                            g++;
                        }
                        c=1;
                    }
                    else
                    {
                        //ALGORITMO INTELIGENTE
                        t=0;
                        srand(time(NULL));

                        if(j==1)
                        {
                           if(mat[1][1]=='X')
                           {
                               do
                                {
                                    x=(rand())%3;
                                    y=(rand())%3;
                                }
                                while(mat[x][y]!=' ' && (mat[x][y]!=mat[0][0] && mat[x][y]!=mat[0][2] && mat[x][y]!=mat[2][0] && mat[x][y]!=mat[2][2]));
                           }
                           else
                           {
                               x=1;
                               y=1;
                           }
                        }
                        else
                        {
                            for(i=0; i<3; i++)
                            {
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][1] && mat[i][2]==' ')
                                {
                                    x=i;
                                    y=2;
                                }
                                if(mat[i][1]!=' ' && mat[i][1]==mat[i][2] && mat[i][0]==' ')
                                {
                                    x=i;
                                    y=0;
                                }
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][2] && mat[i][1]==' ')
                                {
                                    x=i;
                                    y=1;
                                }
                            }
                            for(i=0; i<3; i++)
                            {
                                if(mat[0][i]!=' ' && mat[0][i]==mat[1][i] && mat[2][i]==' ')
                                {
                                    x=2;
                                    y=i;
                                }
                                if(mat[1][i]!=' ' && mat[1][i]==mat[2][i] && mat[0][i]==' ')
                                {
                                    x=0;
                                    y=i;
                                }
                                if(mat[0][i]!=' ' && mat[0][i]==mat[2][i] && mat[1][i]==' ')
                                {
                                    x=1;
                                    y=i;
                                }
                            }

                            if(mat[0][0]!=' ' && mat[0][0]==mat[1][1] && mat[2][2]==' ')
                            {
                                x=2;
                                y=2;
                            }
                            if(mat[1][1]!=' ' && mat[1][1]==mat[2][2] && mat[0][0]==' ')
                            {
                                x=0;
                                y=0;
                            }
                            if(mat[2][2]!=' ' && mat[2][2]==mat[0][0] && mat[1][1]==' ')
                            {
                                x=1;
                                y=1;
                            }

                            if(mat[0][2]!=' ' && mat[0][2]==mat[1][1] && mat[2][0]==' ')
                            {
                                x=2;
                                y=0;
                            }
                            if(mat[2][0]!=' ' && mat[1][1]==mat[2][0] && mat[0][2]==' ')
                            {
                                x=0;
                                y=2;
                            }
                            if(mat[0][2]!=' ' && mat[0][2]==mat[2][0] && mat[1][1]==' ')
                            {
                                x=1;
                                y=1;
                            }
                        }
                        if(x==99 && y==99)
                        {
                           do
                            {
                                x=(rand())%3;
                                y=(rand())%3;
                            }
                            while(mat[x][y]!=' ');
                        }

                        mat[x][y]='O';
                        g++;
                        }

                    if(g>4)
                    {
                        v=Win(mat);
                    }
                    x=99;
                    y=99;
            }
            out(mat);
            W(v);
            break;

        case 3:
            cout<<"INIZIO PARTITA A GIOCATORE SINGOLO-MODALITA' HARD"<<endl;
            for(j=0; j<9 && v==0 ; j++)
            {
                    G=(g)%2;

                    srand(time(NULL));

                    if(G==0)
                    {
                        out(mat);
                        do
                        {
                            cout<<"Giocatore X :"<<endl;
                            cout<<"Inserisci il numero della cella da 1 a 9:"<<endl;
                            cin>>x;
                        }
                        while(x>9 && x<1);

                        if(x<=3)
                        {
                            y=x-1;
                            if(mat[0][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=6 && x>=4)
                        {
                            y=x-4;
                            if(mat[1][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=9 && x>6)
                        {
                            y=x-7;
                            if(mat[2][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(c==1)
                        {
                            if(x<=3)
                            {
                                y=x-1;
                                mat[0][y]='X';
                            }
                            if(x<=6 && x>=4)
                            {
                                y=x-4;
                                mat[1][y]='X';
                            }
                            if(x<=9 && x>6)
                            {
                                y=x-7;
                                mat[2][y]='X';
                            }
                            g++;
                        }
                        c=1;
                    }
                    else
                    {
                        //ALGORITMO INTELIGENTE
                        t=0;
                        srand(time(NULL));

                        if(j==1)
                        {
                           if(mat[1][1]=='X')
                           {
                               do
                                {
                                    x=(rand())%3;
                                    y=(rand())%3;
                                }
                                while(mat[x][y]!=' ' && (mat[x][y]!=mat[0][1] && mat[x][y]!=mat[1][0] && mat[x][y]!=mat[1][2] && mat[x][y]!=mat[2][1]));
                           }
                           else
                           {
                               x=1;
                               y=1;
                           }
                        }
                        else
                        {
                            for(i=0; i<3; i++)
                            {
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][1] && mat[i][2]==' ')
                                {
                                    x=i;
                                    y=2;
                                }
                                if(mat[i][1]!=' ' && mat[i][1]==mat[i][2] && mat[i][0]==' ')
                                {
                                    x=i;
                                    y=0;
                                }
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][2] && mat[i][1]==' ')
                                {
                                    x=i;
                                    y=1;
                                }
                            }
                            for(i=0; i<3; i++)
                            {
                                if(mat[0][i]!=' ' && mat[0][i]==mat[1][i] && mat[2][i]==' ')
                                {
                                    x=2;
                                    y=i;
                                }
                                if(mat[1][i]!=' ' && mat[1][i]==mat[2][i] && mat[0][i]==' ')
                                {
                                    x=0;
                                    y=i;
                                }
                                if(mat[0][i]!=' ' && mat[0][i]==mat[2][i] && mat[1][i]==' ')
                                {
                                    x=1;
                                    y=i;
                                }
                            }

                            if(mat[0][0]!=' ' && mat[0][0]==mat[1][1] && mat[2][2]==' ')
                            {
                                x=2;
                                y=2;
                            }
                            if(mat[1][1]!=' ' && mat[1][1]==mat[2][2] && mat[0][0]==' ')
                            {
                                x=0;
                                y=0;
                            }
                            if(mat[2][2]!=' ' && mat[2][2]==mat[0][0] && mat[1][1]==' ')
                            {
                                x=1;
                                y=1;
                            }

                            if(mat[0][2]!=' ' && mat[0][2]==mat[1][1] && mat[2][0]==' ')
                            {
                                x=2;
                                y=0;
                            }
                            if(mat[2][0]!=' ' && mat[1][1]==mat[2][0] && mat[0][2]==' ')
                            {
                                x=0;
                                y=2;
                            }
                            if(mat[0][2]!=' ' && mat[0][2]==mat[2][0] && mat[1][1]==' ')
                            {
                                x=1;
                                y=1;
                            }
                        }
                        if(x==99 && y==99)
                        {
                           do
                            {
                                x=(rand())%3;
                                y=(rand())%3;
                            }
                            while(mat[x][y]!=' ');
                        }

                        mat[x][y]='O';
                        g++;
                        }

                    if(g>4)
                    {
                        v=Win(mat);
                    }
                    x=99;
                    y=99;
            }
            out(mat);
            W(v);
            break;

        case 4:
            cout<<"INIZIO PARTITA A GIOCATORE SINGOLO-MODALITA' IMPOSSIBILE"<<endl;
            for(j=0; j<9 && v==0 ; j++)
            {
                    G=(g)%2;

                    srand(time(NULL));

                    if(G==0)
                    {
                        out(mat);
                        do
                        {
                            cout<<"Giocatore X :"<<endl;
                            cout<<"Inserisci il numero della cella da 1 a 9:"<<endl;
                            cin>>x;
                        }
                        while(x>9 && x<1);

                        if(x<=3)
                        {
                            y=x-1;
                            if(mat[0][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=6 && x>=4)
                        {
                            y=x-4;
                            if(mat[1][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(x<=9 && x>6)
                        {
                            y=x-7;
                            if(mat[2][y]!=' ')
                            {
                                cout<<"c'e' gia' un elemento nella cella. inserisci nuove coordinate:"<<endl;
                                c=0;
                            }
                        }
                        if(c==1)
                        {
                            if(x<=3)
                            {
                                y=x-1;
                                mat[0][y]='X';
                            }
                            if(x<=6 && x>=4)
                            {
                                y=x-4;
                                mat[1][y]='X';
                            }
                            if(x<=9 && x>6)
                            {
                                y=x-7;
                                mat[2][y]='X';
                            }
                            g++;
                        }
                        c=1;
                    }
                    else
                    {
                        //ALGORITMO INTELIGENTE
                        t=0;
                        srand(time(NULL));

                        if(j==1)
                        {
                           if(mat[1][1]!=' ')
                           {
                               do
                                {
                                    x=(rand())%3;
                                    y=(rand())%3;
                                }
                                while(mat[x][y]!=mat[0][1] && mat[x][y]!=mat[1][0] && mat[x][y]!=mat[1][2] && mat[x][y]!=mat[2][1]);
                           }
                           else
                           {
                               x=1;
                               y=1;
                           }
                        }
                        else
                        {
                            for(i=0; i<3; i++)
                            {
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][1] && mat[i][2]==' ' && m==0)
                                {
                                    x=i;
                                    y=2;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                                if(mat[i][1]!=' ' && mat[i][1]==mat[i][2] && mat[i][0]==' ' && m==0)
                                {
                                    x=i;
                                    y=0;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                                if(mat[i][0]!=' ' && mat[i][0]==mat[i][2] && mat[i][1]==' ' && m==0)
                                {
                                    x=i;
                                    y=1;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                            }
                            for(i=0; i<3; i++)
                            {
                                if(mat[0][i]!=' ' && mat[0][i]==mat[1][i] && mat[2][i]==' ' && m==0)
                                {
                                    x=2;
                                    y=i;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                                if(mat[1][i]!=' ' && mat[1][i]==mat[2][i] && mat[0][i]==' ' && m==0)
                                {
                                    x=0;
                                    y=i;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                                if(mat[0][i]!=' ' && mat[0][i]==mat[2][i] && mat[1][i]==' ' && m==0)
                                {
                                    x=1;
                                    y=i;
                                    if(x!=99 && y!=99 && mat[x][y]=='O')
                                    {
                                        m=1;
                                    }
                                }
                            }

                            if(mat[0][0]!=' ' && mat[0][0]==mat[1][1] && mat[2][2]==' ' && m==0)
                            {
                                x=2;
                                y=2;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }
                            if(mat[1][1]!=' ' && mat[1][1]==mat[2][2] && mat[0][0]==' ' && m==0)
                            {
                                x=0;
                                y=0;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }
                            if(mat[2][2]!=' ' && mat[2][2]==mat[0][0] && mat[1][1]==' ' && m==0)
                            {
                                x=1;
                                y=1;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }

                            if(mat[0][2]!=' ' && mat[0][2]==mat[1][1] && mat[2][0]==' ' && m==0)
                            {
                                x=2;
                                y=0;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }
                            if(mat[2][0]!=' ' && mat[1][1]==mat[2][0] && mat[0][2]==' ' && m==0)
                            {
                                x=0;
                                y=2;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }
                            if(mat[0][2]!=' ' && mat[0][2]==mat[2][0] && mat[1][1]==' ' && m==0)
                            {
                                x=1;
                                y=1;
                                if(x!=99 && y!=99 && mat[x][y]=='O')
                                {
                                    m=1;
                                }
                            }
                        }
                        if(x==99 && y==99)
                        {
                           do
                            {
                                x=(rand())%3;
                                y=(rand())%3;
                            }
                            while(mat[x][y]!=' ' && (mat[x][y]!=mat[0][0] && mat[x][y]!=mat[0][2] && mat[x][y]!=mat[2][0] && mat[x][y]!=mat[2][2]));
                        }

                        mat[x][y]='O';
                        g++;
                        m=0;
                        }

                    if(g>4)
                    {
                        v=Win(mat);
                    }
                    x=99;
                    y=99;
            }
            out(mat);
            W(v);
            break;

        default:
            cout<<"SCELTA INESISTENTE INSERISCI UN OPSIONE VALIDA"<<endl;
        }

        if(scelta==1 || scelta==2)
        {
            cout<<"5-RIVINCITA"<<endl;
            cout<<"0-ESCI"<<endl;
            cin>>scelta;
        }

    }
    while(scelta!=0 || scelta==5);

    return 0;
}

