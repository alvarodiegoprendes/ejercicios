carameloscaja=[2,4,5,6,6,6]
cantidadestudiantes=2
cajas=6
mitad=0
totalcaramelos=sum(carameloscaja)

def buscar_cajas_correctas(mitad,carameloscaja,cantidadestudiantes):
    fin=len(carameloscaja)-1
    inicio=0
    aux=0
    aux2=0
    while inicio<=fin:
        mitad=(inicio+fin)//2
        for i in range(len(carameloscaja)):
            aux+=(carameloscaja[i]//carameloscaja[mitad])
            aux2=aux
        if aux==cantidadestudiantes: 
            break
        if aux>cantidadestudiantes:
            inicio=mitad+1
            aux=0
        elif aux<cantidadestudiantes:
            fin=mitad-1
            aux=0
        if aux2>cantidadestudiantes:
            mitad=mitad+1
        if aux2<cantidadestudiantes:
            mitad=mitad-1
    if mitad==len(carameloscaja):
        mitad=mitad-1
    return mitad

def imprimir_resultados(totalcaramelos,carameloscaja,mitad):
    print(f"la cantidad de caramelos por estudiantes es de: {carameloscaja[mitad]}")
    caramelosninos=carameloscaja[mitad]*cantidadestudiantes
    caramelossobrantes=totalcaramelos-caramelosninos
    print(f"el dueno se puedo comer {caramelossobrantes} caramelos")

def llamadafunciones(carameloscaja,cantidadestudiantes):

    valorretornado=buscar_cajas_correctas(mitad,carameloscaja,cantidadestudiantes)
    imprimir_resultados(totalcaramelos,carameloscaja,valorretornado)

    '''while inicio<=fin:
        mitad=(inicio+fin)//2
        for i in range(len(carameloscaja)):
            aux+=(carameloscaja[i]//carameloscaja[mitad])
            aux2=aux
        if aux==cantidadestudiantes: 
            break
        if aux>cantidadestudiantes:
            inicio=mitad+1
            aux=0
        elif aux<cantidadestudiantes:
            fin=mitad-1
            aux=0
        if aux2>cantidadestudiantes:
            mitad=mitad+1
        if aux2<cantidadestudiantes:
            mitad=mitad-1
    if mitad==len(carameloscaja):
        mitad=mitad-1'''


llamadafunciones(carameloscaja,cantidadestudiantes)

