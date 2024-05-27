#include <iostream>
using namespace std;
int main() {
    int matriz[100][100],fila,columna;

        cout<<"ingrese el numero de filas de su matriz: "<<endl;cin>>fila;
        cout<<"ingrese el numero de columnas de su matriz: "<<endl; cin>>columna;
            //contruyendo la matriz
            for(int i=0;i<fila;i++){
                for(int j=0;j<columna;j++){
                    cout<<"ingrese un numero para ser guardado en su matriz en la posicion: ["<<i<<"] ["<<j<<"]";
                    cin>>matriz[i][j];
                }
            }
            //imprimiendo la matriz
            for(int i=0;i<fila;i++){
                for(int j=0;j<columna;j++){
                    cout<<" "<<matriz[i][j];
                }
                cout<<"\n";
            }

    return 0;
}
