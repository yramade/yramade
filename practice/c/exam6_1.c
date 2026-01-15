#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int YourHeight;

  printf("여러분의 키를 입력하세요. 단위는 cm입니다.\n");
  printf("나의 키 : ");
  scanf("%d", &YourHeight);

  printf("\n");
  printf("키가 %d이시군요.\n", YourHeight);
  
  if (YourHeight >= 175)
    printf("키가 크시네요.\n");

  return;
}