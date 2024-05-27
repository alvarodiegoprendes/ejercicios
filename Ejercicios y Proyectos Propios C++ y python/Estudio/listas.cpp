#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    float dato;
    Nodo *siguiente;
};

void almacenar_datos(Nodo *&, float);
void suma(Nodo *, float &);

float calculo = 0;
int cont;

int main()
{
    Nodo *lista = NULL;
    float dato;
    char respuesta;
    int opcion;
    do
    {
        cout << "digite un numero para almacenar en la lista: " << endl;
        cin >> dato;
        almacenar_datos(lista, dato);
        cout << "para almacenar otro numero digite s: " << endl;
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    cout << "para calcular la suma y el promedio digite 1: " << endl;

    cin >> opcion;
    switch (opcion)
    {
    case 1:
        suma(lista, calculo);

        break;
    }
    getch();
    return 0;
}
void almacenar_datos(Nodo *&lista, float n)
{

    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if (lista == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux = lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
}
void suma(Nodo *lista, float &calculo)
{

    while (lista != NULL)
    {

        calculo += lista->dato;
        lista = lista->siguiente;
        cont++;
    }
    float prom;
    prom = calculo / cont;

    cout << "el resultado de la suma es: " << calculo << endl;
    cout << "el promedio es: " << prom << endl;
}
