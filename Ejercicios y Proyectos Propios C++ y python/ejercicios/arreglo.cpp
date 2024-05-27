#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int almacen = 9999;
    int t;
    int numeros[100], *dirnumero;
    cout << "digite el numero de elemntos del arreglo: " << endl;
    cin >> t;
    // rellendando arreglo
    for (int i = 0; i < t; i++)
    {

        cout << "digite los numeros del arreglo: " << i << endl;
        cin >> numeros[i];
    }
    // imprimiendo arreglo
    for (int i = 0; i < t; i++)
    {
        cout << " los numeros son: " << numeros[i] << endl;
    }

    // imprimiendo menor numero
    dirnumero = numeros;
    for (int i = 0; i < t; i++)
    {
        if (*dirnumero < almacen)
        {
            almacen = *dirnumero;
        }
        dirnumero++;
    }

    cout << "\nel menor numero es: " << almacen << endl;

    getch();
    return 0;
}