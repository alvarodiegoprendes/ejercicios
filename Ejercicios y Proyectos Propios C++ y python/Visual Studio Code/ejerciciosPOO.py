class Cuenta():
    def __init__(self,id,saldo) -> None:
        self.id=id
        self.saldo=saldo
     
class Solicitud():
    def __init__(self,id,cantidad) -> None:
        self.id=id
        self.cantidad=cantidad
        self.solicitudes=[]

class Banco():
    def __init__(self) -> None:
        self.lista_cuentas=[]
        self.lista_solicitudes=[]
    def agregar_cuentas(self,cuenta: Cuenta):
        self.lista_cuentas.append(cuenta)
    def verificar_cuenta(self,id):
        for cuenta in self.lista_cuentas:
            if id == cuenta.id:
                return True
        return False
    def crear_solicitud(self,solicitud):
        self.lista_solicitudes.append(solicitud)
    def atender_solicitudes(self,solicitudes):
        pass

cuenta1= Cuenta(123,300)
cuenta2=Cuenta(234,400)

listado=Banco()
listado.agregar_cuentas(cuenta1)
listado.agregar_cuentas(cuenta2)
print(listado.verificar_cuenta(123))

