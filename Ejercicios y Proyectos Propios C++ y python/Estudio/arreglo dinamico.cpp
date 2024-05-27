#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void entrar_arreglo();
void buscar_numero(int *, int);

int tamano, *arreglo;

int main()
{
    entrar_arreglo();
    buscar_numero(arreglo, tamano);
    delete[] arreglo;
    getch();
    return 0;
}

void entrar_arreglo()
{
    arreglo = new int[tamano];
    cout << "ingrese el tamano del arreglo: ";
    cin >> tamano;
    for (int i = 0; i < tamano; i++)
    {
        cout << "ingrese los numeros del arreglo: " << i << ": ";
        cin >> *(arreglo + i);
    }
}

void buscar_numero(int *arreglo, int tamano)
{
    int a;
    cout << "ingrese el numero que desea buscar dentro del arreglo: ";
    cin >> a;
    bool band = false;
    int i = 0;
    while ((band == false) && (i < tamano))

    {
        if (a == *(arreglo + i))
        {
            band = true;
        }
        i++;
    }
    if (band == true)
    {
        cout << "el numero se encuentra dentro del arreglo en la posicion " << i - 1;
    }
    else
    {
        cout << "el numero no se encuentra dentro del arreglo";
    }
}