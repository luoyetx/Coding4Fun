#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseString(char *s) {
  int n = strlen(s);
  char *ss = (char*)malloc((n+1)*sizeof(char));

  int i;
  for (i=0; i<n; i++) {
    ss[i] = s[n-i-1];
  }
  ss[n] = '\0';

  return ss;
}

int main(int argc, char *argv[]) {
  return 0;
}
