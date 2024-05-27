import itertools
import sys
lista=[95.95, 73.35, 78.85, 78.85, 22.85, 90.45, 64.15, 88.45, 37.12, 90.45, 37.12, 37.12, 95.95, 14.18, 78.85, 78.85, 64.15, 90.45, 90.45, 56.08, 66.75]
opcion= 0
valor=662.25
while opcion !=4:
    print(" 1- Ingresar el total: ")
    print(" 2- Ingresar sumandos: ")
    print(" 3- Modificar sumandos: ")
    print(" 4- salir: ")
    sys.stdin.flush()
    opcion=int(input())
    match opcion:
        case 1:
            valor=float(input("digite el valor de la suma a la cual desea llegar: "))
        case 2:
            numero=float(input("digite los sumandos: "))
            lista.append(numero)
            print(lista)
        case 3:
            print(f"Estos son los valores que acaba de ingresar:\n{lista}\n\n\n")
            posicion=int(input("ingrese el valor que desea eliminar: "))
            lista.remove(posicion)
        case 4: 
            break
       

# Generar todas las combinaciones posibles
combinations = []
for r in range(len(lista)):
    combinations += itertools.combinations(lista, r)

# Comprobar si la suma de cada combinación es igual a la suma objetivo
result = []
for combo in combinations:
    if sum(combo) == valor:
        result.append(combo)

# Mostrar las combinaciones encontradas
if result:
    for combo in result:
        print(combo)
else:
    print("no se encontraron resultados")