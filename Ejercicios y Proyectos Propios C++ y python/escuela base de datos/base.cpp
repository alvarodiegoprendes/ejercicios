/*
En una academia de formaci�n profesional se quiere automatizar la gesti�n de profesores
y clases. En la academia se imparten clases de primer y segundo grado en diferentes
especialidades (administraci�n, inform�tica, delineaci�n y electr�nica), existiendo varios
grupos por cada curso y especialidad, de forma que existen, por ejemplo, un 1� A en la
especialidad de Administraci�n, un 1� A en la especialidad de Inform�tica, un 1� B de
Administraci�n, etc.
Cada especialidad se caracteriza por un c�digo de especialidad, nombre, n�mero de
asignaturas totales y t�tulo oficial otorgado. Los cursos se componen de un n�mero de curso
(1�, 2�, 3�, 4� o 5�) y de la lista de asignaturas del curso. Por su parte, los grupos incluyen
el c�digo de grupo (A, B o C) y el n�mero de alumnos que lo componen, siendo una prioridad
del centro mantener un l�mite m�ximo de 15 alumnos por grupo.
Cada grupo tiene un profesor al que se considera tutor del grupo y que se encarga de dar
algunas de las asignaturas consideradas como troncales del curso: matem�ticas, literatura,
etc. Adem�s, debido a las caracter�sticas particulares de cada especialidad, existen
profesores encargados de impartir clases especializadas como contabilidad, sistemas
operativos, etc. Tanto los profesores �tutores� como los �especialistas� se consideran
personal fijo de la academia y la informaci�n que se deber� almacenar de ellos es su DNI,
nombre y apellidos, domicilio, nivel de estudios alcanzados y titulaci�n. Un profesor puede
ser �tutor� de un grupo y �especialista� en el mismo u otro grupo distinto y nada impide que
un profesor s�lo pertenezca a la categor�a de �especialistas�.
Uno de los principales objetivos de la academia es llevar un riguroso control de las clases
impartidas por los profesores y tambi�n de las clases recibidas por los alumnos de forma
individualizada (con el objetivo de realizar posteriores estad�sticas de absentismo
acad�mico) para lo que establece las siguientes medidas:
- Todos los profesores deben firmar diariamente una hoja de actividad que justifica las
clases que ha dado. Existe una hoja de actividad diaria por cada grupo y en dicha hoja se
registra la fecha, el nombre del profesor y las horas de inicio y de fin de la clase dada por
el profesor.
- Adem�s de firmar la hoja de actividad, los profesores deben firmar a cada alumno una
ficha individual en la que consta el mes, el d�a del mes, la clase impartida y la firma del
profesor. Estas fichas individuales se renuevan cada mes de forma que cada una contiene
tantas casillas con los tres campos (d�a, clase y firma) como d�as tenga el mes.
Como la academia est� muy preocupada porque el ritmo de las clases no se altere bajo
ning�n concepto mantiene un grupo de profesores �candidatos� que permiten impartir las
clases cuando alguno de los profesores tutores o especialistas no puede hacerlo por
cualquier motivo (enfermedad, vacaciones, etc). Los interesados en cubrir vacantes deben
dejar en la academia una copia de su Curriculum Vitae y rellenar un formulario en el que
indiquen las materias que desean impartir y si desean trabajar como tutores, como
especialistas o como ambas cosas.Cuando se necesita cubrir una vacante se consulta la lista de candidatos y en funci�n de
las clases a cubrir se contacta telef�nicamente con algunos de los candidatos para
concertar una entrevista. De la llamada interesa almacenar la fecha y hora de la misma y la
disposici�n del candidato a mantener la entrevista: �no localizado�, �no est� interesado� o
�entrevista concertada�. Una vez realiza la entrevista, se emite un informe con la fecha de
la entrevista, el nombre del candidato entrevistado, la materia a cubrir y la valoraci�n que
se le asigna.
El proceso de selecci�n de candidatos (llamada y entrevista) es realizado por un grupo de
profesores tutores o especialistas que forman parte de un comit� selectivo encargado de
estas labores. Este comit� es por tanto el encargado de elegir al candidato en funci�n de la
valoraci�n que se le haya dado. Una vez elegido el candidato la formalizaci�n de su contrato
laboral no es objeto de este modelo de datos. El comit� se compone de un presidente, un
secretario y un vocal. La pertenencia al comit� es optativa y sus miembros se eligen
anualmente, pero la academia est� interesada en mantener un historial de los sucesivos
comit�s de selecci�n por lo que deber� guardarse tambi�n el a�o de constituci�n de cada
comit�.
*/

#include <iostream>
#include <pqxx/pqxx>
#include <cstdlib>


using namespace std;
using namespace pqxx;

void limpiarConsola() {
	system("cls");
}

void limpiarBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausar() {
	cout << "Pulse Enter para continuar...";
	cin.get();

}

void ejecutarConsulta(connection& c, const string& query) {
	try {
		nontransaction n(c);
		result r = n.exec(query);
		n.commit();
	}
	catch (const exception & e) {
		cerr << "Error al ejecutar la consulta SQL: " << e.what() << endl;
	}
}

connection conectar() {
	try {
		connection c("dbname = escuela user = postgres password = alvaroadp200301 hostaddr = 127.0.0.1 port = 5432");
		if (c.is_open()) {
			cout << "Conexion establecida con la base de datos " << c.dbname() << endl;
			return c;
		}
		else {
			cout << "No se ha podido conectar con la base de datos" << endl;
			cout << "Pulse Enter para salir del programa" << endl;
			cin.get();
			throw runtime_error("Error de conexion con la base de datos");
		}
	}
	catch (const exception & e) {
		cerr << e.what() << endl;
		throw;
	}
	pausar();
}


void mostrarcursos(connection& c) {
	limpiarBuffer();
	limpiarConsola();
	try {
		nontransaction N(c);
		result R(N.exec("SELECT f.numero_curso, f.lista_asignaturas "
			"FROM curso f "));

		if (R.empty()) {
			cout << "el curso esta vacio." << endl;
			pausar();
			return;
		}

		cout << "Datos de la tabla curso:" << endl;
		for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
			cout << "ID: " << row["numero_curso"].as<int>() << endl;
			//cout << "Codigo especialidad: " << row["especialidadcodigoespecialidad"].as<string>() << endl;
			cout << "Asignaturas: " << row["lista_asignaturas"].as<string>() << endl;
			cout << endl;
		}
	}
	catch (const exception & e) {
		cerr << "Error al mostrar datos de la tabla curso " << e.what() << endl;
		throw;
	}
	pausar();
}
void mostrargrupos(connection& c) {
	limpiarBuffer();
	limpiarConsola();
	try {
		nontransaction N(c);
		result R(N.exec("SELECT g.codigo_grupo, g.cant_alumnos, g.cursonumero_curso, g.especialidadcodigoespecialidad "
			"FROM grupo g"));

		if (R.empty()) {
			cout << "La tabla grupo esta vacia." << endl;
			pausar();
			return;
		}

		cout << "Datos de la tabla grupo:" << endl;
		for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
			cout << "codigo_grupo: " << row["codigo_grupo"].as<string>() << endl;
			cout << "cant_alumnos: " << row["cant_alumnos"].as<string>() << endl;
			cout << "cursonumero_curso: " << row["cursonumero_curso"].as<string>() << endl;
			cout << "especialidadcodigo especialidad: " << row["especialidadcodigoespecialidad"].as<string>() << endl;
			cout << endl;
		}
	}
	catch (const exception & e) {
		cerr << "Error al mostrar datos de la tabla grupo: " << e.what() << endl;
		throw;
	}
	pausar();
}

void mostrarespecialidad(connection& c) {
	limpiarBuffer();
	limpiarConsola();
	try {
		nontransaction N(c);
		result R(N.exec("SELECT m.codigoespecialidad, m.nombre, m.cant_asignaturas, m.titulo "
			"FROM especialidad m"));

		if (R.empty()) {
			cout << "La tabla especialidad esta vacia." << endl;
			pausar();
			return;
		}

		cout << "Datos de la tabla especialidad:" << endl;
		for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
			cout << "codigo especialidad: " << row["codigoespecialidad"].as<int>() << endl;
			cout << "nombre: " << row["nombre"].as<string>() << endl;
			cout << "cant_asignaturas: " << row["cant_asignaturas"].as<string>() << endl;
			cout << "titulo: " << row["titulo"].as<string>() << endl;
			cout << endl;
		}
	}
	catch (const exception & e) {
		cerr << "Error al mostrar datos de la tabla especialidad: " << e.what() << endl;
		throw;
	}
	pausar();
}

void mostrarhoja_actividad(connection& c) {
	limpiarBuffer();
	limpiarConsola();
	try {
		nontransaction N(c);
		result R(N.exec("SELECT pm.id, pm.fecha, pm.nombre_profesor, pm.hora_inicio, pm.hora_fin, pm.grupocodigo_grupo "
			"FROM hojaactividad pm "));

		if (R.empty()) {
			cout << "La tabla hoja_actividad esta vacia." << endl;
			pausar();
			return;
		}

		cout << "Datos de la tabla hoja_actividad:" << endl;
		for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
			cout << "ID: " << row["id"].as<int>() << endl;
			cout << "Fecha: " << row["fecha"].as<string>("%Y-%m-%d") << endl;
			cout << "hora_inicio: " << row["hora_inicio"].as<string>("%H:%M:%S") << endl;
			cout << "hora_fin: " << row["hora_fin"].as<string>("%H:%M:%S") << endl;
			cout << "grupocodigo_grupo: " << row["grupocodigo_grupo"].as<string>() << endl;
			cout << "nombre_profesor: " << row["nombre_profesor"].as<string>() << endl;
			cout << endl;
		}
	}
	catch (const exception & e) {
		cerr << "Error al mostrar datos de la tabla hoja_actividad: " << e.what() << endl;
		throw;
	}
	pausar();
}
void mostraralumnos(connection& c) {
	limpiarBuffer();
	limpiarConsola();
	try {
		nontransaction N(c);
		result R(N.exec("SELECT a.numero, a.nombre, a.grupocodigo_grupo "
			"FROM alumno a "));

		if (R.empty()) {
			cout << "La tabla de alumnos esta vacia." << endl;
			pausar();
			return;
		}

		cout << "Datos de la tabla alumnos:" << endl;
		for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
			cout << "numero de lista: " << row["numero"].as<int>() << endl;
			cout << "nombre: " << row["nombre"].as<string>() << endl;
			cout << "grupocodigo_grupo: " << row["grupocodigo_grupo"].as<string>() << endl;
			cout << endl;
		}
	}
	catch (const exception & e) {
		cerr << "Error al mostrar datos de la tabla alumno: " << e.what() << endl;
		throw;
	}
	pausar();
}

void menuPrincipal(connection& c) {
	int opcion;
	do {
		limpiarConsola();
		cout << "SISTEMA DE ESCUELA\n" << endl;
		cout << "1. Mostrar cursos" << endl;
		cout << "2. Mostrar grupos" << endl;
		cout << "3. Mostrar especialidad" << endl;
		cout << "4. Mostrar hoja_actividad" << endl;
		cout << "5. Mostrar alumnos" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";

		cin >> opcion;

		switch (opcion) {
		case 1:
			mostrarcursos(c);
			break;
		case 2:
			mostrargrupos(c);
			break;
		case 3:
			mostrarespecialidad(c);
			break;
		case 4:
			mostrarhoja_actividad(c);
			break;
		case 5:
			mostraralumnos(c);
			break;
		case 0:
			limpiarConsola();
			cout << "Programa finalizado..." << endl;
			break;
		default:
			limpiarConsola();
			cout << "Opcion no valida, intente otra vez: " << endl;
			pausar();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	} while (opcion != 0);
}

int main() {
	limpiarConsola();
	try {
		connection c = conectar();
		menuPrincipal(c);
	}
	catch (const exception & e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	return 0;
}

