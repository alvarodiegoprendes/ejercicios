from abc import  abstractmethod

class IVisitor():
    @abstractmethod
    def can_access(self, autorizados: list)-> bool:
        pass
        
class Persona(IVisitor):
    def __init__(self, id: str, name: str) -> None:
        self.id = id
        self.name = name

    def can_access(self, autorizados: list) -> bool:
        for visitor in autorizados:
            if isinstance(visitor, Persona) and visitor.id == self.id:
                return True
        return False
    
class Automovil(IVisitor):
    def __init__(self, plate: str, type: str) -> None:
        self.plate = plate
        self.type = type

    def can_access(self, autorizados: list)-> bool:
        for visitor in autorizados:
            if isinstance(visitor, Automovil) and visitor.plate == self.plate:
                return True
        return False
        

class Centro_investigacion:
    def __init__(self) -> None:
        self.autorizados = []

    def add_visitor(self, visitor: IVisitor) -> None:
        self.autorizados.append(visitor)

    def verify_access(self, visitor: IVisitor) -> bool:
        if visitor.can_access(self.autorizados):
            return True
        return False
    

centro_investigacion = Centro_investigacion()
visitor_1 = Persona("123", "Alvaro")
visitor_2 = Persona("234", "Carlos")
visitor_3 = Automovil("HA1234", "Camion")

centro_investigacion.add_visitor(visitor_1)
centro_investigacion.add_visitor(visitor_2)
centro_investigacion.add_visitor(visitor_3)


#for visitor in centro_investigacion.autorizados:
#    if isinstance(visitor, Persona):
#        print(visitor.name)
#    else:
#        print(visitor.type)

visitor_4 = Persona("123", "Alvaro")
visitor_5 = Persona("456", "Pepe")
visitor_6 = Automovil("HA1234","Camion")

print(centro_investigacion.verify_access(visitor_4))

print(centro_investigacion.verify_access(visitor_5))
print(centro_investigacion.verify_access(visitor_6))