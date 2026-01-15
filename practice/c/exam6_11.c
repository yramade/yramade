#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  char ch = 'a';

  printf("무한 루프 프로그램입니다.\n");
  printf("출력할 문자를 입력하세요 : ");

  while (ch < 'z')
  {
    printf("%c", ch);
    /* ch++; */
  }
  

  return;
}