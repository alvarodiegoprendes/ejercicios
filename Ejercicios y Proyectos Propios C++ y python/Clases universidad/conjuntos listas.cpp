#include <iostream>
#include <algorithm>
using namespace std;

struct Nodo
{
    int numero;
    Nodo *siguiente;
};

void crear_lista(Nodo *&lista, int numero)
{
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->numero = numero;
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

// Función para imprimir los elementos de la lista
void imprimirLista(Nodo *lista)
{
    Nodo *aux = lista;
    while (aux != NULL)
    {
        cout << aux->numero << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

int main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;

    int numero;
    int opcion = 0;
    while (opcion < 4)
    {
        cout << "digite 1 para crear la lista1: " << endl;
        cout << "digite 2 para crear la lista2: " << endl;
        cout << "digite 3 para unir ambas listas: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "digite el numero que desea agregar a la lista: " << endl;
            cin >> numero;
            crear_lista(lista1, numero);
            break;
        case 2:
            cout << "digite el numero que desea agregar a la lista: " << endl;
            cin >> numero;
            crear_lista(lista2, numero);
            break;
        case 3:
            Nodo *&aux_unir = lista2;
            while (aux_unir != NULL)
            { // uniendo lista 1 con lista 2 en lista 1
                crear_lista(lista1, aux_unir->numero);
                aux_unir = aux_unir->siguiente;
            }
            
            Nodo *actual = lista1;
            if (actual == NULL)
            {
                cout << "La lista está vacía";
            }

            while (actual != NULL)

            {
                Nodo *siguienteNodo = actual->siguiente;
                Nodo *nodoAnterior = actual;

                while (siguienteNodo != NULL)
                {
                    if (actual->numero == siguienteNodo->numero)
                    {
                        nodoAnterior->siguiente = siguienteNodo->siguiente;
                        delete siguienteNodo;
                        siguienteNodo = nodoAnterior->siguiente;
                    }
                    else
                    {
                        nodoAnterior = siguienteNodo;
                        siguienteNodo = siguienteNodo->siguiente;
                    }
                }

                actual = actual->siguiente;
            }
            imprimirLista(lista1);
            break;
        }
    }

    return 0;
}
