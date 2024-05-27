#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

class Cliente
{
private:
    string nombre;
    string dirrec;

public:
    Cliente(string n, string d)
    {
        nombre = n;
        dirrec = d;
    }
    string verNombre()
    {
        return nombre;
    }
    string getdirrec()
    {
        return dirrec;
    }
    void ponerNombre(string n)
    {
        nombre = n;
    }
    void ponerdirrec(string d)
    {
        dirrec = d;
    }
};
class Cuenta
{
private:
    int numero;
    double saldo;
    vector<string> historial;

public:
    Cuenta(int n, double s) 
    {
        numero = n;
        saldo = s; 
    }
    int verNumero() const
    {
        return numero;
    }
    double verSaldo()
    {
        return saldo;
    }
    void depositar(double cantidad)
    {
        saldo += cantidad;
        historial.push_back("Deposito: +" + to_string(cantidad));
    }
    void retirar(double cantidad)
    {
        if (cantidad <= saldo)
        {
            saldo -= cantidad;
            historial.push_back("Retiro: -" + to_string(cantidad));
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
    }
    void transferir(double cantidad, Cuenta &cuentaDestino)
    {
        if (cantidad <= saldo)
        {
            saldo -= cantidad;
            cuentaDestino.depositar(cantidad);
            historial.push_back("Transferencia: -" + to_string(cantidad) + " a cuenta " + to_string(cuentaDestino.verNumero()));
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
    }
    vector<string> verHistorial()
    {
        return historial;
    };
};

 bool isnumber(const string& s){
   return !s.empty()&& all_of(s.begin(),s.end(),::isdigit);}
   
  bool cuentaAsignada(const vector<Cuenta>& cuentas, int numCuenta)
{
    for (const auto& cuenta : cuentas)
    {
        if (cuenta.verNumero() == numCuenta)
        {
            return true;
        }
    }
    return false;
}

int main()
{
	Inicio:
    vector<Cliente> clientes;
    vector<Cuenta> cuentas;
    string respuesta = "si";
    string opcion;
    do
    {
        system("cls");
        cout << "Menu principal:" << endl<<endl;
        cout << "1. Ingresar clientes y cuentas" << endl;
        cout << "2. Consultar saldo" << endl;
        cout << "3. Realizar deposito" << endl;
        cout << "4. Realizar transferencia" << endl;
        cout << "5. Mostrar todas las cuentas creadas" << endl;
        cout << "6. Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
       getline(cin,opcion);
           if (!isnumber(opcion)){
        	cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
                goto Inicio;
		}
	
		if (isnumber(opcion)){
        
        
        switch (stoi(opcion))
        {
            
      /*case 1:

            while (respuesta == "si")
            {
                cout << "Ingrese el nombre del cliente: " << endl;
                string nombre, direccion;
                getline(cin, nombre);
                cout << "Ingrese la direccion del cliente: " << endl;
                getline(cin, direccion);
                // Crear el objeto de cliente
                Cliente nuevoCliente(nombre, direccion);

                // Crear el objeto de cuenta
                cout << "Ingrese el numero de la cuenta: " << endl;
                int numCuenta;
                cin >> numCuenta;
                cout << "Ingrese el saldo inicial de la cuenta: " << endl;
                double saldoInicial;
                cin >> saldoInicial;
                Cuenta nuevaCuenta(numCuenta, saldoInicial);

                // Agregar el nuevo cliente y cuenta al final de los vectores
                clientes.push_back(nuevoCliente);
                cuentas.push_back(nuevaCuenta);

                cout << "Ingrese 'si' para crear otro usuario con su cuenta o 'no' en caso contrario: " << endl;
                cin >> respuesta;
                fflush(stdin);
            }
            break;*/
            case 1:
		{
    while (respuesta == "si")
    {
        cout << "Ingrese el nombre del cliente: " << endl;
        string nombre, direccion;
        getline(cin, nombre);
        cout << "Ingrese la direccion del cliente: " << endl;
        getline(cin, direccion);
        // Crear el objeto de cliente
        Cliente nuevoCliente(nombre, direccion);
		
        // Crear el objeto de cuenta
        int numCuenta;
        do
        {
            cout << "Ingrese el numero de la cuenta: " << endl;
            cin >> numCuenta;
       
            if (cuentaAsignada(cuentas, numCuenta))
            {
                cout << "Error: el numero de cuenta ya esta asignado. Intente con otro numero." << endl;
            }
        } while (cuentaAsignada(cuentas, numCuenta));

        cout << "Ingrese el saldo inicial de la cuenta: " << endl;
        double saldoInicial;
        cin >> saldoInicial;
        Cuenta nuevaCuenta(numCuenta, saldoInicial);
        	 fflush(stdin);

        // Agregar el nuevo cliente y cuenta al final de los vectores
        clientes.push_back(nuevoCliente);
        cuentas.push_back(nuevaCuenta);

        cout << "Ingrese 'si' para crear otro usuario con su cuenta o 'no' en caso contrario: " << endl;
        cin >> respuesta;
        fflush(stdin);
        if (respuesta != "si" && respuesta != "no")
        {
            cout << "Respuesta invalida. Saliendo de la opcion 1." << endl;
            respuesta = "no";
        }
    }
    break;
}
            
        case 2:
            system("cls");
            cout << "Ingrese el numero de cuenta: ";
            int numCuenta;
            cin >> numCuenta;
            for (int i = 0; i < cuentas.size(); i++)
            {
                if (cuentas[i].verNumero() == numCuenta)
                {
                    cout << "Saldo actual: $" << cuentas[i].verSaldo() << endl;
                    break;
                }
                if (i == cuentas.size() - 1)
                {
                    cout << "Cuenta no encontrada" << endl;
                }
            }fflush(stdin);
            break;

        case 3:
            system("cls");
            cout << "Ingrese el numero de cuenta: ";
            cin >> numCuenta;
            for (int i = 0; i < cuentas.size(); i++)
            {
                if (cuentas[i].verNumero() == numCuenta)
                {
                    double cantidad;
                    cout << "Ingrese la cantidad a depositar: $";
                    cin >> cantidad;
                    cuentas[i].depositar(cantidad);
                    cout << "Deposito realizado correctamente" << endl;
                    break;
                }
                if (i == cuentas.size() - 1)
                {
                    cout << "Cuenta no encontrada" << endl;
                }
            }fflush(stdin);
            break;

        case 4:
            system("cls");
            int numCuentaOrigen, numCuentaDestino;
            double cantidadTransferir;
            cout << "Ingrese el numero de cuenta de origen: ";
            cin >> numCuentaOrigen;
            for (int i = 0; i < cuentas.size(); i++)
            {
                if (cuentas[i].verNumero() == numCuentaOrigen)
                {
                    cout << "Ingrese el numero de cuenta destino: ";
                    cin >> numCuentaDestino;
                    for (int j = 0; j < cuentas.size(); j++)
                    {
                        if (cuentas[j].verNumero() == numCuentaDestino)
                        {
                            cout << "Ingrese la cantidad a transferir: $";
                            cin >> cantidadTransferir;
                            cuentas[i].transferir(cantidadTransferir, cuentas[j]);
                            cout << "Transferencia realizada correctamente" << endl;
                            break;
                        }
                        if (j == cuentas.size() - 1)
                        {
                            cout << "Cuenta destino no encontrada" << endl;
                        }
                    }
                    break;
                }
                if (i == cuentas.size() - 1)
                {
                    cout << "Cuenta origen no encontrada" << endl;
                }
            }fflush(stdin);
            break;
        case 5:
            system("cls");
            cout << "Cuentas de clientes:" << endl;
            for (int i = 0; i < clientes.size(); i++)
            {
                cout << "Cliente: " << clientes[i].verNombre() << endl;
                for (int j = 0; j < cuentas.size(); j++)
                {
                    if (cuentas[j].verNumero() == i + 1)
                    {
                        cout << "    Cuenta #" << cuentas[j].verNumero() << ", Saldo: $" << cuentas[j].verSaldo() << endl;
                    }
                }
            }fflush(stdin);
            break;

        case 6:
            cout << "Saliendo del programa" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
        }

        system("pause");
    }
}  while (stoi(opcion) != 6);
    return 0;
}
