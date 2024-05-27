#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;
//VARIABLES
string nombre;
string ci;
string fecha_de_nacimiento;
string sexo;
string direccion;
string anios_de_xp;
string materia;
string categoria_docente;
string categoria_cientifica;
string facultad;
string especialidad;
string anio;
string grupo;
string provincia;
string num_cuarto;
ofstream archivo;
ifstream file;

//ALGUNAS FUNCIONES UTILIZADAS
void MenuPrincipal();
void Graduar_Estudiante();
void Insertar_Profesor_Estudiante();
void Quita_Profesor_Estudiante();
void mostrar_matricula();
int claustro();
int matricula_estud();
void Insertar_Persona();
void Check_ci();
void Mostrar_Profesores(int i);
void Eliminar_Estudiante();
void Eliminar_Becado();
void Eliminar_Profesor();
void ElegirListado();
void Guardar_Archivo_P();
void Guardar_Archivo_E();
void Guardar_Archivo_B();
void Cargar_Info();
void Guardar_Imprimir();
void Cargar_Imprimir();

//CLASES
class Persona{
  public:
	string nombre;
	string ci;
	string fecha_de_nacimiento;
	string sexo;
	string direccion;

	Persona(string nombre, string ci, string fecha_de_nacimiento, string sexo, string direccion){
	this->nombre=nombre;
	this->ci=ci;
	this->fecha_de_nacimiento=fecha_de_nacimiento;
	this->sexo=sexo;
	this->direccion=direccion;
	 }


	};

class Profesor: public Persona {
public:
	string anios_de_xp;
	string materia;
	string categoria_docente;
	string categoria_cientifica;

	Profesor (string nombre, string ci, string fecha_de_nacimiento,
            string sexo, string direccion, string anios_de_xp, string materia,
             string categoria_docente, string categoria_cientifica) : Persona(nombre, ci, fecha_de_nacimiento, sexo, direccion){
		this->anios_de_xp=anios_de_xp;
		this->materia=materia;
		this->categoria_docente=categoria_docente;
		this->categoria_cientifica=categoria_cientifica;}



};

class Estudiante : public Persona{
public:
		string facultad;
		string especialidad;
		string anio;
		string grupo;

		Estudiante(string nombre, string ci, string fecha_de_nacimiento, string sexo, string direccion, string facultad, string especialidad, string anio, string grupo) : Persona(nombre, ci, fecha_de_nacimiento, sexo, direccion){
			this->facultad=facultad;
			this->especialidad=especialidad;
			this->anio=anio;
			this->grupo=grupo;
		}

};

class Becado: public Estudiante {
public:
		string provincia;
		string num_cuarto;

		Becado(string nombre, string ci, string fecha_de_nacimiento, string sexo, string direccion, string facultad, string especialidad, string anio, string grupo, string provincia, string num_cuarto) : Estudiante(nombre, ci, fecha_de_nacimiento, sexo, direccion, facultad, especialidad, anio, grupo){
			this->provincia=provincia;
			this->num_cuarto=num_cuarto;
		}

};

class Almacen_Profesor {
  public:
	Profesor **p;
	int tam;
	int cont;
         //CONSTRUCTOR DE LA CLASE
		Almacen_Profesor(){
			tam = 5;
			cont = 0;
			p = new Profesor*[tam];
		}
		//METODOS DE LA CLASE
		void Insertar_Profesor(Profesor* y){
			if (cont==tam){
				Profesor** new_Almacen_Profesor =new Profesor*[tam*=2];
				for (int i = 0; i < tam/2; i++){
					new_Almacen_Profesor[i]=p[i];
				}
				delete[] p;
				p=new_Almacen_Profesor;
				tam*=2;
			}
			p[cont]=y;
			cont++;
		}

		void setmasp(int pos){
			p[pos]=p[pos+1];}

		Profesor* get_p(int pos){
			return p[pos];
		}
		void setcont(int x){
			cont=x;
		}
		int getcont(){
			return cont;
		}


};
//OBJETO DE LA CLASE PROFESOR
Almacen_Profesor P = Almacen_Profesor();

class Almacen_Estudiante {
  public:
	Estudiante **e;
	int tam;
	int cont;
        //CONSTRUCTOR DE LA CLASE
		Almacen_Estudiante(){
			tam = 5;
			cont = 0;
			e = new Estudiante*[tam];
		}

	    //METODOS DE LA CLASE
		void Insertar_Estudiante(Estudiante* y){
			if (cont==tam){
				Estudiante** new_Almacen_Estudiante =new Estudiante *[tam*=2];
				for (int i = 0; i < tam/2; i++){
					new_Almacen_Estudiante[i]=e[i];
				}
				delete[] e;
				e=new_Almacen_Estudiante;
				tam*=2;
			}
			e[cont]=y;
			cont++;
		}

		void setmase(int pos){
			e[pos]=e[pos+1];
		}
		Estudiante* get_e(int pos){
			return e[pos];
		}
		void setcont(int x){
			cont=x;
		}
		int getcont(){
			return cont;
		}

};
//OBJETO DE LA CLASE ESTUDIANTE
Almacen_Estudiante E = Almacen_Estudiante();

class Almacen_Becado {
   public:
	Becado **b;
	int tam;
	int cont;
       //CONSTRUCTOR DE LA CLASE
		Almacen_Becado(){
			tam = 5;
			cont = 0;
			b = new Becado*[tam];
		}

	   //METODOS DE LA CLASE
		void Insertar_Becado(Becado *y){
			if (cont==tam){
				Becado** new_Almacen_Becado =new Becado*[tam*=2];
				for (int i = 0; i < tam/2; i++){
					new_Almacen_Becado[i]=b[i];
				}
				delete[] b;
				b=new_Almacen_Becado;
				tam*=2;
			}
			b[cont]=y;
			cont++;
		}

		void setmasb(int pos){
			b[pos]=b[pos+1];
		}
		Becado* get_b(int pos){
			return b[pos];
		}
		void setcont(int x){
			cont=x;
		}
		int getcont(){
			return cont;
		}

};
//OBJETO DE LA CLASE BECADO
Almacen_Becado B = Almacen_Becado();

//FUNCIONES PARA INSERTAR PERSONAL
void Insertar_Persona(){
	cout<<"Nombre y apellidos: ";

	cin.ignore();
	getline(cin, nombre);
	cout<<"Carnet de identidad: ";
	cin>>ci;
	Check_ci();
	cout<<"Fecha de nacimiento, formato numeral (dia/mes/año):";
	cin.ignore();
	getline(cin, fecha_de_nacimiento);
	cout<<"Sexo: ";
	cin>>sexo;
	cout<<"Direccion particular, formato (provincia,#,calles): ";
	cin.ignore();
	getline(cin, direccion);


}

void Insertar_Profesor_1(){
	cout<<"Rellene el siguiente formulario para insertar Profesor: \n"<<endl;
	Insertar_Persona();
	cout<<"Años de experiencia: ";
	cin>>anios_de_xp;
	cout<<"Asignatura que imparte: ";
	cin.ignore();
	getline(cin,materia);
	cout<<"Categoria docente: ";
	cin>>categoria_docente;
	cout<<"Categoria cientifica: ";
	cin>>categoria_cientifica;

	Profesor *p = new Profesor(nombre, ci, fecha_de_nacimiento, sexo, direccion, anios_de_xp, materia, categoria_docente, categoria_cientifica);
	P.Insertar_Profesor(p);

	cout<<"\n\n ->......Se ha agregado un profesor......<-"<<endl;
	system("pause");
	system("cls");
	MenuPrincipal();

}

void Insertar_Estudiante_1(){
	cout<<"Rellene el siguiente formulario para insertar Estudiante: \n"<<endl;
	Insertar_Persona();
	cout<<"Facultad a la que pertenece: ";
	getline(cin, facultad);
	cout<<"Especialidad de la carrera: ";
	getline(cin, especialidad);
	cout<<"Año en el que se encuentra: ";
	cin>>anio;
	cout<<"Grupo: ";
	cin>>grupo;

	Estudiante *e = new Estudiante(nombre, ci, fecha_de_nacimiento, sexo, direccion, facultad, especialidad, anio, grupo);
	E.Insertar_Estudiante(e);

	cout<<"\n\n ->......Se ha agregado un estudiante externo......<-"<<endl;
	system("pause");
	system("cls");
	MenuPrincipal();
}

void Insertar_Becado_1(){
	cout<<"Rellene el siguiente formulario para insertar Estudiante: \n"<<endl;
	Insertar_Persona();
	cout<<"Facultad a la que pertenece: ";
	getline(cin, facultad);
	cout<<"Especialidad de la carrera: ";
	getline(cin, especialidad);
	cout<<"Año en el que se encuentra: ";
	cin>>anio;
	cout<<"Grupo en el que esta: ";
	cin>>grupo;
	cout<<"Provincia de donde proviene: ";
	cin.ignore();
	getline(cin, provincia);
	cout<<"Cuarto de residencia: ";
	getline(cin, num_cuarto);


	Becado *b = new Becado(nombre, ci, fecha_de_nacimiento, sexo, direccion, facultad, especialidad, anio, grupo, provincia, num_cuarto);
	B.Insertar_Becado(b);

	cout<<"\n\n ->......Se ha agregado un estudiante becado......<-"<<endl;
	system("pause");
	system("cls");
	MenuPrincipal();
}

//FUNCIONES PARA MOSTRAR PERSONAL
void Mostrar_Profesores(int i){
	cout<<endl<< i+1<<"-"<<endl;
	cout<<"Nombre: "<<P.get_p(i)->nombre<<endl;
	cout<<"Carnet de identidad: "<<P.get_p(i)->ci<<endl;
	cout<<"Fecha de nacimiento: "<<P.get_p(i)->fecha_de_nacimiento<<endl;
	cout<<"Sexo: "<<P.get_p(i)->sexo<<endl;
	cout<<"Direccion: "<<P.get_p(i)->direccion<<endl;
	cout<<"Tiempo de docencia: "<<P.get_p(i)->anios_de_xp<<endl;
	cout<<"Asigantura que imparte: "<<P.get_p(i)->materia<<endl;
	cout<<"Categoria docente: "<<P.get_p(i)->categoria_docente<<endl;
	cout<<"Categoria cientifica: "<<P.get_p(i)->categoria_cientifica<<endl;
	cout<<"\n";
}

void Mostrar_Estudiantes(int i){
	cout<<endl<< i+1<<"-"<<endl;
	cout<<"Nombre y apellidos: "<<E.get_e(i)->nombre<<endl;
	cout<<"Carnet de identidad: "<<E.get_e(i)->ci<<endl;
	cout<<"Fecha de nacimiento: "<<E.get_e(i)->fecha_de_nacimiento<<endl;
	cout<<"Sexo: "<<E.get_e(i)->sexo<<endl;
	cout<<"Direccion: "<<E.get_e(i)->direccion<<endl;
	cout<<"Facultad: "<<E.get_e(i)->facultad<<endl;
	cout<<"Especialidad de la carrera: "<<E.get_e(i)->especialidad<<endl;
	cout<<"Año en que esta: "<<E.get_e(i)->anio<<endl;
	cout<<"Grupo: "<<E.get_e(i)->grupo<<endl;
	cout<<"\n";
}

void Mostrar_Becados(int i){
	cout<<endl<< i+1<<"-"<<endl;
	cout<<"Nombre y apellidos: "<<B.get_b(i)->nombre<<endl;
	cout<<"Carnet de identidad: "<<B.get_b(i)->ci<<endl;
	cout<<"Fecha de nacimiento: "<<B.get_b(i)->fecha_de_nacimiento<<endl;
	cout<<"Sexo: "<<B.get_b(i)->sexo<<endl;
	cout<<"Direccion: "<<B.get_b(i)->direccion<<endl;
	cout<<"Facultad: "<<B.get_b(i)->facultad<<endl;
	cout<<"Especialidad de la carrera: "<<B.get_b(i)->especialidad<<endl;
	cout<<"Año en que esta: "<<B.get_b(i)->anio<<endl;
	cout<<"Grupo: "<<B.get_b(i)->grupo<<endl;
	cout<<"Provincia: "<<B.get_b(i)->provincia<<endl;
	cout<<"Cuarto de residencia: "<<B.get_b(i)->num_cuarto<<endl;
	cout<<"\n";
}

void Profesor_catg_doc(){
    string catg_doc;
    cout<<"Digite la categoria docente a listar "<<endl;
    cin.ignore();
    getline(cin,catg_doc);

           for(int k=0;k<P.getcont();k++){

           if(P.get_p(k)->categoria_docente==catg_doc){
               Mostrar_Profesores(k);
               system("pause");
               system("cls");
                ElegirListado();

           }
           else {cout<<"\nNo se encuentra ningun profesor con dicha categoria docente  "<<endl<<endl;
           system("pause");
           system("cls");
            ElegirListado();
           }

    }
}

//FUNCIOES PARA ELIMINAR PERSONAL
void Eliminar_Estudiante(){
    if (E.getcont()==0)
        {cout<<"NO EXISTEN ESTUDIANTES EXTERNOS EN LA BASE DE DATOS DEL CENTRO PARA GRADUAR"<<endl;
        system("pause");
	    system("cls");
        Quita_Profesor_Estudiante();
	}

    float nota_f;
    string carrera_1;
    string rector;
	cout<<"\n GRADUAR ESTUDIANTE\n"<<endl;
	cout<<"Diga el numero de carnet de identidad del estudiante que desea graduar: "<<endl;
	string newci;
	cin>>newci;

	for(int j=0; j<E.getcont(); j++)
    {
        if(E.get_e(j)->ci==newci)
        {
    cout<<"Nota final del estudiante:"<<endl; cin>>nota_f;
	cout<<"Carrera que curso:"<<endl;
	cin.ignore();
	getline(cin,carrera_1);
	cout<<"Rector en funciones:"<<endl;
	getline(cin,rector);
        cout << "\nEl Estudiante" <<" "<<E.get_e(j)->nombre<<" "<< "ha sido graduado de la carrera de"<<" "<<carrera_1<<" "<<"con la nota de "<<" "<<nota_f<<" "<<"por el rector en funciones" <<" "<<rector<< endl;
            for(int i=j; i<E.getcont(); i++)
            {
                E.setmase(i);
            }
            E.setcont(E.getcont()-1);

            system("pause");
            system("cls");
            MenuPrincipal();
        }
        else {cout<<"El carnet introducido es incorrecto!"<<endl<<endl;
        system("pause");
        system("cls");
       Quita_Profesor_Estudiante();
        }
    }
}

void Eliminar_Becado(){
     if (B.getcont()==0)
        {cout<<"NO EXISTEN ESTUDIANTES BECADOS EN LA BASE DE DATOS DEL CENTRO PARA GRADUAR"<<endl;
        system("pause");
	    system("cls");
        Quita_Profesor_Estudiante();
	}

    float nota_f;
    string carrera_1;
    string rector;
	cout<<"\n Graduar Estudiante Becado\n"<<endl;
	cout<<"Diga el numero de carnet de identidad del estudiante becado que desea eliminar: "<<endl;
	string newci;
	cin>>newci;
	cout<<"Nota final del estudiante:"<<endl; cin>>nota_f;
	cout<<"Carrera que curso:"<<endl;
	cin.ignore();
	getline(cin,carrera_1);
	cout<<"Rector en funciones:"<<endl;
	getline(cin,rector);
	for(int j=0; j<B.getcont(); j++)
    {
        if(B.get_b(j)->ci==newci)
        {
    cout << "\nEl Estudiante" <<" "<<B.get_b(j)->nombre<<" "<< "ha sido graduado de la carrera de"<<" "<<carrera_1<<" "<<"con la nota de "<<" "<<nota_f<<" "<<"por el rector en funciones" <<" "<<rector<< endl;
            for(int i=j; i<B.getcont(); i++)
            {
                B.setmasb(i);
            }
            B.setcont(B.getcont()-1);

            system("pause");
            system("cls");
            MenuPrincipal();
        }
         else {cout<<"El carnet introducido es incorrecto!"<<endl<<endl;
         system("pause");
         system("cls");
       Quita_Profesor_Estudiante();
        }
    }
}

void Eliminar_Profesor(){

if (P.getcont()==0)
        {cout<<"NO EXISTEN PROFESORES EN LA BASE DE DATOS DEL CENTRO PARA ELIMINAR"<<endl;
        system("pause");
	    system("cls");
        MenuPrincipal();
	}


    string motivo;
	cout<<"DAR BAJA A UN PROFESOR\n"<<endl;
	cout<<"Diga el numero de carnet de identidad del profesor que desea dar de baja: "<<endl;
	string newci;
	cin>>newci;

	for(int j=0; j<P.getcont(); j++)
    {
        if(P.get_p(j)->ci==newci)
        {

	cout<<"Motivo por el cual se le da de baja:"<<endl;
	cin.ignore();
	getline(cin,motivo);

        cout << "\nEl Profesor" <<" "<<P.get_p(j)->nombre<<" "<< "ha sido dado de baja del centro exitosamente por el siguiente motivo:"<<" "<<motivo<< endl;
            for(int i=j; i<P.getcont(); i++)
            {
                P.setmasp(i);
            }
            P.setcont(P.getcont()-1);

            system("pause");
            system("cls");
            MenuPrincipal();
        }
        else {cout<<"El carnet introducido es incorrecto!"<<endl<<endl;
        system("pause");
        system("cls");
       MenuPrincipal();
        }
    }

}

//FUNCIOES DE MENU Y SUBMENUS
void ElegirListado(){
	cout<<"------------Por favor elija el tipo de listado---------------\n"<<endl;
	cout<<"1.-Listar todas las personas del centro"<<endl;
	cout<<"2.-Listar Profesores"<<endl;
	cout<<"3.-Listar Profesores segun su categoria docente  "<<endl;
	cout<<"4.-Listar Estudiantes externos"<<endl;
	cout<<"5.-Listar Estudiantes becados"<<endl;
	cout<<"6.-Menu Principal"<<endl;


	char opcion;
	cout<<"\nOpcion"<<endl;
	cin>>opcion;


	switch(opcion){
		case '1':
			system("cls");
			if ((P.getcont()==0)&&(E.getcont()==0)&&(B.getcont()==0))
            {cout<<"\tNO HAY PERSONAS REGISTRADAS EN LA BASE DE DATOS DEL CENTRO"<<endl;
            }
            if ((P.getcont()!=0)||(E.getcont()!=0)||(B.getcont()!=0))
            {cout<<"\tTODAS LAS PERSONAS DEL CENTRO"<<endl;
            }

			if(P.getcont()!=0)
			cout<<"PROFESORES"<<endl;

			for(int i = 0; i < P.getcont(); i++){
				Mostrar_Profesores(i);
			}
			if(E.getcont()!=0)
			cout<<"ESTUDIATES EXTERNOS"<<endl;

			for(int i = 0; i<E.getcont(); i++){
				Mostrar_Estudiantes(i);
			}
			if(B.getcont()!=0)
			cout<<"ESTUDIANTES BECADOS"<<endl;

			for(int i = 0; i < B.getcont(); i++){
				Mostrar_Becados(i);
			}

			system("pause");
			system("cls");
			MenuPrincipal();
			break;

		case '2':
			system("cls");
			     if(P.getcont()!=0)
			{cout<<"PROFESORES"<<endl;}
			else{cout<<"\tNO SE ENCUENTRA NINGUN PROFESOR EN LA BASE DE DATOS DEL CENTRO "<<endl;}

			for(int i = 0; i<P.getcont(); i++){
				Mostrar_Profesores(i);
			}
			system("pause");
			system("cls");
			MenuPrincipal();
			break;

       case '3':

			system("cls");
			if(P.getcont()!=0)
			cout<<"PROFESORES"<<endl;
             Profesor_catg_doc();
			break;


		case '4':
			system("cls");
				if(E.getcont()!=0)
			{cout<<"ESTUDIATES EXTERNOS"<<endl;}
			else{cout<<"\tNO SE ENCUENTRA NINGUN ESTUDIANTE EXTERNO EN LA BASE DE DATOS DEL CENTRO "<<endl;}

			for(int i = 0; i<E.getcont(); i++){
				Mostrar_Estudiantes(i);
			}
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '5':
			system("cls");
			     if(B.getcont()!=0)
			{cout<<"ESTUDIANTES BECADOS"<<endl;}
			else{cout<<"\tNO SE ENCUENTRA NINGUN ESTUDIANTE BECADO EN LA BASE DE DATOS DEL CENTRO "<<endl;}

			for(int i = 0; i<B.getcont(); i++){
				Mostrar_Becados(i);
			}
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '6':
			system("cls");
			MenuPrincipal();
			break;
		default:
			cout<<"Por favor introduzca un numero entre 1 y 6"<<endl;
			system("cls");
			ElegirListado();
			break;
	}
}

void MenuPrincipal(){
    cout<<"-----------------------------------------BIENVENIDOS A LA BASE DE DATOS DE LA CUJAE------------------------------------\n"<<endl;
	cout<<"-----MENU PRINCIPAL-------------------\n"<<endl;
	cout<<"\n SELECCIONE LA OPCION DESEADA"<<endl;
	cout<<"1.-Insertar Profesor o Estudiante"<<endl;
	cout<<"2.-Mostrar la matricula total de estudiantes y el claustro de profesores"<<endl;
	cout<<"3.-Graduar Estudiantes"<<endl;
	cout<<"4.-Listar"<<endl;
	cout<<"5.-Dar baja a un profesor"<<endl;
	cout<<"6.-Guardar la informacion en un archivo"<<endl;
	cout<<"7.-Guardar en modelo de impresion"<<endl;
	cout<<"8.-Ver el modelo de impresion guardado"<<endl;
	cout<<"9.-Cargar un archivo"<<endl;
	cout<<"10.-Salir del programa"<<endl;

	char opcion;
	cout<<"\nOpcion"<<endl;
	cin>>opcion;
	switch(opcion){
		case '1':
			system("cls");
			Insertar_Profesor_Estudiante();
			system("pause");
			system("cls");
			break;

		case '2':
            system("cls");
            mostrar_matricula();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;

		case '3':
			system("cls");
			Quita_Profesor_Estudiante();
			system("pause");
			system("cls");
			break;

		case '4':
			system("cls");
			ElegirListado();
			system("pause");
			system("cls");
			break;
        case '5':
			system("cls");
			Eliminar_Profesor();
			system("pause");
			system("cls");
			break;
        case '6':
			system("cls");
			Guardar_Archivo_P();
			Guardar_Archivo_E();
			Guardar_Archivo_B();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
        case '7':
			system("cls");
			Guardar_Imprimir();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
        case '8':
			system("cls");
			Cargar_Imprimir();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
        case '9':
			system("cls");
			Cargar_Info();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '10':
			system("cls");
			cout<<"---------------GRACIAS POR USAR NUESTRA APLICACION--------------- "<<endl;
			exit(1);
			break;
		default:
			cout<<"Introduzca un numero entre 1 y 10"<<endl;
			system("cls");
			MenuPrincipal();
			break;
	}
}

void Insertar_Profesor_Estudiante(){
	cout<<"------------Isertar Personal al centro---------------\n"<<endl;
	cout<<"Seleccione una de las siguientes opciones\n"<<endl;
	cout<<"1.-Insertar Profesor"<<endl;
	cout<<"2.-Insertar Estudiante externo"<<endl;
	cout<<"3.-Insertar Estudiante becado"<<endl;
	cout<<"4.-Regresar al Menu Principal"<<endl;
	char opcion;
	cout<<"\nOpcion"<<endl;
	cin>>opcion;
	switch(opcion){
		case '1':
			Insertar_Profesor_1();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '2':
			Insertar_Estudiante_1();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '3':
			Insertar_Becado_1();
			system("pause");
			system("cls");
			MenuPrincipal();
			break;
		case '4':
			system("cls");
			MenuPrincipal();
			break;
		default:
			cout<<"Ingrese un numero entre 1 y 4"<<endl;
			system("cls");
			Insertar_Profesor_Estudiante();
			break;
	}
}

void Quita_Profesor_Estudiante(){
	cout<<"----------Graduar estudiantes-----------\n"<<endl;
	cout<<"Seleccione una de las siguientes opciones: \n"<<endl;
	cout<<"1.-Graduar Estudiante externo"<<endl;
	cout<<"2.-Graduar Estudiante Becado"<<endl;
	cout<<"3.-Volver al Menu Principal"<<endl;
	char opcion;
	cout<<"\n Opcion: "<<endl;
	cin>>opcion;
	switch(opcion){
		case '1':
			Eliminar_Estudiante();
			break;
		case '2':
			Eliminar_Becado();
			break;
		case '3':
			system("cls");
			MenuPrincipal();
			break;
		default:
			cout<<"Introduzca un numero entre 1 y 3"<<endl;
			system("cls");
			Quita_Profesor_Estudiante();
			break;
	}
}

//FUNCION QUE VERIFICA EL CI
void Check_ci(){
    for(int i=0;i<P.getcont();i++){
       if (P.get_p(i)->ci == ci)
    {cout<<"EL CARNET INTRODUCIDO YA EXISTE EN LA BASE DE DATOS, POR FAVOR RECTIFIQUE "<<endl;
    system("pause");
    system("cls");
    Insertar_Profesor_Estudiante();
    }
    }

   for(int j=0;j<E.getcont();j++){
       if (E.get_e(j)->ci == ci)
    {cout<<"EL CARNET INTRODUCIDO YA EXISTE EN LA BASE DE DATOS, POR FAVOR RECTIFIQUE "<<endl;
    system("pause");
    system("cls");
    Insertar_Profesor_Estudiante();
    }
    }

    for(int k=0;k<B.getcont();k++){
       if (B.get_b(k)->ci == ci)
    {cout<<" EL CARNET INTRODUCIDO YA EXISTE EN LA BASE DE DATOS, POR FAVOR RECTIFIQUE "<<endl;
    system("pause");
    system("cls");
    Insertar_Profesor_Estudiante();
    }
    }



    }

//FUNCIONES QUE DEVUELVEN LA MATRICULA DEL CENTRO
int matricula_estud(){

    int cont_1=0;
    int cont_2=0;
    int result;
for(int i = 0; i<E.getcont(); i++){
    cont_1++;
}
    for(int i = 0; i < B.getcont(); i++){
        cont_2++;
    }
    result=cont_1+cont_2;
    return result;
}

int claustro(){
    int cont=0;
for(int i = 0; i<P.getcont(); i++)
cont++;
return cont;
}

void mostrar_matricula(){
 cout<<"Total de estudiantes del centro:"<<" "<<matricula_estud()<<endl<<endl;
 cout<<"Total de profesores del centro:"<<" "<<claustro()<<endl<<endl;
}

//FUNCONES PARA CARGAR Y GUARDAR EN UN ARCHIVO
void Guardar_Archivo_P(){
     const char DELIMITADOR= ',';
    ofstream archivo_pr;
    archivo_pr.open("DATOS_P.txt",ios::out);

if (archivo_pr.fail()){
    cout<<"Ha ocurrido un error al guardar el fichero"<<endl;
    MenuPrincipal();
}


else{

   for (int a=0; a<P.getcont();a++){
    archivo_pr<<P.get_p(a)->nombre<<DELIMITADOR<<P.get_p(a)->ci<<DELIMITADOR<<P.get_p(a)->fecha_de_nacimiento<<DELIMITADOR<<P.get_p(a)->sexo<<DELIMITADOR<<P.get_p(a)->direccion<<DELIMITADOR<<P.get_p(a)->anios_de_xp<<DELIMITADOR<<P.get_p(a)->materia<<DELIMITADOR<<P.get_p(a)->categoria_docente<<DELIMITADOR<<P.get_p(a)->categoria_cientifica<<DELIMITADOR<<endl;
   }
   archivo_pr.close();
}
}

void Guardar_Archivo_E(){
     const char DELIMITADOR= ',';
    ofstream archivo_es;
    archivo_es.open("DATOS_E.txt",ios::out);

if (archivo_es.fail()){
    cout<<"Ha ocurrido un error al guardar el fichero"<<endl;
    MenuPrincipal();
}


else{
   for(int b=0;b<E.getcont();b++){
    archivo_es<<E.get_e(b)->nombre<<DELIMITADOR<<E.get_e(b)->ci<<DELIMITADOR<<E.get_e(b)->fecha_de_nacimiento<<DELIMITADOR<<E.get_e(b)->sexo<<DELIMITADOR<<E.get_e(b)->direccion<<DELIMITADOR<<E.get_e(b)->facultad<<DELIMITADOR<<E.get_e(b)->especialidad<<DELIMITADOR<<E.get_e(b)->anio<<DELIMITADOR<<E.get_e(b)->grupo<<DELIMITADOR<<endl;
   }
   archivo_es.close();
}
}

void Guardar_Archivo_B(){
    const char DELIMITADOR= ',';
    ofstream archivo_be;
    archivo_be.open("DATOS_B.txt",ios::out);

if (archivo_be.fail()){
    cout<<"Ha ocurrido un error al guardar el fichero"<<endl;
    MenuPrincipal();
}

else{
   for(int c=0;c<B.getcont();c++){
    archivo_be<<B.get_b(c)->nombre<<DELIMITADOR<<B.get_b(c)->ci<<DELIMITADOR<<B.get_b(c)->fecha_de_nacimiento<<DELIMITADOR<<B.get_b(c)->sexo<<DELIMITADOR<<B.get_b(c)->direccion<<DELIMITADOR<<B.get_b(c)->facultad<<DELIMITADOR<<B.get_b(c)->especialidad<<DELIMITADOR<<B.get_b(c)->anio<<DELIMITADOR<<B.get_b(c)->grupo<<DELIMITADOR<<B.get_b(c)->provincia<<DELIMITADOR<<B.get_b(c)->num_cuarto<<DELIMITADOR<<endl;
   }
   cout<<"EL ARCHIVO SE HA GUARDADO EXITOSAMENTE"<<endl;
   archivo_be.close();
}
}

void Cargar_Info(){
    //PARTE 1
    string nombre_archivo_pr="DATOS_P.txt";
    ifstream archivo_pr(nombre_archivo_pr.c_str());
    string linea;
    string nombre;
	string ci;
	string fecha_de_nacimiento;
	string sexo;
	string direccion;
    string anios_de_xp;
	string materia;
	string categoria_docente;
	string categoria_cientifica;
	 const char DELIMITADOR = ',';

     while(!archivo.eof()){
	 while (getline(archivo_pr, linea))
	{
        stringstream input_stringstream(linea);
		getline(input_stringstream,nombre,DELIMITADOR);
		getline(input_stringstream,ci,DELIMITADOR);
		getline(input_stringstream,fecha_de_nacimiento, DELIMITADOR);
		getline(input_stringstream,sexo, DELIMITADOR);
		getline(input_stringstream,direccion, DELIMITADOR);
		getline(input_stringstream,anios_de_xp, DELIMITADOR);
		getline(input_stringstream,materia, DELIMITADOR);
		getline(input_stringstream,categoria_docente, DELIMITADOR);
		getline(input_stringstream,categoria_cientifica, DELIMITADOR);

    Profesor * teacher;
    teacher =new Profesor(nombre,ci,fecha_de_nacimiento,sexo,direccion,anios_de_xp,materia,categoria_docente,categoria_cientifica);
    P.Insertar_Profesor(teacher);
	}
	archivo_pr.close();

	//PARTE 2
	string nombre_archivo_es="DATOS_E.txt";
    ifstream archivo_es(nombre_archivo_es.c_str());
    string linea2;
    string facultad;
    string especialidad;
    string anio;
    string grupo;

    while (getline(archivo_es, linea2))
	{
        stringstream input_stringstream(linea2);
		getline(input_stringstream,nombre,DELIMITADOR);
		getline(input_stringstream,ci,DELIMITADOR);
		getline(input_stringstream,fecha_de_nacimiento, DELIMITADOR);
		getline(input_stringstream,sexo, DELIMITADOR);
		getline(input_stringstream,direccion, DELIMITADOR);
		getline(input_stringstream,facultad, DELIMITADOR);
		getline(input_stringstream,especialidad, DELIMITADOR);
		getline(input_stringstream,anio, DELIMITADOR);
		getline(input_stringstream,grupo, DELIMITADOR);

    Estudiante *estudent;
    estudent=new Estudiante(nombre,ci,fecha_de_nacimiento,sexo,direccion,facultad,especialidad,anio,grupo);
    E.Insertar_Estudiante(estudent);
	}
	archivo_es.close();

	//PARTE 3
	string nombre_archivo_be="DATOS_B.txt";
    ifstream archivo_be(nombre_archivo_be.c_str());
    string linea3;
    string provincia;
    string num_cuarto;


    while (getline(archivo_be, linea3))
	{
        stringstream input_stringstream(linea3);
		getline(input_stringstream,nombre,DELIMITADOR);
		getline(input_stringstream,ci,DELIMITADOR);
		getline(input_stringstream,fecha_de_nacimiento, DELIMITADOR);
		getline(input_stringstream,sexo, DELIMITADOR);
		getline(input_stringstream,direccion, DELIMITADOR);
		getline(input_stringstream,facultad, DELIMITADOR);
		getline(input_stringstream,especialidad, DELIMITADOR);
		getline(input_stringstream,anio, DELIMITADOR);
		getline(input_stringstream,grupo, DELIMITADOR);
        getline(input_stringstream,provincia, DELIMITADOR);
		getline(input_stringstream,num_cuarto, DELIMITADOR);


    Becado *scholarship;
    scholarship=new Becado(nombre,ci,fecha_de_nacimiento,sexo,direccion,facultad,especialidad,anio,grupo,provincia,num_cuarto);
    B.Insertar_Becado(scholarship);
	}
	archivo_be.close();

      remove("Profesor.txt");
      remove("Externo.txt");
      remove("Becado.txt");
       cout<<"INFORMACION CARGADA CON EXITO"<<endl;
        system("pause");
        system("cls");
        MenuPrincipal();}
}


//FUNCIONES PARA CREAR UN ARCHIVO PRESENTABLE PARA IMPRIMIR
void Guardar_Imprimir(){
    ofstream archivo;
    archivo.open("TRABAJO_FINAL.txt",ios::out);

if (archivo.fail()){
    cout<<"Ha ocurrido un error al guardar el fichero"<<endl;
    MenuPrincipal();
}


else{

   for (int a=0; a<P.getcont();a++){
    archivo<<"PROFESOR"<<endl;
    archivo<<"Nombre: "<<P.get_p(a)->nombre<<endl;
	archivo<<"Carnet de identidad: "<<P.get_p(a)->ci<<endl;
	archivo<<"Fecha de nacimiento: "<<P.get_p(a)->fecha_de_nacimiento<<endl;
	archivo<<"Sexo: "<<P.get_p(a)->sexo<<endl;
	archivo<<"Direccion: "<<P.get_p(a)->direccion<<endl;
	archivo<<"Tiempo de docencia: "<<P.get_p(a)->anios_de_xp<<endl;
	archivo<<"Asigantura que imparte: "<<P.get_p(a)->materia<<endl;
	archivo<<"Categoria docente: "<<P.get_p(a)->categoria_docente<<endl;
	archivo<<"Categoria cientifica: "<<P.get_p(a)->categoria_cientifica<<endl;
	archivo<<"\n";
   }

   for(int b=0;b<E.getcont();b++){

    archivo<<"ESTUDIANTE EXTERNO"<<endl;
    archivo<<"Nombre y apellidos: "<<E.get_e(b)->nombre<<endl;
	archivo<<"Carnet de identidad: "<<E.get_e(b)->ci<<endl;
	archivo<<"Fecha de nacimiento: "<<E.get_e(b)->fecha_de_nacimiento<<endl;
	archivo<<"Sexo: "<<E.get_e(b)->sexo<<endl;
	archivo<<"Direccion: "<<E.get_e(b)->direccion<<endl;
	archivo<<"Facultad: "<<E.get_e(b)->facultad<<endl;
	archivo<<"Especialidad de la carrera: "<<E.get_e(b)->especialidad<<endl;
	archivo<<"Año en que esta: "<<E.get_e(b)->anio<<endl;
	archivo<<"Grupo: "<<E.get_e(b)->grupo<<endl;
	archivo<<"\n";
   }
   for(int c=0;c<B.getcont();c++){
    archivo<<"ESTUDIANTE BECADO"<<endl;
    archivo<<"Nombre y apellidos: "<<B.get_b(c)->nombre<<endl;
	archivo<<"Carnet de identidad: "<<B.get_b(c)->ci<<endl;
	archivo<<"Fecha de nacimiento: "<<B.get_b(c)->fecha_de_nacimiento<<endl;
	archivo<<"Sexo: "<<B.get_b(c)->sexo<<endl;
	archivo<<"Direccion: "<<B.get_b(c)->direccion<<endl;
	archivo<<"Facultad: "<<B.get_b(c)->facultad<<endl;
	archivo<<"Especialidad de la carrera: "<<B.get_b(c)->especialidad<<endl;
	archivo<<"Año en que esta: "<<B.get_b(c)->anio<<endl;
	archivo<<"Grupo: "<<B.get_b(c)->grupo<<endl;
	archivo<<"Provincia: "<<B.get_b(c)->provincia<<endl;
	archivo<<"Cuarto de residencia: "<<B.get_b(c)->num_cuarto<<endl;
	archivo<<"\n";
   }
   cout<<"EL ARCHIVO SE HA GUARDADO EXITOSAMENTE"<<endl;
   archivo.close();

}
}

void Cargar_Imprimir(){
    ifstream file;
    string texto;

    file.open("TRABAJO_FINAL.txt",ios::in);

if (file.fail()){
    cout<<"Ha ocurrido un error al guardar el fichero"<<endl;
    MenuPrincipal();
}
else{
        while(!file.eof()){
          getline(file,texto);
          cout<<texto<<endl;
}



}
}


//FUNCION PRINCIPAL
int main(){

	MenuPrincipal();


	return 0;
}
