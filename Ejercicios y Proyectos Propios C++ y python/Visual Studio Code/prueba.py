def Satisfechos(cantidad, lista):
    total_satisfechos = 0
    for i in lista:
        total_satisfechos += i//cantidad
    return total_satisfechos

def Reparticion(total_ninnos: int, cajas: list) -> int:
    inicio = 0
    fin = max(cajas)
    while inicio < fin:
        mitad = (inicio + fin)//2
        satisfechos = Satisfechos(mitad, cajas)
        if satisfechos >= total_ninnos:
            inicio = fin
        if satisfechos < total_ninnos:
            fin = mitad
    return mitad

#print(Reparticion(10, [4, 2, 8, 6, 5]))

def Iguales(l1, l2):
    print(l1)
    print(l2)
    return l1 == l2

def ADN(secuence, mutation):
    position = -1
    for i in range(0, len(secuence)):
        if secuence[i] == mutation[0]:
            if Iguales(secuence[i:len(mutation)+1], mutation):
                position = i+1
                break
    return position

#print(ADN("ACGCCT", "CT"))

def MaxArea(heights):
    i = 0
    j = len(heights) - 1
    area = 0
    while i<j:
        area = max(area, (j-i)*min(heights[i], heights[j]))
        if heights[i] < heights[j]:
            i += 1
        else:
            j -= 1
    return area


heights = [1,4,3,4,6,2]
#print(MaxArea(heights))

def ParkSide(n: int, s: int):
    spaces = 0
    next_row = 0
    incremento = 0
    paso = 0
    while n > 0:
        fila = ' ' * spaces
        value = s + next_row
        for i in range(0, n):
            value += i + paso
            if value > 9:
                #print(value)
                value -= 9 #* value//10
            fila += str(value)
        print(fila)
        n -= 1
        spaces += 1
        next_row += (1 + incremento)
        incremento += 1
        paso += 1

#ParkSide(6, 1)

lst = [2, 1, 2]
lst[::2] = range(2)
#print(lst)

def Fib(n:int):
    if n == 1 or n == 2:
        return 1
    return Fib(n-1) + Fib(n-2)

termino = 40
#print(Fib(termino))

def Fib(n:int, memo:list()):
    if n == 1 or n == 2:
        return 1
    if memo[n] != 0:
        return memo[n]
    result = Fib(n-1, memo) + Fib(n-2, memo)
    if memo[n] == 0:
        memo[n] = result
    return result

#print(Fib(300, [0]*(300 + 1)))

def Escalera(n:int, actual:int) -> int:
    if actual == n:
        return 1
    if actual > n:
        return 0
    return Escalera(n, actual+1) + Escalera(n, actual+2) + Escalera(n, actual+3)

peldannos = 28
#print(Escalera(peldannos, 0))

def Escalera(n:int, actual:int, memo: list()) -> int:
    if actual == n:
        return 1
    if actual > n:
        return 0
    if memo[actual] != 0:
        return memo[actual]
    result = Escalera(n, actual+1, memo) + Escalera(n, actual+2, memo) + Escalera(n, actual+3, memo)
    if memo[actual] == 0:
        memo[actual] = result
    return result

#print(Escalera(200, 0, [0]*200))

def Descomposicion_Sumandos(n:int, index:int, total:int, result: list()):
    if n == 0:
        print(result)
        total+=1
    del result[-1]
    for i in range(index, n+1):
        result.append(i)
        total = Descomposicion_Sumandos(n - i, i, total, result)
    return total

#print(Descomposicion_Sumandos(4, 1, 0, []))

def Lcs(x: str, y: str, m: int, n: int):
    if m == 0 or n == 0:
        return 0
    if x[m - 1] == y[n - 1]:
        return 1 + Lcs(x, y, m - 1, n - 1)
    else:
        return max(Lcs(x, y, m, n - 1), Lcs(x, y, m - 1, n))

#print(Lcs("COMIERAMOS", "ACOMETIERAMOS", 10, 13))


def Dados_Valor(dados:list(), valor:int, tirada:int):
    if tirada == len(dados):
        if valor == sum(dados):
            print(dados)
    else:
        for i in range(1, 7):
            dados[tirada] = i
            Dados_Valor(dados, valor, tirada + 1)

#print(Dados_Valor([0]*6, 8, 0))

def Particion(gifts: list(), subset1: int, subset2: int, pos: int) -> int:
    if pos == len(gifts):
        return abs(subset1 - subset2)
    x = Particion(gifts, subset1 + gifts[pos], subset2, pos+1)
    y = Particion(gifts, subset1, subset2 + gifts[pos], pos+1)
    return min(x, y)

gifts = [5, 4, 3] #[23, 45, 34, 12, 5, 98, 99, 4, 189, 1, 4]
#print(Particion(gifts, 0, 0, 0))

def InsercionesPalindromo(s: str, first: int, last: int) -> int:
    if first >= last:
        return 0
    if s[first] == s[last]:
        return InsercionesPalindromo(s, first+1, last-1)
    s1 = 1 + InsercionesPalindromo(s, first+1, last)
    s2 = 1 + InsercionesPalindromo(s, first, last-1)
    return min(s1, s2)

str = 'somois'
#print(InsercionesPalindromo(str, 0, len(str)-1))

def knapSack(items: list(), weights: list(), w: int, p: int, u: int, index: int)-> int:
    if index == len(items):
        if p <= w:
            return u
        return 0
    else:
        p += weights[index]
        u += items[index]
        r1 = knapSack(items, weights, w, p, u, index + 1)
        p -= weights[index]
        u -= items[index]
        r2 = knapSack(items, weights, w, p, u, index + 1)
        return max(r1, r2)

#print(knapSack([100, 160, 120], [10, 20, 30], 20, 0, 0, 0))

def PermutationsWithoutRepetition(numbers: list(), index:int, selected:list()):
    if index == len(numbers):
        print(selected)
    else:
        for i in range(0, len(numbers)):
            selected[index] = i
            PermutationsWithoutRepetition(numbers, index+1, selected)
            selected[index] = i

#PermutationsWithoutRepetition([1, 2, 3, 4], 0, [0]*4)

def PermutationsWithRepetition(numbers: list(), index:int, selected:list()):
    if index == len(numbers):
        print(selected)
    else:
        for i in range(0, len(numbers)):
            selected[index] = numbers[i]
            PermutationsWithRepetition(numbers, index+1, selected)
            selected[index] = 0

#PermutationsWithRepetition([1, 2, 3, 4], 0, [0]*4)

def GenerateSubSets(numbers: list(), index: int, subSet:list()):
    if index == len(numbers):
        result = []
        for i in range(0, len(subSet)):
            if subSet[i]:
                result.append(numbers[i])
        print(result)
    else:
        subSet[index] = True
        GenerateSubSets(numbers, index+1, subSet)
        subSet[index] = False
        GenerateSubSets(numbers, index+1, subSet)

#GenerateSubSets([1, 2, 3, 4], 0, [False]*4)

def Taxista(x:int, y:int) -> int:
    if x == 0 or y == 0:
        return 1
    return Taxista(x - 1, y) + Taxista(x, y - 1)

#print(Taxista(5, 3))

drow = [-1, 0, 1, 0]
dcol = [ 0, 1, 0, -1]

def SalidaLaberinto(mapa: list(), mask: list(), c_row: int, c_col : int) -> bool:
    print(f'{c_row} : {c_col}')
    if c_row == len(mapa)-1 and c_col == len(mapa[0])-1:
        return True
    else:
        mask[c_row][c_col] = True
        for i in range(len(drow)):
            if c_row + drow[i] >= 0 and c_row + drow[i] < len(mapa) and c_col + dcol[i] >= 0 and c_col + dcol[i] < len(mapa[0]) and not(mask[c_row + drow[i]][c_col + dcol[i]]) and mapa[c_row + drow[i]][c_col + dcol[i]] != 1:
                if SalidaLaberinto(mapa, mask, c_row + drow[i], c_col + dcol[i]):
                    return True
        mask[c_row][c_col] = False
        return False

mapa1 = [[0, 1, 0, 0, 0],
         [0, 0, 0, 1, 1],
         [0, 1, 0, 0, 0]]

mask1 = [[False]*5 for x in range(3)]
#print(SalidaLaberinto(mapa1, mask1, 0, 0))
lista = [False for x in range(5)]
#print(lista)
mapa2 = [[0, 1, 0, 1, 0],
         [0, 1, 0, 1, 0],
         [0, 0, 0, 1, 0],
         [0, 1, 0, 1, 0],
         [0, 0, 0, 0, 0]]

mask2 = [[False]*5 for x in range(5)]
#print(SalidaLaberinto(mapa2, mask2, 0, 0))

#drow = [0, 1]
#dcol = [1, 0]

def Caminos(c_row: int, c_col: int, f_row: int, f_col: int, total: int) -> int:
    if c_row == f_row and c_col == f_col:
        total+=1
    else:
        for i in range(2):
            if c_row <= f_row and c_col <= f_col:
                total = Caminos(c_row+drow[i], c_col+ dcol[i], f_row, f_col, total)
    return total

#print(Caminos(0, 0, 3, 5, 0))

def Paracaidista(mapa: list(), mask: list(), c_row: int, c_col : int, k: int) -> int:
    total = 1
    print(f'{c_row} : {c_col} - {total}')
    mask[c_row][c_col] = True
    for i in range(len(drow)):
        n_row = c_row + drow[i]
        n_col = c_col + dcol[i]
        if n_row >= 0 and n_row < len(mapa) and n_col >= 0 and n_col < len(mapa[0]) and not mask[n_row][n_col] and abs(mapa[c_row][c_col] - mapa[n_row][n_col] <= k):
            total += Paracaidista(mapa, mask, n_row, n_col, k)
    return total


# def f():
#     total++
#     mask[pos] = true
#     for pos in adj_pos:
#         if comprobar que te puedas mover:
#             f()

mapa = [[3, 1, 9,  2,  1, 10],
        [5, 5, 6,  7,  8, 11],
        [7, 1, 1,  2, 15, 12],
        [1, 5, 8, 11, 14,  7]]

mask = [[False]*6 for x in range(4)]
k = 3
print(Paracaidista(mapa, mask, 1, 2, k))

conjunto = {3, 2, 1, 2}
#print(conjunto)