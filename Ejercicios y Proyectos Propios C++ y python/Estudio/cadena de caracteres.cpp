#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

void pedir_datos();
char oracion[30];
void cant_vocales(char *);

int main()
{
    pedir_datos();
    cant_vocales(oracion);
    getch();
    return 0;
}

void pedir_datos()
{

    cout << "digite la oracion que desee para saber la cantidad de vocales que posee: "<<endl;
    cin.getline(oracion, 30, '\n');
}
void cant_vocales(char *oracion)
{

    strupr(oracion); 
    int A = 0, E = 0, I = 0, O = 0, U = 0;

    while(*oracion){
        switch (*oracion)
        {
        case 'A':
            A++;
            break;
            case 'E':
            E++;
            break;
            case 'I':
            I++;
            break;
            case 'O':
            O++;
            break;
            case 'U':
            U++;
            break;
        
        }
        oracion++;

    }
    cout<<"\nNumero de vocales A: "<<A<<endl;
	cout<<"Numero de vocales E: "<<E<<endl;
	cout<<"Numero de vocales I: "<<I<<endl;
	cout<<"Numero de vocales O: "<<O<<endl;
	cout<<"Numero de vocales U: "<<U<<endl;
}
