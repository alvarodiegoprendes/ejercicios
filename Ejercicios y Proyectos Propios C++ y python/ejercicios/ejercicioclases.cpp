#include <iostream>
#include <stdlib.h>
using namespace std;

class estudiante
{
    string nombre;
    string carrera;
    float promedio;
    char sexo;
    bool ayudante;

public: // Metodos
    estudiante();
    void crear_estudiante(string, string, float, char, bool);
    void imprimir_telecomunicaciones();
};

estudiante::estudiante()
{
    this->nombre = "";
    this->carrera = "";
    this->promedio = 0;
    this->sexo = 'M';
    this->ayudante = 1;
}

void estudiante::crear_estudiante(string Nombre, string Carrera, float Promedio, char Sexo, bool Ayudante)

{
    this->nombre = Nombre;
    this->carrera = Carrera;
    this->promedio = Promedio;
    this->sexo = Sexo;
    this->ayudante = Ayudante;

    /*cout << "ingrese un nombre: ";
    cin >> Nombre;
    cout << "entre la carrera: ";
    cin >> Carrera;
    cout << "entre el promedio: ";
    cin >> Promedio;
    cout << "entre el sexo del alumno como un caracter M o F: ";
    cin >> Sexo;
    cout << "ingrese un 1 en caso que el alumno sea ayudante y un 0 en caso contrario: ";
    cin >> Ayudante;*/
}

void estudiante::imprimir_telecomunicaciones()
{

    cout << "estudiante " << this->nombre << endl;
    cout << "carrera " << this->carrera << endl;
    cout << "promedio " << this->promedio << endl;
    cout << "sexo " << this->sexo << endl;
    cout << "ayudante " << (this->ayudante ? "si" : "no") << endl;
}


int main()
{
    int opcion;
    int i;

    cout << "1 para crear el objeto" << endl;
    cout << "2 para mostrar " << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        if (opcion == 1)
        {
            string Nombre;
            string Carrera;
            float Promedio;
            char Sexo;
            bool Ayudante;
            estudiante z = estudiante();
            cout << "ingrese un nombre: ";
            cin >> Nombre;
            cout << "entre la carrera: ";
            cin >> Carrera;
            cout << "entre el promedio: ";
            cin >> Promedio;
            cout << "entre el sexo del alumno como un caracter M o F: ";
            cin >> Sexo;
            cout << "ingrese un 1 en caso que el alumno sea ayudante y un 0 en caso contrario: ";
            cin >> Ayudante;
            z.crear_estudiante(Nombre, Carrera, Promedio, Sexo, Ayudante);
            cout << "\n ha creado el objeto";
            cout << "\n ingrese el numero 2";
            cin >> i;
            z.imprimir_telecomunicaciones();
        }
        break;

    default:
        break;
    }

    system("pause");
    return 0;
}
