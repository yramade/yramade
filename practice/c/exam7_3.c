#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int a = 10;
  printf("지역 변수에 대한 테스트\n");
  printf("a의 값은 %d\n", a);

  if(a == 10){
    int a = 7; // if문 지역 변수
    printf("if 문의 코드 블록 안입니다.\n");
    printf("a의 값은 %d\n", a);
  }

  printf("if 문의 코드 블록 밖입니다.\n");
  printf("a의 값은 %d\n", a);

  return;
}