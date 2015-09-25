#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int left, right, mid;
    left = -1; right = matrixRowSize;
    while (left < right-1) {
        mid = (left + right) / 2;
        if (matrix[mid][0] > target) right = mid;
        else left = mid;
    }
    if (left == -1) return false;
    int row = left;
    left = -1; right = matrixColSize;
    while (left < right-1) {
        mid = (left + right) / 2;
        if (matrix[row][mid] > target) right = mid;
        else left = mid;
    }
    if (left == -1) return false;
    if (matrix[row][left] == target) return true;
    else return false;
}


int main(int argc, char *argv[]) {
    int a[][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int **matrix;
    matrix = (int**)malloc(3*sizeof(int*));
    int i;
    for (i=0; i<3; i++) {
        matrix[i] = (int*)a + 4*i;
    }
    int target = 1;
    printf("target = %d, bool = %d\n", target, searchMatrix(matrix, 1, 1, target));
    return 0;
}
