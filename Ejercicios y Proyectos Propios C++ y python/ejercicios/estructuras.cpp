#include <iostream>
#include <conio.h>
using namespace std;

struct alumno
{
    string nombre;
    int edad;
    float promedio;
} alumno[2];

int main()
{
    int mayor = 0;
    int pos;

    for (int i = 0; i < 2; i++)
    {
        // fflush(stdin);
        cout << "ingresa el nombre ";
        cin >> alumno[i].nombre;
        cout << "ingrese su edad ";
        cin >> alumno[i].edad;
        cout << "ingrese su promedio ";
        cin >> alumno[i].promedio;
    }
    for (int i = 0; i < 2; i++)
    {
        if (alumno[i].promedio >= mayor)
        {
            mayor = alumno[i].promedio;
            pos = i;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (alumno[i].promedio == mayor && i != pos)
        {
            cout << "los alumnos con el mejor promedio son: " << endl;
            cout << "\nNombre: " << alumno[i].nombre << endl;
            cout << "Edad: " << alumno[i].edad << endl;
            cout << "Promedio: " << alumno[i].promedio << endl;
        }
    }

    cout << "\nNombre: " << alumno[pos].nombre << endl;
    cout << "Edad: " << alumno[pos].edad << endl;
    cout << "Promedio: " << alumno[pos].promedio << endl;

    getch();
    return 0;
}
