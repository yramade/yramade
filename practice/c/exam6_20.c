#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  // 세 개의 반복문으로 구현
  int i, j, t;

  for(t = 1; t < 10; t += 3){
    for(i = 1; i < 10; i++){
      for(j = t; j < (t + 3); j++){
        printf("%d X %d = %d\t", j, i, i * j);
      }
      printf("\n");
    }
    printf("\n");
  }

  return;
}