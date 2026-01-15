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

  if(YourHeight >= 175){
    printf("키가 크시네요.\n");
    printf("평균 키보다 %d cm만큼 더 크시네요.\n", (YourHeight - 175 ));
  }else {
    printf("키가 큰 편은 아니시군요.\n");
    printf("평균 키보다 %d cm만큼 작으시네요.\n", (175 - YourHeight));
  }

  return;
}