//Giochi di carte
#include <iostream>
#include <fstream> 
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <string>
#include <algorithm>

using namespace std;

// struct
struct carte
{
    string tip;
	int num;
};

struct giocatore
{
    carte mano[3], mazzo[40];
	int punti; 
	string nome;
};

// mazzo
void mischia(carte y[40])
{
    int x[40], t;
    
    srand(time(NULL));
	for(int j=0; j<40 ;j++)
	{
        x[j]=(rand()%40);
        
	    for(int i=0; i<j ;i++)
	    {
	        while(x[i]==x[j])
	        {
                x[j]=(rand()%40);
                i=0;
	        }
	    }
	}
	
    for(int j=0;j<40;j++)
	{
	    t=floor(x[j]/10) + 1;
	    
	    switch (t)
        {
        case 1:
            y[j].tip="denari";
            break;

        case 2:
            y[j].tip="bastoni";
            break;

        case 3:
            y[j].tip="spade";
            break;

        case 4:
            y[j].tip="coppe";
            break;
        }
        
        y[j].num=x[j];
        
        while(y[j].num>10) y[j].num=y[j].num - 10;
        
        if(y[j].num==0) y[j].num=y[j].num + 10;
	}
}

void stampa(carte x[40], int n)
{
    cout<<"       numero  tipo"<<endl;
    for(int j=0; j<n ;j++)
	{
        cout<<j+1<<")   "<<x[j].num<<" di "<<x[j].tip<<endl;
	}
}


//MAIN
int main()
{
    giocatore g[4];
    carte c[40], terra[40], temp;
    int k, scelta, n, i=0, j=0, y=0, x=3, a=0, w, comb[40], D, M, Den[4][2], R[4][2], X1, tip, Som[4][1], COMB[40], MAX[40], maxx;
    int s=0, U=0, T=0, t=0, Mat[20][20], r[4]={0,0,0,0} , X=0, l=0, tm, den[4], tmp, W, set[4][5][10], vr[4], Xx, ss, pp, hh;
    bool k1, Dc, Mc, Vin, Max;
    string riga, S;
    
    //START
    do
    {
        cout<<" "<<endl;
        cout<<"hai scelto di giocare a SCOPA "<<endl;
        cout<<" "<<endl;
        
        //lettura dal file per recuperare i dati
        k=2;
        ifstream mioFile0("SCOPA.txt");
        if (mioFile0.is_open())
        {
            //vuoi riprendere
            k1=false;
            do
            {
                if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
                
                cout<<"Vuoi riprendere la partita precedente (1) o iniziarne una nuova (2) ?"<<endl;
                cin >> k;
                k1=true;
            }while(k<1 || k>2);
            if(k==1)
            {
                // ASSEGNAZIONE DELLE CARTE
                mioFile0>>n; //numero di giocatori
                for(int y=0; y<n; y++)
                { 
                    mioFile0>>g[y].nome>>x;
                    for(int h=0 ; h<x; h++) mioFile0>>g[y].mano[h].num>>g[y].mano[h].tip;
                    mioFile0>>r[y];
                    for(int h=0 ; h<r[y]; h++) mioFile0>>g[y].mazzo[h].num>>g[y].mazzo[h].tip;
                    mioFile0>>g[y].punti;
                }
                mioFile0.close();
                
                ifstream mioFile1 ("SCOPAterra.txt");
                mioFile1>>j; //numero di carte a terre
                for(int y=0; y<j+1; y++) mioFile1>>terra[y].num>>terra[y].tip;
                mioFile1.close();
                
                ifstream mioFile2 ("SCOPAmazzo.txt");
                mioFile2>>i; //numero di carte restanti nel mazzo
                for(int y=i; y<40; y++) mioFile2>>c[y].num>>c[y].tip;
                mioFile2.close();
            }
            else
            {
                mioFile0.close();
                
                //cancellazione dei file perche' non hai voluto riprendere la precedente partita
                remove("SCOPA.txt");
                remove("SCOPAmazzo.txt");
                remove("SCOPAterra.txt");
            }
        }
        if(k==2)
        {
            //REGOLAMENTO
            k1=false;
            do
            {
            if(k1==true) cout<<" Attenzione scelta sbargliata!!!! "<<endl;
            
            cout<<"Conosci il regolamento? 1 per SI, 2 per NO"<<endl;
            cin >> k;
            k1=true;
            }while(k<1 || k>2);
            if(k==2)
            {
                cout<<"  "<<endl;
                cout<<" REGOLAMENTO "<<endl;
                cout<<"  "<<endl;
                cout<<" Nel gioco di scopa al primo gioro vengono messe 4 carte a terra e ai giocatori vengono fornite "<<endl;
                cout<<" 3 carte a testa per ogni giro, che si conclude quando a entrambi i giocatori non restano piu' carte "<<endl;
                cout<<" che gli verranno nuovamente fornite dal banco."<<endl;
                cout<<" Nel gioco i giocatori usano le loro carte per poter prendere le carte a terra se con una presa"<<endl;
                cout<<" il giocatore non lascia piu caret a terra fa SCOPA ovvero 1 punto se non puo prendere nessuna cata"<<endl;
                cout<<" deve mettere una carta a terra, si fa punto anche avendo il 7 di denari, la settanta ovvero chi ha"<<endl;
                cout<<" un certo numero di carete che conseguono un punteggio, un altro punto per chi ha piu cate e un altro."<<endl;
                cout<<" per chi ha piu carte a denari. "<<endl;
                cout<<" Se a terra sono presenti carte superiori al 7 bisogna prenderle per forza anche se a terra ci sono care"<<endl;
                cout<<" piu' piccole che possono comporre quel numero."<<endl;
                cout<<"  "<<endl;
                cout<<"  "<<endl;
            }
            
            //MAZZO
            mischia(c);
            
            //GIOCATORI
            k1=false;
            do
            {
            cout<<" "<<endl;
            if(k1==true) cout<<" Attenzione scelta non contemplata!!!! "<<endl;
            
            cout<<"scegli il numero di giocatori: 2 ; 3 ; 4"<<endl;
            cin >> n;
            k1=true;
            }while(n<2 || n>4);
            cout<<" "<<endl;
            cout<<"ATTENZIONE!!!! se si vuole giocare non contro un altro giocatore ma contro"<<endl;
            cout<<"il computer bastera' inserire davanti al nome del giocatore il prefisso bot-"<<endl;
            cout<<" "<<endl;
            
            //NOMI
            for(int y=0 ; y<n; y++)
            {
                cout<<"inserisci il nome del giocatore "<<y+1<<":"<<endl;
                cin>>g[y].nome;
            }
            
            // PRIMA ASSEGNAZIONE DELLE CARTE 
            i=0;
            for(j=0 ; j<4; j++)
            {
                terra[j]=c[i];
                i++;
                for(int y=0 ; y<n; y++)
                {
                    g[y].mano[j]=c[i];
                    i++;
                }
            }
            
            // INIZIALIZZAZIONE PUNTI
            for(int y=0 ; y<n; y++)
            {
                g[y].punti=0;
            }
        }
        
        //GIOCO VERO E PROPIO
        do
        {
            Vin=false;
            
            // VIVO DEL GIOCO
            do
            {
                //TURNO
                for(int h=0 ; h<x; h++)
                {
                    for(int v=a ; v<n+a; v++)
                    {
                        if(v<n) w=v;
                        else w=v-n;
                        
                        // Estrazione della sottostringa delle prime 3 lettere
                        S = g[w].nome.substr(0, 3);
                        
                        // Conversione della sottostringa in minuscolo
                        transform(S.begin(), S.end(), S.begin(), ::tolower);
                        
                        // Controllo del bot
                        if (S == "bot") 
                        {
                            for(int y=0; y<40 ;y++)
                            {
                                MAX[y]=0;
                                COMB[y]=0;
                            }
                            
                            cout << " " << endl;
                            cout << " " << endl;
                            cout << g[w].nome << endl;
                            
                            //le carte della tua mano
                            cout<<" "<<endl;
                            cout<<" "<<endl;
                            cout<<" carte della mano del giocatore "<<w+1<<", "<<g[w].nome<<endl;
                            stampa( g[w].mano, x-h);
                            
                            // terra
                            cout<<" "<<endl;
                            cout<<"   carte a terra:"<<endl;
                            cout<<" "<<endl;
                            stampa( terra, j);
                            
                            
                            k1=false;
                            ss=0;
                            for(int hh=0; hh<=2-h; hh++)
                            {
                                //si puo prendere qualcosa?
                                Max=false;
                                s=0;
                                for(int y=0; y<j; y++)
                                {
                                    if(g[w].mano[hh].num == terra[y].num)
                                    {
                                        comb[s]=y;
                                        s++;
                                        comb[s]=40;
                                        s++;
                                        if(g[w].mano[hh].num>7) Max=true;
                                    }
                                }
                                if(g[w].mano[hh].num!=1 && Max==false)
                                {
                                    for(int o=0; o<j-1; o++)
                                    {
                                        for(int p=o+1; p<j; p++)
                                        {
                                            if(terra[p].num < g[w].mano[hh].num && terra[o].num < g[w].mano[hh].num)
                                            {
                                                if(g[w].mano[hh].num == terra[o].num+terra[p].num)
                                                {
                                                    comb[s]=o;
                                                    s++;
                                                    comb[s]=p;
                                                    s++;
                                                    comb[s]=40;
                                                    s++;
                                                }
                                                if(o>0 && terra[p].num+terra[o].num < g[w].mano[hh].num)
                                                {
                                                    U=0;
                                                    for(int u=0; u<o; u++) U = U + terra[u].num;
                                                    
                                                    if(g[w].mano[hh].num == U+terra[o].num+terra[p].num)
                                                    {
                                                        for(int u=0; u<o; u++)
                                                        {
                                                            comb[s]=u;
                                                            s++;
                                                        }
                                                        comb[s]=o;
                                                        s++;
                                                        comb[s]=p;
                                                        s++;
                                                        comb[s]=40;
                                                        s++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                comb[s]=40;
                                
                                if(comb[0]==40)
                                {
                                    COMB[ss]=40;
                                    ss++;
                                }
                                else // se si
                                {
                                    k1=true;
                                    //scelta della combinazione
                                    T=0;
                                    t=0;
                                    X=0;
                                    for(int y=0; X<2 ;y++)
                                    {
                                        Mat[T][t]=comb[y];
                                        if(comb[y]==40)
                                        {
                                            if(X==0)
                                            {
                                                MAX[T]=MAX[T]+(y*5);
                                                pp=0;
                                            }
                                            if(X==1)
                                            {
                                                MAX[T]=1000;
                                            }
                                            X++;
                                            T++;
                                            t=0;
                                            
                                        }
                                        else
                                        {
                                            if(terra[comb[y]].tip=="denari") pp=pp+3;
                                            if(terra[comb[y]].num==7) pp=pp+20;
                                            if(terra[comb[y]].num==6) pp=pp+6;
                                            if(terra[comb[y]].num==1) pp=pp+5;
                                            if(terra[comb[y]].num>1 && terra[comb[y]].num<6) pp=pp+2;
                                            
                                            MAX[T]=pp;
                                            
                                            terra[comb[y]];
                                            X=0;
                                            t++;
                                        }
                                    }
                                    
                                    if(y==0) k=1;
                                    else
                                    {
                                        for(int y=0; MAX[y]==1000 ;y++)
                                        {
                                            if(y==0 || MAX[y]>maxx) 
                                            {
                                                maxx=MAX[y];
                                                k=y;
                                            }
                                        }
                                    }
                                    
                                    k--;
                                    for(int y=0 ; Mat[k][y]!=40 ; y++)
                                    {
                                        COMB[ss]=Mat[k][y];
                                        ss++;
                                    }
                                    COMB[ss]=40;
                                    ss++;
                                }
                            }
                            COMB[ss]=80;
                            ss++;
                            if(k1==false)
                            {
                                terra[j]=g[w].mano[2-h];
                                j++;
                            }
                            else
                            {
                                //scelta della combinazione
                                T=0;
                                t=0;
                                X=0;
                                for(int y=0; COMB[y]!=80 ;y++)
                                {
                                    Mat[T][t]=COMB[y];
                                    if(COMB[y]==40)
                                    {
                                        if(y==0) MAX[T]=1;
                                        else if (COMB[y-1]==40) MAX[T]=1;
                                        else
                                        {
                                            MAX[T]=MAX[T]+(y*5);
                                            pp=0;
                                        }
                                        X++;
                                        T++;
                                        t=0;
                                    }
                                    else
                                    {
                                        if(terra[COMB[y]].tip=="denari") pp=pp+3;
                                        if(terra[COMB[y]].num==7) pp=pp+20;
                                        if(terra[COMB[y]].num==6) pp=pp+6;
                                        if(terra[COMB[y]].num==1) pp=pp+5;
                                        if(terra[COMB[y]].num>1 && terra[COMB[y]].num<6) pp=pp+2;
                                        
                                        MAX[T]=pp;
                                        
                                        terra[COMB[y]];
                                        X=0;
                                        t++;
                                    }
                                }
                                pp=0;
                                MAX[T]=1000;
                                
                                for(int y=0; MAX[y]!=1000 ;y++)
                                {
                                    if(y==0 || MAX[y]>maxx) 
                                    {
                                        maxx=MAX[y];
                                        k=y;
                                    }
                                }
                                
                                //tolgo dalla mano la carta scelta
                                if(k!=x-h)
                                {
                                    temp=g[w].mano[k];
                                    g[w].mano[k]=g[w].mano[2-h];
                                    g[w].mano[2-h]=temp;
                                }
                                
                                W=w;
                                g[w].mazzo[r[w]]=g[w].mano[2-h];
                                r[w]++;
                                
                                for( y=0 ; Mat[k][y]!=40 ; y++);
                                
                                for(int I=1; I<=y; I++)
                                {
                                    for(int J=1; J<=y-I; J++)
                                    {
                                        if(Mat[k][J-1]<Mat[k][J])
                                        {
                                            tm = Mat[k][J];
                                            Mat[k][J] = Mat[k][J-1];
                                            Mat[k][J-1] = tm;
                                        }
                                    }
                                }
                                
                                for(int y=0 ; Mat[k][y]!=40 ; y++)
                                {
                                    g[w].mazzo[r[w]]=terra[Mat[k][y]];
                                    r[w]++;
                                    
                                    j--;
                                    terra[Mat[k][y]]=terra[j];
                                }
                            }
                        }
                        else
                        {
                            //le carte della tua mano
                            cout<<" "<<endl;
                            cout<<" "<<endl;
                            cout<<" carte della mano del giocatore "<<w+1<<", "<<g[w].nome<<endl;
                            sleep(x-1);
                            stampa( g[w].mano, x-h);
                            
                            // terra
                            sleep(x-1);
                            cout<<" "<<endl;
                            cout<<"   carte a terra:"<<endl;
                            cout<<" "<<endl;
                            stampa( terra, j);
                            sleep(x-1);
                            
                            // scegli la carta della tua mano da mettere
                            k1=false;
                            do
                            {
                                if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
                                
                                cout<<" "<<endl;
                                cout<<" "<<endl;
                                cout<<"Quale carta tra quelle presenti nella tua mano vuoi usare?"<<endl;
                                cin >> k;
                                k1=true;
                            }while(k<1 || k>x-h);
                            
                            //tolgo dalla mano la carta scelta
                            if(k!=x-h)
                            {
                                temp=g[w].mano[k-1];
                                g[w].mano[k-1]=g[w].mano[2-h];
                                g[w].mano[2-h]=temp;
                            }
                            
                            //si puo prendere qualcosa?
                            Max=false;
                            s=0;
                            for(int y=0; y<j; y++)
                            {
                                if(g[w].mano[2-h].num == terra[y].num)
                                {
                                    comb[s]=y;
                                    s++;
                                    comb[s]=40;
                                    s++;
                                    if(g[w].mano[2-h].num>7) Max=true;
                                }
                            }
                            if(g[w].mano[2-h].num!=1 && Max==false)
                            {
                                for(int o=0; o<j-1; o++)
                                {
                                    for(int p=o+1; p<j; p++)
                                    {
                                        if(terra[p].num < g[w].mano[2-h].num && terra[o].num < g[w].mano[2-h].num)
                                        {
                                            if(g[w].mano[2-h].num == terra[o].num+terra[p].num)
                                            {
                                                comb[s]=o;
                                                s++;
                                                comb[s]=p;
                                                s++;
                                                comb[s]=40;
                                                s++;
                                            }
                                            if(o>0 && terra[p].num+terra[o].num < g[w].mano[2-h].num)
                                            {
                                                U=0;
                                                for(int u=0; u<o; u++) U = U + terra[u].num;
                                                
                                                if(g[w].mano[2-h].num == U+terra[o].num+terra[p].num)
                                                {
                                                    for(int u=0; u<o; u++)
                                                    {
                                                        comb[s]=u;
                                                        s++;
                                                    }
                                                    comb[s]=o;
                                                    s++;
                                                    comb[s]=p;
                                                    s++;
                                                    comb[s]=40;
                                                    s++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            comb[s]=40;
                            
                            if(comb[0]==40) // se no
                            {
                                terra[j]=g[w].mano[2-h];
                                j++;
                            }
                            else // se si
                            {
                                W=w;
                                g[w].mazzo[r[w]]=g[w].mano[2-h];
                                r[w]++;
                                
                                //scelta della combinazione
                                k1=false;
                                do
                                {
                                    if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
                                    cout<<" "<<endl;
                                    cout<<" "<<endl;
                                    cout<<"Con la carta scelta puoi prendere:"<<endl;
                                    cout<<" "<<endl;
                                    sleep(x-2);
                                    T=0;
                                    t=0;
                                    cout<<" "<<endl;
                                    cout<<"       numero  tipo"<<endl;
                                    //stampo le combinazioni
                                    X=0;
                                    for(int y=0; X<2 ;y++)
                                    {
                                        Mat[T][t]=comb[y];
                                        if(comb[y]==40)
                                        {
                                            X++;
                                            T++;
                                            t=0;
                                            cout<<" "<<endl;
                                            sleep(x-2);
                                        }
                                        else
                                        {
                                            if(t==0)cout<<T+1<<")   ";
                                            if(t>0)cout<<" + ";
                                            cout<<terra[comb[y]].num<<" di "<<terra[comb[y]].tip;
                                            terra[comb[y]];
                                            X=0;
                                            t++;
                                        }
                                    }
                                    if(y==0) k=1;
                                    else
                                    {
                                        cout<<"inserisci la tua scelta:"<<endl;
                                        cin >> k;
                                        k1=true;
                                    }
                                }while(k<1 || k>T+1);
                                
                                k--;
                                for( y=0 ; Mat[k][y]!=40 ; y++);
                                
                                for(int I=1; I<=y; I++)
                                {
                                    for(int J=1; J<=y-I; J++)
                                    {
                                        if(Mat[k][J-1]<Mat[k][J])
                                        {
                                            tm = Mat[k][J];
                                            Mat[k][J] = Mat[k][J-1];
                                            Mat[k][J-1] = tm;
                                        }
                                    }
                                }
                                
                                for(int y=0 ; Mat[k][y]!=40 ; y++)
                                {
                                    g[w].mazzo[r[w]]=terra[Mat[k][y]];
                                    r[w]++;
                                    
                                    j--;
                                    terra[Mat[k][y]]=terra[j];
                                }
                            }
                        }
                        
                        // SCOPA
                        if(j<=0)
                        {
                            sleep(x-2);
                            cout<<" "<<endl;
                            cout<<"SCOPAAAAAA !!!!!!!!! "<<endl;
                            cout<<" "<<endl;
                            sleep(x-2);
                            cout<<"HAI CONVALIDATO UN PUNTO !!!!!!! "<<endl;
                            cout<<" "<<endl;
                            g[w].punti++;
                        }
                    }
                }
                for(int y=0 ; y<10; y++) cout<<" "<<endl;
                
                
                //ASSEGNAZIONDE DELLE CARTE DOPO FINE TURNO
                if(i<40)
                {
                    for(int h=0 ; h<x; h++)
                    {
                        for(int y=0 ; y<n; y++)
                        {
                            i++;
                            g[y].mano[h]=c[i];
                        }
                    }
                }
                else
                {
                    for(int y=0 ; y<j ; y++)
                    {
                        g[W].mazzo[r[W]]=terra[y];
                        r[W]++;
                    }
                    j=0;
                }
                
                
                //SALVATAGGIO
                if(true)
                {
                    //scrivo nel file il valore di ogni cella
                    ofstream mioFilee0 ("SCOPA.txt");
                    mioFilee0<<n<<endl; //numero di giocatori
                    for(int y=0; y<n; y++)
                    { 
                        mioFilee0<<g[y].nome<<" "<<x<<" ";
                        for(int h=0 ; h<x; h++) mioFilee0<<g[y].mano[h].num<<" "<<g[y].mano[h].tip<<" ";
                        mioFilee0<<r[y]<<" ";
                        for(int h=0 ; h<r[y]; h++) mioFilee0<<g[y].mazzo[h].num<<" "<<g[y].mazzo[h].tip<<" ";
                        mioFilee0<<g[y].punti<<" "<<endl;
                    }
                    mioFilee0.close();
                    
                    ofstream mioFilee1 ("SCOPAterra.txt");
                    mioFilee1<<j<<endl; //numero di carte a terre
                    for(int y=0; y<j; y++) mioFilee1<<terra[y].num<<" "<<terra[y].tip<<" ";
                    mioFilee1.close();
                    
                    ofstream mioFilee2 ("SCOPAmazzo.txt");
                    mioFilee2<<i<<endl; //numero di carte restanti nel mazzo
                    for(int y=i; y<40; y++) mioFilee2<<c[y].num<<" "<<c[y].tip<<" ";
                    mioFilee2.close();
                }
                
            }while(i<40); 
            
            if(a<n) a++;
            else a=0;
            
            // Carte a lungo, di denari e 7 di denari
            for(int h=0 ; h<n; h++)
            {
                den[h]=0;
                for(int v=0 ; v<r[h]; v++)
                {
                    if(g[h].mazzo[v].tip=="denari")
                    {
                        den[h]++;
                        if(g[h].mazzo[v].num == 7 ) g[h].punti++;
                    }
                }
            }
            
            Mc=false;
            Dc=false;
            for(int h=0; h<=n; h++)
            {
                for(int v=1; v<=n-(h+1); v++)
                {
                    Den[h][0]=den[v];
                    if(Den[h][0]<den[v])
                    {
                        Den[h][0]=den[v];
                    }
                    
                    R[h][0]=r[v];
                    if(R[h][0]<r[v])
                    {
                        R[h][0]=r[v];
                    }
                }
                if(h>0)
                {
                    if(Den[h][0]>Den[h-1][0]) D=h;
                    
                    if(Den[h][0]==Den[h-1][0]) Dc=true;
                    
                    if(R[h][0]>R[h-1][0]) Mc=h;
                    
                    if(R[h][0]==R[h-1][0]) M=true;
                }
            }
            
            if(Dc==false) g[D].punti++;
            
            if(Mc==false) g[M].punti++;
            
            // 70
            for(int h=0; h<4; h++) 
            {
                vr[h]=0;
                Som[h][0]=0;
            }
            
            for(int h=0; h<n; h++)
            {
                for(int v=0; v<r[h]; v++)
                {
                    if(g[h].mano[v].tip=="denari")
                    {
                        tip=1;
                        if(g[h].mano[v].num==5 || g[h].mano[v].num==6 ||g[h].mano[v].num==7) set[h][tip][vr[tip]]=g[h].mano[v].num*3;
                        if(g[h].mano[v].num==1) set[h][tip][vr[tip]]=16;
                        if(g[h].mano[v].num==2 || g[h].mano[v].num==3 ||g[h].mano[v].num==4) set[h][tip][vr[tip]]=10+g[h].mano[v].num;
                        if(g[h].mano[v].num>7) set[h][tip][vr[tip]]=10;
                        vr[tip]++;
                        for(int I=1; I<=vr[tip]; I++)
                        {
                            for(int J=1; J<=vr[tip]-I; J++)
                            {
                                if(set[h][tip][J-1]<set[h][tip][J])
                                {
                                    X1=set[h][tip][J];
                                    set[h][tip][J]=set[h][tip][J-1];
                                    set[h][tip][J-1]=X1;
                                }
                            }
                        }
                    }
                    if(g[h].mano[v].tip=="bastoni")
                    {
                        tip=2;
                        if(g[h].mano[v].num==5 || g[h].mano[v].num==6 ||g[h].mano[v].num==7) set[h][tip][vr[tip]]=g[h].mano[v].num*3;
                        if(g[h].mano[v].num==1) set[h][tip][vr[tip]]=16;
                        if(g[h].mano[v].num==2 || g[h].mano[v].num==3 ||g[h].mano[v].num==4) set[h][tip][vr[tip]]=10+g[h].mano[v].num;
                        if(g[h].mano[v].num>7) set[h][tip][vr[tip]]=10;
                        vr[tip]++;
                        for(int I=1; I<=vr[tip]; I++)
                        {
                            for(int J=1; J<=vr[tip]-I; J++)
                            {
                                if(set[h][tip][J-1]<set[h][tip][J])
                                {
                                    X1=set[h][tip][J];
                                    set[h][tip][J]=set[h][tip][J-1];
                                    set[h][tip][J-1]=X1;
                                }
                            }
                        }
                    }
                    if(g[h].mano[v].tip=="spade")
                    {
                        tip=3;
                        if(g[h].mano[v].num==5 || g[h].mano[v].num==6 ||g[h].mano[v].num==7) set[h][tip][vr[tip]]=g[h].mano[v].num*3;
                        if(g[h].mano[v].num==1) set[h][tip][vr[tip]]=16;
                        if(g[h].mano[v].num==2 || g[h].mano[v].num==3 ||g[h].mano[v].num==4) set[h][tip][vr[tip]]=10+g[h].mano[v].num;
                        if(g[h].mano[v].num>7) set[h][tip][vr[tip]]=10;
                        vr[tip]++;
                        for(int I=1; I<=vr[tip]; I++)
                        {
                            for(int J=1; J<=vr[tip]-I; J++)
                            {
                                if(set[h][tip][J-1]<set[h][tip][J])
                                {
                                    X1=set[h][tip][J];
                                    set[h][tip][J]=set[h][tip][J-1];
                                    set[h][tip][J-1]=X1;
                                }
                            }
                        }
                    }
                    if(g[h].mano[v].tip=="coppe")
                    {
                        tip=4;
                        if(g[h].mano[v].num==5 || g[h].mano[v].num==6 ||g[h].mano[v].num==7) set[h][tip][vr[tip]]=g[h].mano[v].num*3;
                        if(g[h].mano[v].num==1) set[h][tip][vr[tip]]=16;
                        if(g[h].mano[v].num==2 || g[h].mano[v].num==3 ||g[h].mano[v].num==4) set[h][tip][vr[tip]]=10+g[h].mano[v].num;
                        if(g[h].mano[v].num>7) set[h][tip][vr[tip]]=10;
                        vr[tip]++;
                        for(int I=1; I<=vr[tip]; I++)
                        {
                            for(int J=1; J<=vr[tip]-I; J++)
                            {
                                if(set[h][tip][J-1]<set[h][tip][J])
                                {
                                    X1=set[h][tip][J];
                                    set[h][tip][J]=set[h][tip][J-1];
                                    set[h][tip][J-1]=X1;
                                }
                            }
                        }
                    }
                }
                for(int tip=1; tip<=4; tip++) Som[h][0]=Som[h][0]+set[h][tip][0];
                
                if(h==0) Xx=Som[h][0];
                if(Xx<Som[h][0]) Xx=Som[h][0];
            }
            
            for(int h=0; h<n; h++) if(Xx==Som[h][0]) g[h].punti++;
            
            // PUNTI
            for(int h=0 ; h<n; h++)
            {
                cout<<" "<<endl;
                cout<<"i punti totalizzati dal giocatore "<<h+1<<", "<<g[h].nome<<" sono: "<<endl;
                cout<<"  "<<g[h].punti<<" Punti"<<endl;
                cout<<" "<<endl;
            }
            
            // VINCITORE?
            for(int h=0 ; h<n; h++)
            {
                if(g[h].punti>=11)
                {
                    sleep(x-2);
                    cout<<" "<<endl;
                    cout<<"ABBIAMO UN VINCITOREEEE !!!!!!!!! "<<endl;
                    cout<<" "<<endl;
                    sleep(x-2);
                    cout<<"CON UN TOTALE DI "<<g[h].punti<<" PUNTI "<<endl;
                    cout<<" "<<endl;
                    cout<<"IL GIOCATORE "<<h+1<<", "<<g[h].nome<<" VINCEEEEEEE !!!!!!!!! "<<endl;
                    Vin=true;
                    break;
                }
            }
            
            if(Vin==false) 
            {
                for(int y=0 ; y<n; y++) r[y]=0;
                
                // CREAZIONE DEL MAZZO
                mischia(c);
                
                i=0;
                for(j=0 ; j<4; j++)
                {
                    terra[j]=c[i];
                    i++;
                    for(int y=0 ; y<n; y++)
                    {
                        g[y].mano[j]=c[i];
                        i++;
                    }
                }
            }
            
        }while(Vin==false);
        
        //cancellazione dei file perche' la partita e' finita
        remove("SCOPA.txt");
        remove("SCOPAmazzo.txt");
        remove("SCOPAterra.txt");
        
        
        //RESTART se si vincitore
        k1=false;
        do
        {
            if(k1==true) cout<<"Attenzione scelta sbargliata!!!!"<<endl;
            
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"Vuoi giocare una nuova partita? 1 per SI, 2 per NO"<<endl;
            cin >> k;
            k1=true;
        }while(k<1 || k>3);
        
    }while(k==1);
    
    if(k==3)
    {
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"Stai per scoprire una verita' nascosta di questo gioco ovvero che...."<<endl;
        cout<<"Ora la notizia negativa e' che hai perso tempo prezioso della tua vita a giocare a questo gioco"<<endl;
        cout<<"Ma la notizia positiva e' che non ne hai perso tanto quanto chi ha programmato sta roba qua"<<endl;
    }
    
    return 0;
}














