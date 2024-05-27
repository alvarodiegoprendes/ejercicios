#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
int main()
{
    char cadena1[100];
    char cadena2[100];
    cout << "digite una cadena de caracteres: ";
    cin.getline(cadena1, 20, '\n');
    cout << "digite otra cadena de caracteres: ";
    cin.getline(cadena2, 20, '\n');
    if (strcmp(cadena1, cadena2) == 0)
    {
        cout << "ambas cadenas son iguales";
    }
    else if (strcmp(cadena1, cadena2) > 0)
    {
        cout << cadena1 << " es superior alfabeticamente que " << cadena2;
    }
    else
    {
        cout << cadena2 << " es superior alfabeticamente que " << cadena1;
    }
    getch();
    return 0;
}