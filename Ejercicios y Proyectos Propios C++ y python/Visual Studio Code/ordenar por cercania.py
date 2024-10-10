lista=[5,12,7,10,3]
orden=[]
pivote=7
def ciclo_for():
        for x in range(len(lista)):
            diferencia=lista[x]-pivote
            for y in range(len(lista)):
                diferencia2=lista[y]-pivote
                if diferencia<diferencia2:
                    orden.append(lista[x])
                else :
                    orden.append(lista[y])

          
def ordenar_cercania():
    for buscar in range(len(lista)):
        if pivote==lista[buscar]:
            orden.append(pivote)
            lista.remove(pivote)
            break
    for x in range(len(lista)):
        diferencia=lista[x]-pivote
        if diferencia<0:
            diferencia=-(diferencia)
        for y in range(len(lista)):
            diferencia2=lista[y]-pivote
            if diferencia2<0:
                diferencia2=-(diferencia2)
            if diferencia<diferencia2:
                orden.append(lista[x])
            if diferencia2<diferencia:
                orden.append(lista[y])
            print(f"mostrando lista en x {lista[x]} y diferencia: {diferencia}")
            print(f"mostrando lista en y {lista[y]} y diferencia2: {diferencia2}")
            print(f"ordenandose {orden}")


    print(f"{orden}")
    eliminardobles=[]
    for elementos in orden:
        if elementos not in eliminardobles:
            eliminardobles.append(elementos)
    casi_terminada=list(set(lista)-set(eliminardobles))
    eliminardobles=eliminardobles+casi_terminada
    print(f" el orden es el siguiente: {eliminardobles}")                   

ordenar_cercania()