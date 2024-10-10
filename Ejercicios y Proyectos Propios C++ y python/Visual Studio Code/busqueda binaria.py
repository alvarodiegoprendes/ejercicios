def buscarnumero(lista,numero):
    inicio=0
    fin=len(lista)-1
    while inicio<=fin:
        medio=(inicio+fin)//2
        if numero==lista[medio]:
            return True
        if numero<lista[medio]:
            fin=medio
        if numero>lista[medio]:
            inicio=medio+1    
    return False
lista=[1,2,3,4,5]
numero=6

if buscarnumero(lista,numero):
    print("el numero fue encontrado")
else:
    print("el numero no fue encontrado")