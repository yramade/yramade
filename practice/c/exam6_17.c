#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  char a = 'a';
  int i, j;
  int n = 0;

  for(i = 0; i < 26; i++) {
    for(j = 0; j <= i; j++) {
      if( n >= 26 ) break;

      printf("%c", a + n);
      n++;
    }
    printf("\n");
    if( n >= 26 ) break;
  }

  return;
}