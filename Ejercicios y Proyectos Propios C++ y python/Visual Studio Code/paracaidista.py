mapa = [[3, 1, 9,  2,  1, 10],
        [5, 5, 6,  7,  8, 11],
        [7, 1, 1,  2, 15, 12],
        [1, 5, 8, 11, 14,  7]]
k=3
mov_filas  = [-1,0,1,0]
mov_columnas=[0,1,0,-1]
mask=[[False]*6 for x in range(4)]
total=0

def Paracaidista(mapa,mask,k,pos_fila,pos_columna,total):
    total=1
    mask[pos_fila][pos_columna]=True
    for i in range(len(mov_filas)):
        paso_fila= pos_fila + mov_filas[i]
        paso_columna = pos_columna + mov_columnas[i]
        if (paso_fila>=0 and paso_fila<len(mapa) and paso_columna>=0 and paso_columna<len(mapa[0]) and not mask[paso_fila][paso_columna] and abs((mapa[pos_fila][pos_columna])-(mapa[paso_fila][paso_columna]))<=k):
        
            total += Paracaidista(mapa,mask,k,paso_fila,paso_columna,total)

    return total   

print(Paracaidista(mapa,mask,k,1,2,total))





""" drow  = [-1,0,1,0]
dcol=[0,1,0,-1]
def Paracaidista(mapa, mask, c_row, c_col, k):
    total = 1

    mask[c_row][c_col] = True
    for i in range(len(drow)):
        n_row = c_row + drow[i]
        n_col = c_col + dcol[i]
        if n_row >= 0 and n_row < len(mapa) and n_col >= 0 and n_col < len(mapa[0]) and not mask[n_row][n_col] and abs(mapa[c_row][c_col] - mapa[n_row][n_col] <= k):
            total += Paracaidista(mapa, mask, n_row, n_col, k)
    return total


mapa = [[3, 1, 9,  2,  1, 10],
        [5, 5, 6,  7,  8, 11],
        [7, 1, 1,  2, 15, 12],
        [1, 5, 8, 11, 14,  7]]

mask = [[False]*6 for x in range(4)]
k = 3
print(Paracaidista(mapa, mask, 1, 2, k)) """