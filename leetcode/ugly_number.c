#include <stdio.h>
#include <stdbool.h>

bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    if (num == 1) return true;
    else return false;
}


int main(int argc, char const *argv[])
{
    int number = 11;
    printf("%d = %d\n", number, isUgly(number));
    return 0;
}
