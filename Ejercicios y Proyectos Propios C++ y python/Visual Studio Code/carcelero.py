def estado_puertas(cantidad_celdas):
    #cantidad_vueltas=cantidad_celdas
    total=0
    lista=[False for x in range(cantidad_celdas)]
    for i in range(cantidad_celdas):# vueltas
        for j in range(cantidad_celdas):#celdas
            while i>0:
                if j%i==0:
                    lista[j]=not lista[j]
    for celda in  lista:
        print(celda)
    for h in range(len(lista)-1):
        if lista[h]==True:
            total=+1
    print(f"el total de prisioneros que escapo fue {total}")

estado_puertas(8)
