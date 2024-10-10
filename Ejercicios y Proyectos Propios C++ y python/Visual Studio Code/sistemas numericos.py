def sistema_numerico(frase,base):
    valor_de_base=len(base)
    segundo_valor_base=len(frase)-1
    resultado=0

    for a in range(len(frase)):
        print(f"imprimiendo a: {a}")
        for b in range(len(base)):
            print(f"imprimiendo b: {b}")
            if frase[a]==base[b]:
                resultado=resultado + b*(valor_de_base**segundo_valor_base)
                print(f"impriendo valor base: {valor_de_base}")
                print(f"entrando en b con valor: {b}")
                print(f" imprimiendo resultado: {resultado}")
                segundo_valor_base-=1
    print(f"el resultado es: {resultado}")

sistema_numerico("baaca",('a','b','c'))