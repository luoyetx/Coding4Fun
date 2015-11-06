#include <stdio.h>

int addDigits(int num) {
    int r = num % 9;
    if (num != 0 && r == 0) r = 9;
    return r;
}

int main(int argc, char* argv[]) {
    return 0;
}
