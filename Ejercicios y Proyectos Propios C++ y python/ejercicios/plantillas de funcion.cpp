#include <iostream>
#include <conio.h>
using namespace std;
// prototipo de la funcion
template <class tipod>
void mostrarabs(tipod numero);

template <class tipod>
void mostrarabs(tipod numero)
{
    if (numero < 0)
    {
        numero = numero * -1;
    }
    cout << "el valor modular es: " << numero << endl;
}

int main()
{
    int a = 4;
    float b = 6.5;

    mostrarabs(a);
    mostrarabs(b);

    getch();
    return 0;
}