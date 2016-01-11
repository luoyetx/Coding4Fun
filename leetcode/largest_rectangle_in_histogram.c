#include <stdio.h>
#include <stdlib.h>


int largestRectangleArea(int* height, int heightSize) {
    int* tower = malloc((heightSize+1)*sizeof(int));
    int* index = malloc((heightSize+1)*sizeof(int));
    int* area = malloc((heightSize+1)*sizeof(int));
    int length = 1;
    tower[0] = -1;
    index[0] = 0;
    int i;
    for (i=0; i<heightSize; i++) {
        // update
        if (height[i] > tower[length-1]) {
            tower[length] = height[i];
            index[length] = i;
            length++;
        }
        else {
            int j = length-1;
            while (j>0 && tower[j]>=height[i]) j--;
            tower[j+1] = height[i];
            length = j+2;
        }
        int j = length-1;
        area[i] = (i-index[j]+1)*height[i];
    }
    tower[0] = -1;
    index[0] = heightSize-1;
    length = 1;
    for (i=heightSize-1; i>=0; i--) {
        // update
        if (height[i] > tower[length-1]) {
            tower[length] = height[i];
            index[length] = i;
            length++;
        }
        else {
            int j = length-1;
            while (j>0 && tower[j]>=height[i]) j--;
            tower[j+1] = height[i];
            length = j+2;
        }
        int j = length-1;
        area[i] += (index[j]-i+1)*height[i] - height[i];
    }
    int area_max = 0;
    for (i=0; i<heightSize; i++) {
        if (area[i] > area_max) area_max = area[i];
    }
    free(area);
    free(tower);
    free(index);
    return area_max;
}


void main() {
    int height[] = {1};
    int area = largestRectangleArea(height, 1);
    printf("max area = %d\n", area);
}

