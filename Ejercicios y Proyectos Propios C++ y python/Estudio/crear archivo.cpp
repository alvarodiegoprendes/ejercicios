#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void creararchivo();

int main()
{
    creararchivo();

    return 0;
}

void creararchivo()
{
    char rsp;
    string frase;
    string nombre;
    ofstream archivo;
    cout << "digite el nombre del archivo: " << endl;
    getline(cin, nombre);

    archivo.open(nombre.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "no se pudo crear el archivo" << endl;
        exit(1);
    }
    do
    {
        fflush(stdin);
        cout << "digite la frase que desea guardar en su arhivo: " << endl;
        getline(cin, frase);
        archivo << frase<<endl;
        cout << "si desea agregar otra frase presione s" << endl;
        cin >> rsp;
    } while (rsp == 's' || rsp == 'S');

    archivo.close();
}