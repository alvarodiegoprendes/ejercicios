""" def unpaso(cantidad_peldanos):
    if cantidad_peldanos>0:
        print("se puede subir de un paso")

def dospasos(cantidad_peldanos):
    if cantidad_peldanos%2==0:
        print("se puede subir de dos pasos")

def trespaso(cantidad_peldanos):
    if cantidad_peldanos%3==0:
        print("se puede subir de tres pasos")

def unpaso_dospasos(cantidad_peldanos):

    while cantidad_peldanos>0:
        cantidad_peldanos-=1
        cantidad_peldanos-=2
    if cantidad_peldanos==0:
        print("se puede subir de uno y dos pasos")
    
def dospaso_unpaso(cantidad_peldanos):
    while cantidad_peldanos>0:
        cantidad_peldanos-=2
        cantidad_peldanos-=1
        if cantidad_peldanos==0:
            print("se puede subir de dos y un pasos")

def unopaso_trespasos(cantidad_peldanos):
    while cantidad_peldanos>0:
        cantidad_peldanos-=1
        cantidad_peldanos-=3
        if cantidad_peldanos==0:
            print("se puede subir de uno y tres pasos")

def trespasos_unpaso(cantidad_peldanos):
    while cantidad_peldanos>0:
        cantidad_peldanos-=3
        cantidad_peldanos-=1
        if cantidad_peldanos==0:
            print("se puede subir de tres y un pasos")

def dospasos_trespasos(cantidad_peldanos):
    while cantidad_peldanos>0:
        cantidad_peldanos-=2
        cantidad_peldanos-=3
        if cantidad_peldanos==0:
            print("se puede subir de dos y tres pasos")

def trespasos_dospasos(cantidad_peldanos):
    while cantidad_peldanos>0:
        cantidad_peldanos-=3
        cantidad_peldanos-=2
        if cantidad_peldanos==0:
            print("se puede subir de tres y dos pasos")
        
def llamando_funciones(cantidad_peldanos):
    unpaso(cantidad_peldanos)
    dospasos(cantidad_peldanos)
    trespaso(cantidad_peldanos)
    unpaso_dospasos(cantidad_peldanos)
    dospaso_unpaso(cantidad_peldanos)
    unopaso_trespasos(cantidad_peldanos)
    trespasos_unpaso(cantidad_peldanos)
    dospasos_trespasos(cantidad_peldanos)
    trespasos_dospasos(cantidad_peldanos)
 """
#llamando_funciones(5)

def TF(n:int, actual:int)->int:
    if actual == n:
        return 1
    if actual > n:
        return 0
    return TF(n, actual+1) + TF(n, actual+2) + TF(n, actual+3)

#print(f"without memoization {TF(3, 0)}")

def TF_M(n:int, actual:int, values:list)->int:
    if actual == n:
        return 1
    if actual > n:
        return 0
    if values[actual] != 0:
        return values[actual]
    result = TF_M(n, actual+1, values) + TF_M(n, actual+2, values) + TF_M(n, actual+3, values)
    if values[actual] == 0:
        values[actual] = result
    return result

n = 3
actual = 0
lista_valores = [0 for i in range(n+1)]

#print(f"with memoization {TF_M(n, actual, lista_valores)}")

def Fib(n:int,lista_fibo)->int:
    if n == 1 or n == 2:
        return 1
    if lista_fibo[n]!=0:
        return lista_fibo[n]
    resultado= Fib(n-1,lista_fibo) + Fib(n-2,lista_fibo)
    if lista_fibo[n]==0:
        lista_fibo[n]=resultado
    return resultado
n=800
lista_fibo=[0]*(n+1)
#print(lista_fibo)
print(Fib(n,lista_fibo))


def Potencia(a:int, b:int)->int:
    if b == 0:
        return 1
    return a * Potencia(a, b-1)


