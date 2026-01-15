#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawStar();

void main() {
  int num;
  int line;

  printf("정적 변수를 사용한 별 출력 프로그램.\n");
  printf("몇 줄을 출력할까요? : ");
  scanf("%d", &line);
  
  printf("\n");

  for(num = 0; num < line; num++)
    drawStar();

  return;
}

void drawStar() {
  static int number = 1;

  int i;

  for(i = 0; i < number; i++)
    printf(" * ");
 
  number++;
  printf("\n");
}