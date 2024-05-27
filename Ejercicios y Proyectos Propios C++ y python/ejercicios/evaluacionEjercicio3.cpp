#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int arreglo[3] = {3, 2, 1};
    int *puntero[3];

    for (int i = 0; i < 3; i++)
    {
        puntero[i] = &arreglo[i];
        cout << " " << &puntero[i] << endl;
    }
    for (int i = 0; i < 3; i++)
    { 
        for (int j = i + 1; j < 3; j++)
        {
            if (*puntero[j] < *puntero[i])
            {
                int *a = puntero[i];
                puntero[i] = puntero[j];
                puntero[j] = a;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << " " << *puntero[i] << endl;
    }

    getch();
    return 0;
}