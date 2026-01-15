#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100

void main() {
  int buf[MAX][MAX];
  int i, j, k = 1;
  int size;

  printf(" 출력할 행의 수를 입력하세요. : ");
  scanf("%d", &size);
  
  printf("\n");

  // 초기화 과정, 0으로 채움
  for (i = 0; i < size; i++)
  {
    for (j = size - i -1; j < size; j++)
      buf[i][j] = k++;
  }

  // 출력 과정
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (buf[i][j] == 0)
        printf("    ");
      else
        printf("%4d", buf[i][j]);
    }
    printf("\n");
  }

  return;
}