#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int par=0;
    int impar=0;
    int arreglo[10];

    cout<<"para un arreglo de 10 elementos: "<<endl;
    for (int i=0; i < 10; i++)
    {
        cout << "escriba un numero: "<<endl;
        cin >> arreglo[i];
    }


    for (int i=0; i < 10; i++)
    {
        if (arreglo[i] % 2 == 0)
        {
            par++;
        }else{
            impar++;
        }
    }
    cout<<"hay "<<par<<"numeros pares y "<<impar<<"numeros impares"<<endl;

    getch();
    return 0;
}