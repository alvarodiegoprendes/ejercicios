#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
int main()
{
    char palabra[10];
    int longitud = 0;
    cout << "digite una cadena de caracteres ";
    cin.getline(palabra, 100, '\n');
    longitud = strlen(palabra);
    if (longitud > 10)
    {
        cout << "el numero de elemtos de la cadena es " << longitud;
    }
    else
    {
        cout << "ingrese mas caracteres";
    }

    getch();
    return 0;
}
