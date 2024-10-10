def movimiento_tren():
    altura=[5,2,1,4]
    energia_cinetica=0
    for x in range(len(altura)-1):
        print(f"{x}")
        while(altura[x]):
            energia_cinetica+=1
            if(altura[x]==1):
                    print(f"entrando en el if con energia cinetica {energia_cinetica} y altura {altura[x]}")
                    canal_agua=1
                    energia_cinetica=energia_cinetica-canal_agua
                    energia_cinetica=energia_cinetica-altura[x+1]
            print(f" altura: {altura[x]}")
            altura[x]=altura[x]-1
        print(f" energia cinetica final {energia_cinetica}")

movimiento_tren()