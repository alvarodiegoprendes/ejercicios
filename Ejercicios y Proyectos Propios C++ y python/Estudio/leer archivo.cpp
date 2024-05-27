#include <iostream>
#include <fstream>
using namespace std;

void leer_archivo();
int main()
{
    leer_archivo();
    return 0;
}

void leer_archivo()
{
    ifstream archivo;
    string ubicacion;
    string texto;
    cout << "digite la ubicacion del archivo que desea abrir: " << endl;
    getline(cin, ubicacion);
    archivo.open(ubicacion.c_str(), ios::in);
    if (archivo.fail())
    {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto<<endl;
    }

    archivo.close();
}