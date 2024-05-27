#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

Nodo *lista = NULL;

void agregarLista(Nodo *&lista, int dato)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < dato))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void pedirLista()
{
    int len;
    int dato, cont = 0;
    cout << "Cantidad de datos a agregar: ";
    cin >> len;
    do
    {
        cout << "Ingrese dato: ";
        cin >> dato;
        agregarLista(lista, dato);
        cont++;
    } while (len > cont);
}

void mostrarLista(Nodo *lista)
{
    Nodo *actual = new Nodo();

    actual = lista;
    Nodo *ayuda = lista;
    cout << "Lista: { ";
    while (ayuda != NULL)
    {
        if (actual == lista)
        {
            cout << actual->dato << " ";
        }
       
        actual = actual->siguiente;
        ayuda = actual->siguiente;
    }
     if (ayuda == NULL)
        {
            cout << actual->dato;
        }
}
/* while (actual != NULL)
 {
     cout << actual->dato << " ";
     actual = actual->siguiente;
 }
 cout << "}";*/

void buscarElemento(Nodo *lista, int dato)
{
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL && actual->dato <= dato)
    {
        if (dato == actual->dato)
        {
            band = true;
        }
        actual = actual->siguiente;
    }
    if (band == true)
    {
        cout << "El dato ['" << dato << "'] se ha encontrado en la lista.";
    }
    else
    {
        cout << "El dato ['" << dato << "'] no se ha encontrado en la lista.";
    }
}

void borrarElemento(Nodo *&lista, int dato)
{
    if (lista != NULL)
    {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while (aux_borrar != NULL && aux_borrar->dato != dato)
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == NULL)
        {
            cout << "El dato " << dato << " no existe en la lista.";
        }
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
            cout << "El elemento " << dato << " se ha eliminado con exito!";
        }
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout << "El elemento " << dato << " se ha eliminado con exito!";
        }
    }
    else
    {
        cout << "La lista no contiene ningun elemento.";
    }
}

void borrarLista(Nodo *&lista)
{
    delete lista;
    lista = NULL;
}

void menu()
{
    system("cls");
    string o;
    int opcion, elemento;
    do
    {
        cout << "\n\t---Menu---\n1. Agregar elementos a la lista\n2. Mostrar lista\n3. Buscar elemento\n4. Eliminar elemento\n5. Eliminar lista\n6. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            pedirLista();
            system("cls");
            cout << "Se añadieron los datos a la lista correctamente.";
            break;
        case 2:
            system("cls");
            mostrarLista(lista);
            break;
        case 3:
            system("cls");
            cout << "Que dato desea buscar?: ";
            cin >> elemento;
            system("cls");
            buscarElemento(lista, elemento);
            break;
        case 4:
            system("cls");
            cout << "Que dato desea eliminar?: ";
            cin >> elemento;
            system("cls");
            borrarElemento(lista, elemento);
            break;
        case 5:
            cout << "Seguro que quiere borrar la lista? (y/n): ";
            cin >> o;
            if (o == "y")
            {
                borrarLista(lista);
            }
            system("cls");
            cout << "La lista se ha borrado correctamente.";
            break;
        case 6:
            system("cls");
            cout << "Adios!\n";
            break;
        default:
            cout << "Opcion inexistente...";
        }
    } while (opcion != 6);
}

int main()
{
    menu();
    return 0;
}