#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100

void main() {
  int buf[MAX];
  int i, size;

  printf("배열을 이용한 Matrix 출력\n");
  printf("Matrix의 크기를 입력하세요 : ");

  scanf("%d", &size);
  printf("\n");

  for (i = 0; i < size * size; i++)
    buf[i] = i + 1;
  
  for (i = 0; i <= size * size; i++)
  {
    printf("%4d", buf[i - 1]);
    if( i % size == 0 )
      printf("\n");
  }
  

  return;
}