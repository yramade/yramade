#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int i, Number;

  printf("구구단 출력 프로그램입니다.\n");
  printf("출력할 단을 입력하세요 : ");

  scanf("%d", &Number);

  i = 1;
  while (i < 10) {
    printf("%d x %d = %d\n", Number, i, Number * i);
    i++;
  }

  return;
}