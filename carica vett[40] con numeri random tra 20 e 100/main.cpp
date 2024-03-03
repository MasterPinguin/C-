//caricamento di un vettore di 40 elementi
//con numeri casuali compresi nel range da 20 a 100
#include<iostream>
#include<cstdlib>
#include<math.h>
#include<ctime>

using namespace std;

main()
{
	int V[40],i;  //dichiarazione del vettore

	srand(time(NULL)); //Inizializza generatore di numeri casuali

	//caricamento elementi del vettore
	for( i=0; i<40; i++)
		{
			V[i]=(rand()%81)+20;
		}

	//visualizza elementi del vettore
		for( i=0; i<40; i++)
		{
			cout<<V[i] <<"\t";
		}
	cout<<endl;
	system("pause");
	return 0;

}
