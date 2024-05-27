#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

struct Alumno {
    string nombre;
    int nota;
    int a;
};

int main() {
   int a;
    int notaMayor = 0;
    int indiceMayor = 0;
    //bool empate = false;
    cout<<"ingrese la cantidad de estudiantes: ";
    cin>>a;
    Alumno alumnos[a];
    // Solicitar los datos de los alumnos
    for (int i = 0; i < a; i++) {
        cout << "Ingrese el nombre del alumno " << i+1 << ": ";
        cin >> alumnos[i].nombre;
        cout << "Ingrese la nota del alumno " << i+1 << ": ";
        cin >> alumnos[i].nota;
        fflush(stdin);
        // Actualizar la nota mayor y el índice del alumno con la nota mayor
        if (alumnos[i].nota > notaMayor) {
            notaMayor = alumnos[i].nota;
            indiceMayor = i;
        //    empate = false;
      // } else if (alumnos[i].nota == notaMayor) {
          //  empate = true;
        }
    }
    
    // Mostrar los datos del alumno o alumnos con la nota mayor
    cout << "El alumno o alumnos con la nota mayor son: " << endl;
    cout << "- " << alumnos[indiceMayor].nombre << endl;
    cout << "- Nota: " << alumnos[indiceMayor].nota << endl;
    
    for (int i = 0; i < a; i++) {
        if (alumnos[i].nota == notaMayor && i != indiceMayor) {
            cout << "- " << alumnos[i].nombre << endl;
            cout << "- Nota: " << alumnos[i].nota << endl;
        }
    }
    getch();
    return 0;
}