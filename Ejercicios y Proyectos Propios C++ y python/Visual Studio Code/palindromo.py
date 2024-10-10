""" def palindromo(palabra,inicio,fin,contador)->int:
    while inicio<=fin:
        if palabra[inicio]!=palabra[fin]:
            fin-=1
            contador=+1
        return contador+palindromo(palabra,inicio+1,fin-1,contador)
    return 0
    #print(f"{contador}")
contador=0
palabra=list("somois")
inicio=0
fin=(len(palabra)-1)
#print(f"{palindromo(palabra,inicio,fin,contador)}") """

def palindromo(palabra, inicio, fin, contador):
    if inicio >= fin:
        return contador
    
    if palabra[inicio] != palabra[fin]:
        fin-=1
        contador += 1
    
    return palindromo(palabra, inicio + 1, fin - 1, contador)

contador = 0
palabra = list("somois")
inicio = 0
fin = len(palabra) - 1
resultado = palindromo(palabra, inicio, fin, contador)
print(resultado)