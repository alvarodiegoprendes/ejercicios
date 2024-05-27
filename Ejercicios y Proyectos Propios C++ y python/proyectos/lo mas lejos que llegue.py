lista=[]
bandera= True
valor=float(input("digite el valor de la suma a la cual desea llegar: "))
while bandera==True:
    numero=float(input("digite los sumandos: "))
    lista.append(numero)
    opcion=input("si desea agregar otro numero presione 's', si no desea agregar mas ninguno presione 'n': ")
    if opcion=='n' or opcion=='N':
        bandera=False

print(f"Estos son los valores que acaba de ingresar:\n{lista}\n\n\n")
combinaciones=[]
aux1=0
suma=0
i=0
j=0
lista_almacen=[]
def sumatoria(suma,aux1,j,valor):
        while j < len((lista)):
            #print(f"mostrando j: {j}->{lista[j]}")
            if suma==0:
                suma=(lista[i]+lista[j])
                lista_almacen.append(lista[j])
            else:
                suma=suma+lista[j] 
                lista_almacen.append(lista[j])   
            if suma==valor:
                combinaciones.append([lista[i],lista_almacen[0:]])
                suma=0
                lista_almacen.clear()
            elif j==(len(lista)-1) and aux1==0:
                print("entro")
                j=0
                j=+1
                aux1=+1
                suma=0
                lista_almacen.clear()
                sumatoria(suma,aux1,j,valor)
            elif j==(len(lista)-1) and aux1>0:
                print("entrando")
                j=aux1
                j+=1 
                aux1+=1
                suma=0
                lista_almacen.clear()
                sumatoria(suma,aux1,j,valor)
            j=j+1

while i < len(lista):
        #print(f"mostrando i: {i}->{lista[i]}")
        j=i+1
        #print(f"valor de j: {j}")
        #print(f"valor de suma: {suma}")
        sumatoria(suma,aux1,j,valor)
        suma=0
        i=i+1

resultado=[]
for valores in combinaciones:
     if valores not in resultado:
          resultado.append(valores)

if resultado:
    print("****LAS COMBINACIONES SON LAS SIGUIENTES****")
    print(f"{resultado}")
    
else:
   print("no se encontraron combinaciones")
input()