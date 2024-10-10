def estado_puertas(cantidad_celdas):
    #cantidad_vueltas=cantidad_celdas
    total=0
    lista=[False]*(cantidad_celdas)
    '''i=1
    j=1
    while i<=cantidad_celdas+1:
        while j<=cantidad_celdas+1:
            if i%j==0:
                lista[j-1]=not lista[j-1]
            j+=1
        i+=1
    for celda in  lista:
        print(celda)
    for h in range(len(lista)-1):
        if lista[h]==True:
            total=+1
    print(f"el total de prisioneros que escapo fue {total}")'''

    for i in range(1,cantidad_celdas+1):# vueltas
        for j in range(1,cantidad_celdas+1):#celdas
                if j%i==0:
                    lista[j-1]=not lista[j-1]   
    for celda in  lista:
        print(celda)
    for h in range(len(lista)):
        if lista[h]==True:
            total+=1
    print(f"el total de prisioneros que escapo fue {total}")

estado_puertas(10)