#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int* xs = (int*)malloc(matrixColSize*sizeof(int));
    int* ys = (int*)malloc(matrixRowSize*sizeof(int));
    memset(xs, 0, matrixColSize*sizeof(int));
    memset(ys, 0, matrixRowSize*sizeof(int));

    for (int i=0; i<matrixRowSize; i++) {
        for (int j=0; j<matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                xs[j] = 1;
                ys[i] = 1;
            }
        }
    }
    for (int i=0; i<matrixRowSize; i++) {
        if (ys[i] == 1) {
            for (int j=0; j<matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j=0; j<matrixColSize; j++) {
        if (xs[j] == 1) {
            for (int i=0; i<matrixRowSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    return 0;
}
