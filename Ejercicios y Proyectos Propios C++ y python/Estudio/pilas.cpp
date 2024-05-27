#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo
{
    char letra;
    Nodo *siguiente;
};

void menu();
void agregar_nodo(Nodo *&, char);
void sacar_nodo(Nodo *&, char &);

int main()
{
    menu();

    getch();
    return 0;
}

void menu()
{

    int opcion;
    char letra;
    Nodo *pila = NULL;
    do
    {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar un caracter a la pila" << endl;
        cout << "2. Mostrar todos los elementos de la pila" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "digite el caracter que desea ingresar a la pila: ";
            cin >> letra;
            agregar_nodo(pila, letra);

            break;
        case 2:
            while (pila != NULL)
            {
                sacar_nodo(pila, letra);
                if (pila != NULL)
                {
                    cout << letra << " , ";
                }
                else
                {
                    cout << letra;
                }
            }
            cout<<"\n";
            system("pause");
            break;
        case 3:
            break;
        }

    } while (opcion != 3);
}
void agregar_nodo(Nodo *&pila, char letra)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->letra = letra;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void sacar_nodo(Nodo *&pila, char &letra)
{

    Nodo *aux = pila;
    letra = aux->letra;
    pila = aux->siguiente;
    delete aux;

}