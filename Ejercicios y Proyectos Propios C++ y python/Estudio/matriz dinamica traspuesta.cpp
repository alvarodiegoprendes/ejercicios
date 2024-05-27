#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

void pedir_matriz();
void mostrar_matriz(int **, int, int);
void invirtiendo_matriz(int **,int, int);

int **matriz, nfilas, ncolumnas;

int main()
{
    pedir_matriz();
    mostrar_matriz(matriz, nfilas, ncolumnas);
    invirtiendo_matriz(matriz,nfilas,ncolumnas);
    for (int i = 0; i < nfilas; i++)
    {

        delete[] matriz[i];
    }
    delete[] matriz;
    getch();
    return 0;
}

void pedir_matriz()
{
    // entrando datos filas y columnas
    cout << "digite la cantidad de filas de su matriz: ";
    cin >> nfilas;
    cout << "digite la cantidad de columnas de su matriz: ";
    cin >> ncolumnas;
    // reservando espacio en memoria para la matriz dinamica
    matriz = new int *[nfilas];
    for (int i = 0; i < nfilas; i++)
    {
        matriz[i] = new int[ncolumnas];
    }
    // creando matriz dinamica
    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncolumnas; j++)
        {
            cout << "digite los numeros de su matriz: ";
            cin >> *(*(matriz + i) + j);
        }
    }
}
// mostrando matriz
void mostrar_matriz(int **matriz, int nfilas, int ncolumnas)
{

    cout << "mostrando matriz: " << endl;
    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncolumnas; j++)
        {
            cout << *(*(matriz + i) + j);
        }
        cout << endl;
    }
}
//invirtiendo matriz
void invirtiendo_matriz(int **matriz,int nfilas, int ncolumnas){
    
    cout << "mostrando matriz transpuesta: " << endl;
    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncolumnas; j++)
        {
            cout << *(*(matriz + j) + i);
        }
        cout << endl;
    }

}