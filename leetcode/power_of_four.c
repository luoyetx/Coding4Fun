#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int num) {
  return (num>0) && ((num&(num-1))==0) && ((num&0xaaaaaaaa)==0);
}
