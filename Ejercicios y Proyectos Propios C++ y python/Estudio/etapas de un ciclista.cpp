#include <iostream>
#include <conio.h>
using namespace std;

struct Etapas

{
    int horas;
    int minutos;
    int segundos;

} etapas[3], *puntero_etapa = etapas;

void pedir_datos();
void tiempo_total(Etapas *);

int main()
{
    pedir_datos();
    tiempo_total(puntero_etapa);
    getch();
    return 0;
}
void pedir_datos()
{

    for (int i = 0; i < 3; i++)
    {
        fflush(stdin);
        cout << "digite la cantidad de horas que se demoro el ciclista en recorrer la etapa" << i+1 << ": " << endl;
        cin >> (puntero_etapa + i)->horas;
        cout << "digite la cantidad de minutos que se demoro el ciclista en recorrer la etapa" << i+1 << ": " << endl;
        cin >> (puntero_etapa + i)->minutos;
        cout << "digite la cantidad de segundos que se demoro el ciclista en recorrer la etapa" << i+1 << ": " << endl;
        cin >> (puntero_etapa + i)->segundos;
    }
}
void tiempo_total(Etapas *puntero_etapa)
{

    int totaldehoras=0;
    int totaldeminutos=0;
    int totaldesegundos=0;

    for (int i = 0; i < 3; i++)
    {

        totaldehoras += (puntero_etapa+i)->horas;
        totaldeminutos += (puntero_etapa+i)->minutos;
        if(totaldeminutos>=60){
            totaldeminutos-=60;
            totaldehoras++;
        }
        totaldesegundos += (puntero_etapa+i)->segundos;
        if(totaldesegundos>=60){
            totaldesegundos-=60;
            totaldeminutos++;
        }
    }

    cout << "el total del tiempo fue de: " << totaldehoras << ":" << totaldeminutos << ":" << totaldesegundos << endl;
}