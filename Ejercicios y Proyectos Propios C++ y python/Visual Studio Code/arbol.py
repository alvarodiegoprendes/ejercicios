class Nodo: 
    def __init__(self,valor) -> None:
        self.valor=valor
        self.nodo_izquierdo=None
        self.nodo_derecho=None

class Arbol():
    def __init__(self,valor) -> None:
        self.raiz=Nodo(valor)

    def agregar_nodo(self,raiz,valor):
        if valor < self.raiz.valor:
            if self.raiz.nodo_izquierdo is None:
                self.raiz.nodo_izquierdo= Nodo(valor)
            else:
                raiz = self.raiz.nodo_izquierdo
                self.agregar_nodo(raiz,valor)
        elif valor > self.raiz.valor:
            if self.raiz.nodo_derecho is None:
                self.raiz.nodo_derecho= Nodo(valor)
            else:
                raiz = self.raiz.nodo_derecho
                self.agregar_nodo(raiz,valor)

    def __inorden_recursivo(self, raiz):
        if raiz is not None:
            self.__inorden_recursivo(self.raiz.nodo_izquierdo)
            print(self.raiz.valor, end=", ")
            self.__inorden_recursivo(self.raiz.nodo_derecho)


    def inorden(self):
        print("Imprimiendo árbol inorden: ")
        self.__inorden_recursivo(self.raiz)
        print("")

    def agregar(self,dato):
        self.agregar_nodo(self.raiz,dato)      


arbol= Arbol(4)
arbol.agregar(6)
arbol.inorden()