#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int i, j;
  i = j = 0;

  printf("continue문의 테스트입니다.\n");

  do {
    printf("do-while문의 %d번째 반복입니다.\n", i);

    for(j = 0; j < 10; j++){
      if(j == 5)
        continue;
      printf("  for문의 %d번째 반복입니다.\n", j);
    }
    i++;
  } while (i < 5);
  printf("프로그램을 종료합니다.\n");

  return;
}