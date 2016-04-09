#include <stdio.h>
#include <stdlib.h>

int search(int **f, int **h, int rows, int cols, int y, int x) {
  if (f[y][x] != -1) return f[y][x];
  f[y][x] = 1;

  int top, bottom, left, right;
  top = bottom = left = right = -1;
  if (y > 0 && h[y-1][x] < h[y][x]) {
    top = search(f, h, rows, cols, y-1, x);
    if (top+1 > f[y][x])
      f[y][x] = top+1;
  }
  if (y < rows-1 && h[y+1][x] < h[y][x]) {
    bottom = search(f, h, rows, cols, y+1, x);
    if (bottom+1 > f[y][x]) {
      f[y][x] = bottom+1;
    }
  }
  if (x > 0 && h[y][x-1] < h[y][x]) {
    left = search(f, h, rows, cols, y, x-1);
    if (left+1 > f[y][x]) {
      f[y][x] = left+1;
    }
  }
  if (x < cols-1 && h[y][x+1] < h[y][x]) {
    right = search(f, h, rows, cols, y, x+1);
    if (right+1 > f[y][x]) {
      f[y][x] =  right+1;
    }
  }

  return f[y][x];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
  int **f = malloc(matrixRowSize*sizeof(int*));
  int i, j;
  for (i=0; i<matrixRowSize; i++) {
    f[i] = malloc(matrixColSize*sizeof(int));
    for (j=0; j<matrixColSize; j++) f[i][j] = -1;
  }

  int res = 0;
  for (i=0; i<matrixRowSize; i++) {
    for (j=0; j<matrixColSize; j++) {
      if (search(f, matrix, matrixRowSize, matrixColSize, i, j) > res) {
        res = f[i][j];
      }
    }
  }

  for (i=0; i<matrixRowSize; i++) {
    free(f[i]);
  }
  free(f);

  return res;
}

int main(int argc, char *argv[]) {
  int n, m, i, j;
  n = m = 3;
  int **mat = malloc(n*sizeof(int*));
  for (i=0; i<n; i++)
    mat[i] = malloc(m*sizeof(int));
  mat[0][0] = 3; mat[0][1] = 4; mat[0][2] = 5;
  mat[1][0] = 3; mat[1][1] = 2; mat[1][2] = 6;
  mat[2][0] = 2; mat[2][1] = 2; mat[2][2] = 1;

  printf("ans = %d\n", longestIncreasingPath(mat, n, m));
  return 0;
}
