from abc import abstractmethod
    
class Pieza():
    def __init__(self,id,nombre,precio_costo) -> None:
        self.id=id
        self.nombre=nombre
        self.precio_costo=precio_costo

    @abstractmethod
    def precio_venta(self,precio_costo,pedidos: list):
        pass


class Nacional(Pieza):
    def __init__(self, id, nombre, precio_costo,categoria) -> None:
        super().__init__(id, nombre, precio_costo)
        self.categoria=categoria
    def precio_venta(self):
        precio_venta1=0
        precio_venta2=0
        precio_venta3=0
        if self.categoria==1:
            precio_venta1=self.precio_costo + 0.08*self.precio_costo
        if self.categoria==2:
            precio_venta2=self.precio_costo + 0.05*self.precio_costo
        if self.categoria==3:
            precio_venta3=self.precio_costo + 0.03*self.precio_costo
        return precio_venta1+precio_venta2+precio_venta3


class Importada(Pieza):
    def __init__(self, id, nombre, precio_costo,pais) -> None:
        super().__init__(id, nombre, precio_costo)
        self.pais=pais
    def precio_venta(self):
        return self.precio_costo*3.16

class Pedido_cant():
    def __init__(self,pieza: Pieza,cantidad: int,cliente: str,numero_pedido: int) -> None:
        self.pieza=pieza
        self.cantidad=cantidad
        self.numero_pedido=numero_pedido
        self.cliente=cliente

    def get_cantidad(self):
        return  self.cantidad

class Pedidos():
    def __init__(self) -> None:
        self.pedidos_cant=[]
   
    def agregar_pedidos_cant(self,pedido_cant:Pedido_cant):
        self.pedidos_cant.append(pedido_cant)
    
    def importe_pedido(self)->float:
        importe = 0
        for pedido_cant in self.pedidos_cant:
            importe += pedido_cant.cantidad*pedido_cant.pieza.precio_venta()
        return importe
    def contar_piezas_importadas(self):
        cantidad_pieza_pedido=0
        for pedido_cant in self.pedidos_cant:
            if isinstance(pedido_cant.pieza,Importada):
                cantidad_pieza_pedido+= pedido_cant.cantidad
        return cantidad_pieza_pedido


class Empresa():
    def __init__(self,nombre) -> None:
        self.nombre=nombre
        self.pedidos = []
    def agregar_pedidos_empresa(self, pedido: Pedidos)->None:
        self.pedidos.append(pedido)

    def importe_total(self)->float:
        importe_total = 0
        for pedido in self.pedidos:
            importe_total += pedido.importe_pedido()
        return importe_total
    
    def total_piezas_importadas(self) -> int:
        total_piezas=0
        for pieza in self.pedidos:
            total_piezas += pieza.contar_piezas_importadas()
        return total_piezas

pieza1=Nacional(123,"micro",20,1)
pieza2=Nacional(234,"fuente",10,2)
pieza3=Nacional(345,"pantalla",30,3)
pieza4=Importada(456,"teclado",5,"espana")
pieza5=Importada(567,"bocina",15,"francia")

pedido1=Pedido_cant(pieza1,1,"alvaro",1)
pedido2=Pedido_cant(pieza2,2,"alvaro",2)
pedido3=Pedido_cant(pieza3,3,"alvaro",3)
pedido4=Pedido_cant(pieza4,4,"carlos",4)
pedido5=Pedido_cant(pieza5,5,"carlos",5)

pedidos_alvaro=Pedidos()
pedidos_alvaro.agregar_pedidos_cant(pedido1)
pedidos_alvaro.agregar_pedidos_cant(pedido2)
pedidos_alvaro.agregar_pedidos_cant(pedido3)

pedidos_carlos=Pedidos()
pedidos_carlos.agregar_pedidos_cant(pedido4)
pedidos_carlos.agregar_pedidos_cant(pedido5)

pedidos=Empresa("importadora")
pedidos.agregar_pedidos_empresa(pedidos_alvaro)
pedidos.agregar_pedidos_empresa(pedidos_carlos)

print(pedidos.importe_total())
print(pedidos.total_piezas_importadas())