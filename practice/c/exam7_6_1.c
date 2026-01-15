#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void DisplayGuGuDan(void);

extern int Number;
int flag;

void main() {
  flag = 0;
  printf("구구단 출력 프로그램입니다.\n");

  while (!flag)
  {
    printf("몇 단을 출력할까요? -> ");
    scanf("%d", &Number);

    if(Number > 1 && Number < 10) {
      flag = 1;
      printf("%d단을 선택하셨군요.\n\n", Number);
      DisplayGuGuDan();
    }else
      printf("2~9 사이의 숫자를 입력하세요.\n");
  }
  

  return;
}