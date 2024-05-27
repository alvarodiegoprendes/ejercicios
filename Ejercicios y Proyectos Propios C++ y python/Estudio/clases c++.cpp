#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangulo
{
private:
    int largo;
    int ancho;

public:
    Rectangulo(int, int);
    void perimetro();
    void area();
};

Rectangulo::Rectangulo(int _largo,int _ancho){
    largo=_largo;
    ancho=_ancho;
}
void Rectangulo::perimetro(){


}
void Rectangulo::area(){


    
}

int main()
{

    

    system("pause");
    return 0;
}