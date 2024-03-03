//esempio che genera 20 numeri casuali nell'intervallo da 1 a 10
#include<iostream>
#include<cstdlib>
#include<math.h>
#include<ctime>

using namespace std;

main()
{
	int x;

	srand(time(NULL)); //Inizializzageneratore di numeri casuali

	for(int i=0; i<20; i++)
		{
			x=(rand()%10)+1;
			cout<< x <<endl;
		}

	system("pause");
	return 0;

}