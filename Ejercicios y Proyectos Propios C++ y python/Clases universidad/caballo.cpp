#include <stdio.h>
#define N 8
#define ncuad N*N

void mover(int tablero[][N], int i, int pos_x, int pos_y, int *q);

const int ejex[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int ejey[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main(void) {
  int tablero[N][N];
  int i, j, q;

  // Inicializa el tablero a cero
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      tablero[i][j] = 0;
    }
  }

  // Pone el primer movimiento
  tablero[0][0] = 1;
  mover(tablero, 2, 0, 0, &q);

  if (q) {
    // Hay solución, muestra el tablero
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        printf("%3d ", tablero[i][j]);
      }
      putchar('\n');
    }
  } else {
    printf("\nNo existe solución\n");
  }

  return 0;
}

void mover(int tablero[][N], int i, int pos_x, int pos_y, int *q) {
  int k, u, v;
  k = 0;
  *q = 0;

  do {
    u = pos_x + ejex[k];
    v = pos_y + ejey[k];

    if (u >= 0 && u < N && v >= 0 && v < N) {
      if (tablero[u][v] == 0) {
        tablero[u][v] = i;
        if (i < ncuad) {
          mover(tablero, i+1, u, v, q);
          if (!*q) {
            tablero[u][v] = 0;
          }
        } else {
          *q = 1;
        }
      }
    }
    k++;
  } while (!*q && k < 8);
}