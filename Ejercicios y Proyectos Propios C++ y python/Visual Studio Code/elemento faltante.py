def buscar_elemento(lista,cantidad_elementos):
    lista_completa=[x for x in range(cantidad_elementos+1)]
    lista_final=lista_completa-lista
    print(f"{lista_completa}")
buscar_elemento([0,5,1,4,2],5)