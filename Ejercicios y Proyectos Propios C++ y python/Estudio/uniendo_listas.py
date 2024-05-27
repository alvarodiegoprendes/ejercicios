# Listas de ejemplo
numeros = [30, 20, 60]
alimentos = ['arroz', 'frijol', 'calabaza']

# Combinar las dos listas en pares de elementos
pares = zip(numeros, alimentos)
print(list(pares))
# Crear un diccionario a partir de los pares
diccionario = dict(pares)

print(diccionario)
