#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



void main() {
  int i = 0;

  char buf[13];

  printf("소문자 12개를 입력해 보세요.\n");
  printf("입력 => ");

  while (i < 12)
  {
    scanf("%c", &buf[i]);
    i++;
  }

  printf("문자를 입력하셨군요. 대문자로 전환합니다.\n");

  for (i = 0; i < 12; i++) {
    if (buf[i] >= 'a' && buf[i] <= 'z')
      printf("%c", buf[i] - ('a' - 'A')); // 소문자의 경우에만 대문자로 변환
    else
      printf("%c", buf[i]); // 소문자가 아니면 그대로 출력
  }

  printf("\n");
  

  return;
}