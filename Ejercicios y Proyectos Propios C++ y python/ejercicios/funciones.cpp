#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
// prototipo de la funcion
void entrarnumero();
void mult(float num1, float num2);
void exponente(float num1, float num2);
float x;
float y;

void entrarnumero()
{
    cout << "ingrese dos numeros: ";
    cin >> x >> y;
}

void mult(float num1, float num2)
{

    float multiplicacion;
    multiplicacion = num1 * num2;
    cout << "la multiplicacion es: " << multiplicacion;
}

void exponente(float num1, float num2)
{
    long z;
    z = pow(num1, num2);
    cout << "el valor exponencial es: " << z;
}
int main()
{
    entrarnumero();
    mult(x, y);
    exponente(x, y);

    getch();
    return 0;
}