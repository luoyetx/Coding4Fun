#include <stdio.h>
#include <stdlib.h>

int pos[100];
int vis[100];
int global_row;

void getResult(int* numbers, int n, int k, int** result, int numRows) {
    int i=0;
    if (k == n) {
        for (i=0; i<n; i++) {
            result[global_row][i] = numbers[pos[i]];
        }
        global_row++;
        return;
    }

    for (i=0; i<n; i++) {
        if (vis[i] == 0) {
            pos[k] = i;
            vis[i] = 1;
            getResult(numbers, n, k+1, result, numRows);
            vis[i] = 0;
        }
    }
}

/* Return the list of permutation results */
/* *numRows stores the number of permutation arrays */
int **permute(int numbers[], int n, int *numRows) {
    int i;
    *numRows = 1;
    for (i=1; i<=n; i++) {
        *numRows *= i;
    }
    // malloc memory
    int** result = (int**)malloc(sizeof(int*) * *numRows);
    for (i=0; i<*numRows; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
    }
    global_row = 0;
    for (i=0; i<n; i++) vis[i] = 0;
    getResult(numbers, n, 0, result, *numRows);

    return result;
}

int main(int argc, char* argv[]) {
    int a[3] = {1, 2, 3};
    int** result = NULL;
    int numRows = 0;

    result = permute(a, 3, &numRows);
    int i, j;
    for (i=0; i<numRows; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
