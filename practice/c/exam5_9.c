#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int i, num;
  int total;
  printf("시그마 연산을 해봅시다\n");
  printf("원하는 숫자를 입력하세요.\n");
  scanf("%d", &num);

  i = 1;
  total = 0;
  while( i <= num )
    total += i++; 

  printf("1부터 %d까지 덧셈하면 %d입니다.\n", num, total);
  return;
}