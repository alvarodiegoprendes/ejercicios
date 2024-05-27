/*
En una academia de formación profesional se quiere automatizar la gestión de profesores  
y clases. En la academia se imparten clases de primer y segundo grado en diferentes  
especialidades (administración, informática, delineación y electrónica), existiendo varios  
grupos por cada curso y especialidad, de forma que existen, por ejemplo, un 1º A en la  
especialidad de Administración, un 1º A en la especialidad de Informática, un 1º B de  
Administración, etc.  
Cada especialidad se caracteriza por un código de especialidad, nombre, número de  
asignaturas totales y título oficial otorgado. Los cursos se componen de un número de curso  
(1º, 2º, 3º, 4º o 5º) y de la lista de asignaturas del curso. Por su parte, los grupos incluyen  
el código de grupo (A, B o C) y el número de alumnos que lo componen, siendo una prioridad  
del centro mantener un límite máximo de 15 alumnos por grupo. 
Cada grupo tiene un profesor al que se considera tutor del grupo y que se encarga de dar  
algunas de las asignaturas consideradas como troncales del curso: matemáticas, literatura,  
etc. Además, debido a las características particulares de cada especialidad, existen  
profesores encargados de impartir clases especializadas como contabilidad, sistemas  
operativos, etc. Tanto los profesores “tutores” como los “especialistas” se consideran  
personal fijo de la academia y la información que se deberá almacenar de ellos es su DNI,  
nombre y apellidos, domicilio, nivel de estudios alcanzados y titulación. Un profesor puede  
ser “tutor” de un grupo y “especialista” en el mismo u otro grupo distinto y nada impide que  
un profesor sólo pertenezca a la categoría de “especialistas”. 
Uno de los principales objetivos de la academia es llevar un riguroso control de las clases  
impartidas por los profesores y también de las clases recibidas por los alumnos de forma  
individualizada (con el objetivo de realizar posteriores estadísticas de absentismo  
académico) para lo que establece las siguientes medidas: 
- Todos los profesores deben firmar diariamente una hoja de actividad que justifica las  
clases que ha dado. Existe una hoja de actividad diaria por cada grupo y en dicha hoja se  
registra la fecha, el nombre del profesor y las horas de inicio y de fin de la clase dada por  
el profesor.  
- Además de firmar la hoja de actividad, los profesores deben firmar a cada alumno una  
ficha individual en la que consta el mes, el día del mes, la clase impartida y la firma del  
profesor. Estas fichas individuales se renuevan cada mes de forma que cada una contiene  
tantas casillas con los tres campos (día, clase y firma) como días tenga el mes. 
Como la academia está muy preocupada porque el ritmo de las clases no se altere bajo  
ningún concepto mantiene un grupo de profesores “candidatos” que permiten impartir las  
clases cuando alguno de los profesores tutores o especialistas no puede hacerlo por  
cualquier motivo (enfermedad, vacaciones, etc). Los interesados en cubrir vacantes deben  
dejar en la academia una copia de su Curriculum Vitae y rellenar un formulario en el que  
indiquen las materias que desean impartir y si desean trabajar como tutores, como  
especialistas o como ambas cosas.Cuando se necesita cubrir una vacante se consulta la lista de candidatos y en función de  
las clases a cubrir se contacta telefónicamente con algunos de los candidatos para  
concertar una entrevista. De la llamada interesa almacenar la fecha y hora de la misma y la  
disposición del candidato a mantener la entrevista: “no localizado”, “no está interesado” o  
“entrevista concertada”. Una vez realiza la entrevista, se emite un informe con la fecha de  
la entrevista, el nombre del candidato entrevistado, la materia a cubrir y la valoración que  
se le asigna.
El proceso de selección de candidatos (llamada y entrevista) es realizado por un grupo de  
profesores tutores o especialistas que forman parte de un comité selectivo encargado de  
estas labores. Este comité es por tanto el encargado de elegir al candidato en función de la  
valoración que se le haya dado. Una vez elegido el candidato la formalización de su contrato  
laboral no es objeto de este modelo de datos. El comité se compone de un presidente, un  
secretario y un vocal. La pertenencia al comité es optativa y sus miembros se eligen  
anualmente, pero la academia está interesada en mantener un historial de los sucesivos  
comités de selección por lo que deberá guardarse también el año de constitución de cada  
comité.
*/

#include <iostream>
#include <pqxx/pqxx>
#include <cstdlib>

using namespace std;
using namespace pqxx;

void limpiarConsola() {
    system("clear");
}

void limpiarBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausar() {
    cout << "Pulse Enter para continuar...";
    cin.get();

}

void ejecutarConsulta(connection &c, const string &query) {
    try {
        nontransaction n(c);
        result r = n.exec(query);
        n.commit();
    } catch (const exception &e) {
        cerr << "Error al ejecutar la consulta SQL: " << e.what() << endl;
    }
}

connection conectar() {
    try {
        connection c("dbname = farmacia user = postgres password = 1234admin hostaddr = 127.0.0.1 port = 5432");
        if (c.is_open()) {
            cout << "Conexión establecida con la base de datos " << c.dbname() << endl;
            return c;
        } else {
            cout << "No se ha podido conectar con la base de datos" << endl;
            cout << "Pulse Enter para salir del programa" <<endl;
            cin.get();
            throw runtime_error("Error de conexión con la base de datos");
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
        throw;
    }
    pausar();
}

void crearTablasFarmacia(connection &c) {
    try {
        string query = "CREATE TABLE IF NOT EXISTS Ciudad ("
                       "nombre_ciudad VARCHAR(100) NOT NULL,"
                       "provincia VARCHAR(100) NOT NULL,"
                       "cantidad_habitantes INTEGER NOT NULL,"
                       "superficie FLOAT NOT NULL,"
                       "PRIMARY KEY (nombre_ciudad, provincia)"
                       ");";
        ejecutarConsulta(c, query);

        query = "CREATE TABLE IF NOT EXISTS Farmacia ("
                "id_farmacia SERIAL PRIMARY KEY,"
                "nombre VARCHAR(100) UNIQUE NOT NULL,"
                "domicilio VARCHAR(100) NOT NULL,"
                "nombre_ciudad VARCHAR(100) NOT NULL,"
                "provincia VARCHAR(100) NOT NULL,"
                "FOREIGN KEY (nombre_ciudad, provincia) REFERENCES Ciudad(nombre_ciudad, provincia)"
                ");";
        ejecutarConsulta(c, query);

        query = "CREATE TABLE IF NOT EXISTS Director ("
                "dni VARCHAR(20) PRIMARY KEY,"
                "nombre VARCHAR(100) NOT NULL,"
                "calle VARCHAR(100) NOT NULL,"
                "numero VARCHAR(10) NOT NULL,"
                "codigo_postal VARCHAR(10) NOT NULL,"
                "nombre_ciudad VARCHAR(100) NOT NULL,"
                "provincia VARCHAR(100) NOT NULL,"
                "id_farmacia INTEGER,"
                "FOREIGN KEY (nombre_ciudad, provincia) REFERENCES Ciudad(nombre_ciudad, provincia),"
                "FOREIGN KEY (id_farmacia) REFERENCES Farmacia(id_farmacia)"
                ");";
        ejecutarConsulta(c, query);

        query = "CREATE TABLE IF NOT EXISTS Medicamento ("
                "id_medicamento SERIAL PRIMARY KEY,"
                "nombre_comercial VARCHAR(100) UNIQUE NOT NULL,"
                "composicion VARCHAR(255) NOT NULL"
                ");";
        ejecutarConsulta(c, query);

        query = "CREATE TABLE IF NOT EXISTS Precio_Medicamento ("
                "id_farmacia INTEGER,"
                "id_medicamento INTEGER,"
                "precio FLOAT NOT NULL,"
                "PRIMARY KEY (id_farmacia, id_medicamento),"
                "FOREIGN KEY (id_farmacia) REFERENCES Farmacia(id_farmacia),"
                "FOREIGN KEY (id_medicamento) REFERENCES Medicamento(id_medicamento)"
                ");";
        ejecutarConsulta(c, query);

        query = "CREATE TABLE IF NOT EXISTS Complemento_Medicamento ("
                "id_medicamento_base INTEGER,"
                "id_medicamento_complemento INTEGER,"
                "PRIMARY KEY (id_medicamento_base),"
                "FOREIGN KEY (id_medicamento_base) REFERENCES Medicamento(id_medicamento),"
                "FOREIGN KEY (id_medicamento_complemento) REFERENCES Medicamento(id_medicamento)"
                ");";
        ejecutarConsulta(c, query);

        cout << "Tablas del sistema de farmacia comprobadas exitosamente" << endl;
        system ("sleep 1");
        cout << "Cargando menú principal..." << endl;
        system("sleep 2");
    } catch (const exception &e) {
        cerr << "Error al crear las tablas del sistema de farmacia: " << e.what() << endl;
        pausar();
        throw;
        return;
    }
}

void mostrarFarmacias(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT f.id_farmacia, f.nombre, f.domicilio, c.nombre_ciudad, c.provincia "
                        "FROM farmacia f "
                        "INNER JOIN ciudad c ON f.nombre_ciudad = c.nombre_ciudad AND f.provincia = c.provincia;"));

        if (R.empty()) {
            cout << "La tabla Farmacia está vacía." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla Farmacia:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "ID: " << row["id_farmacia"].as<int>() << endl;
            cout << "Nombre: " << row["nombre"].as<string>() << endl;
            cout << "Domicilio: " << row["domicilio"].as<string>() << endl;
            cout << "Ciudad: " << row["nombre_ciudad"].as<string>() << endl;
            cout << "Provincia: " << row["provincia"].as<string>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla Farmacia: " << e.what() << endl;
        throw;
    }
    pausar();
}

void mostrargrupos(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT grupo.codigo_grupo, grupo.cant_alumnos, grupo.hoja_actividades, grupo.alumno"
                        "FROM grupo"));

        if (R.empty()) {
            cout << "La tabla grupo esta vacia." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla grupo:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "codigo_grupo: " << row["codigo_grupo"].as<string>() << endl;
            cout << "cant_alumnos: " << row["cant_alumnos"].as<string>() << endl;
            cout << "hoja_actividades: " << row["hoja_actividades"].as<string>() << endl;
            // cout << "cursonumero_curso: " << row["cursonumero_curso"].as<string>() << endl;
            // cout << "especialidadcodigo especialidad: " << row["especialidadcodigo especialidad"].as<string>() << endl;
            cout << "alumno: " << row["alumno"].as<string>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla grupo: " << e.what() << endl;
        throw;
    }
    pausar();
}

void mostrarespecialidad(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT m.codigo especialidad, m.nombre, m.cant_asignaturas, m.titulo "
                        "FROM especialidad m;"));

        if (R.empty()) {
            cout << "La tabla especialidad esta vacia." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla especialidad:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "codigo especialidad: " << row["codigo especialidad"].as<int>() << endl;
            cout << "nombre: " << row["nombre"].as<string>() << endl;
            cout << "cant_asignaturas: " << row["cant_asignaturas"].as<string>() << endl;
            cout << "titulo: " << row["titulo"].as<string>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla especialidad: " << e.what() << endl;
        throw;
    }
    pausar();
}

void mostrarhoja_actividad(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT pm.id, pm.fecha, pm.nombre_profesor, pm.hora_inicio, pm.hora_fin, pm.grupocodigo_grupo "
                        "FROM hoja actividad pm "));

        if (R.empty()) {
            cout << "La tabla hoja_actividad esta vacia." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla hoja_actividad:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "ID: " << row["id"].as<int>() << endl;
            cout << "Fecha: " << row["fecha"].as<int>() << endl;
            cout << "nombre_profesor: " << row["nombre_profesor"].as<float>() << endl;
            cout << "hora_inicio: " << row["hora_inicio"].as<string>() << endl;
            cout << "hora_fin: " << row["hora_fin"].as<string>() << endl;
            cout << "grupocodigo_grupo: " << row["grupocodigo_grupo"].as<string>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla hoja_actividad: " << e.what() << endl;
        throw;
    }
    pausar();
}

void mostrarComplementosMedicamentos(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT cm.id_medicamento_base, cm.id_medicamento_complemento, "
                        "m1.nombre_comercial AS nombre_medicamento_base, "
                        "m2.nombre_comercial AS nombre_medicamento_complemento "
                        "FROM complemento_medicamento cm "
                        "INNER JOIN medicamento m1 ON cm.id_medicamento_base = m1.id_medicamento "
                        "INNER JOIN medicamento m2 ON cm.id_medicamento_complemento = m2.id_medicamento;"));

        if (R.empty()) {
            cout << "La tabla Complemento_Medicamento está vacía." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla Complemento_Medicamento:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "ID del medicamento base: " << row["id_medicamento_base"].as<int>() << endl;
            cout << "ID del medicamento complemento: " << row["id_medicamento_complemento"].as<int>() << endl;
            cout << "Nombre del medicamento base: " << row["nombre_medicamento_base"].as<string>() << endl;
            cout << "Nombre del medicamento complemento: " << row["nombre_medicamento_complemento"].as<string>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla Complemento_Medicamento: " << e.what() << endl;
        throw;
    }
    pausar();
}

void mostrarCiudades(connection &c) {
    limpiarBuffer();
    limpiarConsola();
    try {
        nontransaction N(c);
        result R(N.exec("SELECT * FROM ciudad;"));

        if (R.empty()) {
            cout << "La tabla Ciudad está vacía." << endl;
            pausar();
            return;
        }

        cout << "Datos de la tabla Ciudad:" << endl;
        for (result::const_iterator row = R.begin(); row != R.end(); ++row) {
            cout << "Nombre de la ciudad: " << row["nombre_ciudad"].as<string>() << endl;
            cout << "Provincia: " << row["provincia"].as<string>() << endl;
            cout << "Cantidad de habitantes: " << row["cantidad_habitantes"].as<int>() << endl;
            cout << "Superficie: " << row["superficie"].as<float>() << endl;
            cout << endl;
        }
    } catch (const exception &e) {
        cerr << "Error al mostrar datos de la tabla Ciudad: " << e.what() << endl;
        throw;
    }
    pausar();
}

void menuPrincipal(connection &c){
    int opcion;
    do {
        limpiarConsola();
        cout << "SISTEMA DE FARMACIA\n" << endl;
        cout << "1. Mostrar farmacias" << endl;
        cout << "2. Mostrar directores" << endl;
        cout << "3. Mostrar medicamentos" << endl;
        cout << "4. Mostrar precios de medicamentos" << endl;
        cout << "5. Mostrar complementos de medicamentos" << endl;
        cout << "6. Mostrar ciudades" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarFarmacias(c);
                break;
            case 2:
                mostrarDirectores(c);
                break;
            case 3:
                mostrarMedicamentos(c);
                break;
            case 4:
                mostrarPreciosMedicamentos(c);
                break;
            case 5:
                mostrarComplementosMedicamentos(c);
                break;
            case 6:
                mostrarCiudades(c);
                break;  
            case 0:
                limpiarConsola();
                cout << "Programa finalizado..." << endl;
                system("sleep 1");
                break;
            default:
                limpiarConsola();
                cout << "Opción no válida, intente otra vez: " << endl;
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
        system("sleep 1");
        crearTablasFarmacia(c); 
        system("sleep 1");
        menuPrincipal(c);
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

