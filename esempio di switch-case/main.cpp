#include <iostream>

using namespace std;

int main()
{
    char scelta;

    do
    {

    cout<<"1) funzionalita' uno "<<endl;
    cout<<"2) funzionalita' due "<<endl;
    cout<<"3) funzionalita' tre "<<endl;
    cout<<"4) funzionalita' quattro "<<endl;

    cout<<"Inserisci scelta [1-4]:"<<endl;
    cin>>scelta;


    switch (scelta)
        {
        case '1':
            cout<<"Hai scelto la funzionalita' uno!!!"<<endl;
            break;

        case '2':
            cout<<"Hai scelto la funzionalita' due!!!"<<endl;
            break;

        case '3':
            cout<<"Hai scelto la funzionalita' tre!!!"<<endl;
            break;

        case '4':
            cout<<"Hai scelto la funzionalita' quattro!!!"<<endl;
            break;

        default:
            cout<<"Attenzione scelta sbagliata!!!!!"<<endl;
        }

    }
    while(scelta<'1' || scelta>'4');

    return 0;
}
