#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Cliente
{
    char nombre[30];
    char clave[10];
    int edad;
};
struct Nodo
{
    Cliente c;
    Nodo *siguiente;
};
void cargar_cliente(Cliente &);
void agregar_clientes(Nodo *&, Nodo *&, Cliente);
bool cola_vacia(Nodo *);
void mostar_clientes(Nodo *&, Nodo *&, Cliente &);

int main()
{

    Nodo *frente = NULL;
    Nodo *fin = NULL;
    Cliente c;
    char rsp;
    do
    {
        cargar_cliente(c);
        agregar_clientes(frente, fin, c);

        cout << "para agregar otro cliente presione s: ";
        cin >> rsp;

    } while (rsp == 's' || rsp == 'S');
    cout << " Mostrando clientes: "<<endl;
    while (frente != NULL)
    {
        mostar_clientes(frente, fin, c);

        cout << "nombre: " << c.nombre << endl;
        cout << "clave: " << c.clave << endl;
        cout << "edad: " << c.edad << endl;
    }
    getch();
    return 0;
}
void cargar_cliente(Cliente &c)
{
    fflush(stdin);
    cout << "digite los datos para ingresar un nuevo cliente: " << endl;
    cout << "digite el nombre del cliente: " << endl;
    cin.getline(c.nombre, 30, '\n');
    cout << "digite la clave del usuario: " << endl;
    cin.getline(c.clave, 10, '\n');
    cout << "digite la edad del cliente: " << endl;
    cin >> c.edad;
}

void agregar_clientes(Nodo *&frente, Nodo *&fin, Cliente c)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->c = c;
    nuevo_nodo->siguiente = NULL;
    if (cola_vacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}
bool cola_vacia(Nodo *frente)
{
    return (frente == NULL) ? true : false;
}

void mostar_clientes(Nodo *&frente, Nodo *&fin, Cliente &c)
{
    Nodo *aux = frente;
    c = frente->c;
    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->siguiente;
    }
    delete aux;
}