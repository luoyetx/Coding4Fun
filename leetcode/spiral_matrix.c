#include <stdlib.h>

enum DIRECTION {
    RIGHT, LEFT, UP, DOWN
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* spiralOrder(int **matrix, int matrixRowSize, int matrixColSize) {
    int l = matrixRowSize * matrixColSize;
    int *seq = (int *)malloc(l * sizeof(int));
    int left, top, right, bottom;
    enum DIRECTION direction = RIGHT;

    int i;
    int x, y;
    x = 0; y = -1;
    top = -1; bottom = matrixRowSize;
    left = -1; right = matrixColSize;
    for (int i = 0; i<l; i++) {
        switch (direction) {
        case RIGHT:
            y++;
            if (y == right) {
                x++; y--; top++;
                direction = DOWN;
            }
            break;
        case LEFT:
            y--;
            if (y == left) {
                x--; y++; bottom--;
                direction = UP;
            }
            break;
        case UP:
            x--;
            if (x == top) {
                x++; y++; left++;
                direction = RIGHT;
            }
            break;
        case DOWN:
            x++;
            if (x == bottom) {
                x--; y--; right--;
                direction = LEFT;
            }
            break;
        default:
            // never run here
            break;
        }
        printf("%d %d %d\n", x, y, matrix[x][y]);
        seq[i] = matrix[x][y];
    }
    return seq;
}
