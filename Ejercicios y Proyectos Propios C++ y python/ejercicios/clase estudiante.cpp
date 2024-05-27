#include "iostream"
using namespace std;
class estudiante
{
    string nombre;
    string carrera;
    float promedio;
    char sexo;
    bool ayudante;

public:
    estudiante();
    /*void entrar_nombre(string);
    void entrar_carrera(string);
    void entrar_promedio(float);
    void entrar_sexo(char);
    void entrar_alumnoayudante(bool);

    
    void alumnos_ayudantes();
    void notas_mayores();
    void cantidad_de_alumnos();
    void porcentaje_por_sexo();*/
    void crear_estudiante();
    void imprimir_telecomunicaciones();
};
// DEFINIENDO FUNCIONES

// funcion constructora

estudiante::estudiante()

{
    string Nombre;
    this->nombre = Nombre;
    string Carrera = std::string();
    this->carrera = Carrera;
    float Promedio = 0;
    this->promedio = Promedio;
    char Sexo = 0;
    this->sexo = Sexo;
    bool Ayudante = false;
    this->ayudante = Ayudante;
}

// crear estudiante
void estudiante::crear_estudiante()
{
    string Nombre;
    string Carrera;
    float Promedio;
    char Sexo;
    bool Ayudante;

    cout << "ingrese un nombre: ";
    cin >> Nombre;
    cout << "entre la carrera: ";
    cin >> Carrera;
    cout << "entre el promedio: ";
    cin >> Promedio;
    cout << "entre el sexo del alumno como un caracter M o F: ";
    cin >> Sexo;
    cout << "ingrese un 1 en caso que el alumno sea ayudante y un 0 en caso contrario: ";
    cin >> Ayudante;

}

/*//entrar nombre
void estudiante::entrar_nombre(string) {
    cout<<"ingrese un nombre: ";
    cin>>nombre;
}
//entrar carrera
void estudiante::entrar_carrera(string) {
    cout<<"entre la carrera: ";
    cin>>carrera;
}
//entrar promedio
void estudiante::entrar_promedio(float) {
    cout<<"entre el promedio: ";
    cin>>promedio;
}
//entrar sexo
void estudiante::entrar_sexo(char) {
    cout<<"entre el sexo del alumno como un caracter M o F: ";
    cin>>sexo;
}
//entrar alumno ayudante
void estudiante::entrar_alumnoayudante(bool) {
    cout<<"ingrese un 1 en caso que el alumno sea ayudante y un 0 en caso contrario: ";
    cin>>ayudante;
}*/
// metodo para imprimir estudiantes de telecomunicaciones
void estudiante::imprimir_telecomunicaciones()
{

    cout << "estudiante " <<this-> nombre << endl;
    cout << "carrera " <<this-> carrera << endl;
    cout << "promedio " <<this-> promedio << endl;
    cout << "sexo " <<this-> sexo << endl;
    cout << "ayudante " << (this-> ayudante ? "si" : "no") << endl;
}
// metodo para imprimir relacion de alumnos ayudantes
/*
void estudiante::alumnos_ayudantes()
{
    if (ayudante == true)
    {
        cout << "estudiante " << nombre << endl;
        cout << "carrera " << carrera << endl;
        cout << "promedio " << promedio << endl;
        cout << "sexo " << sexo << endl;
        cout << "ayudante " << endl;
    }
    else if (ayudante == false)
    {
        cout << "No es alumno ayudante";
    }
}
// metodo para imprimir estudiantes con promedio mayor que 4.5
void estudiante::notas_mayores()
{
    if (promedio > 4.5)
    {
        cout << "estudiante " << nombre << endl;
        cout << "carrera " << carrera << endl;
        cout << "promedio " << promedio << endl;
        cout << "sexo " << sexo << endl;
        cout << "ayudante " << (ayudante ? "si" : "no") << endl;
    }
}
// metodo para imprimir cantidad de alumnos por sexo
void estudiante::cantidad_de_alumnos()
{
    int masculinos = 0;
    int femeninos = 0;
    if (sexo == 'M')
    {
        masculinos++;
    }
    else
    {
        femeninos++;
    }
    cout << "la cantidad de alumnos masculinos es " << masculinos << endl;
    cout << "la cantidad de alumnos femeninos es " << femeninos << endl;
}
// metodo para imprimir porcentaje de alumno por sexo
void estudiante::porcentaje_por_sexo()
{
    int cantidad_de_alumnos = 0;
    int masculinos = 0;
    int femeninos = 0;
    if (sexo == 'M')
    {
        masculinos++;
    }
    else
    {
        femeninos++;
    }
    float porcentaje_masc = (masculinos / cantidad_de_alumnos) * 100;
    float porcentaje_fem = (femeninos / cantidad_de_alumnos) * 100;

    cout << "la cantidad de alumnos masculinos representa el " << porcentaje_masc << "%" << endl;
    cout << "la cantidad de alumnos femeninos representa el " << porcentaje_fem << "%" << endl;
}*/

int main()
{

    estudiante p = estudiante();
    p.crear_estudiante();
    p.imprimir_telecomunicaciones();


    /*
        int i;
        cout << "bienvenido a la base de datos \n\n"
             << endl;
        cout << "elija una opcion: \n"
             << endl;
        cout << "1- introducir un nuevo alumno a la base de datos" << endl;
        cout << "2-obtener informacion de un alumno" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
        {
            estudiante::crear_estudiante();


        }break;

        }
        */
    return 0;
}
