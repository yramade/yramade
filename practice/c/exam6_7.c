#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int TotalNumber, InputNumber;
  int i, j;

  printf("1부터 덧셈하는 프로그램입니다.\n");
  printf("마지막 값을 입력하세요.\n");
  printf("1부터 => ");
  scanf("%d", &InputNumber);

  printf("1부터 %d까지 덧셈합니다.\n", InputNumber);

  TotalNumber = 0;
  for(i = 1, j = 0; i <= InputNumber; i++, j++){
    TotalNumber += i;
    printf("[%d행] TotalNumber의 값 : %d\n", j, TotalNumber);
  }

  printf("1부터 %d까지의 덧셈 결과는 %d입니다.\n", InputNumber, TotalNumber);

  return;
}