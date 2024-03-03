/*
 Data l'altezza e il peso di uno studente, calcolare l'IMC ( = Peso/(Altezza*Altezza) ).

   Visualizzare successivamente a video i seguenti esiti:



	1. 	IMC<20 		 --> SOTTOPESO

	2. 	20 <= IMC <= 25  --> NORMOPESO

	3.  	25 < IMC <= 35   --> SOVRAPPESO

	4. 	IMC >35 	 --> OBESO
*/
#include <iostream>

using namespace std;

float peso,altezza,IMC;
int main()
{
    cout << "inserisci la tua altezza" << endl;
    cin>>altezza;
    cout << "inserisci il tuo peso" << endl;
    cin>>peso;

    IMC= peso/(altezza*altezza);

    if(IMC<20)
    {
        cout<<"SOTTOPESO"<<endl;
    }
    else
    {
        if(IMC<=25)
        {
           cout<<"NORMOPESO"<<endl;
        }
        else
        {
            if(IMC<=35)
            {
                cout<<"SOVRAPPESO"<<endl;
            }
            else
            {
                cout<<"OBESO"<<endl;
            }
        }
    }
    return 0;
}
