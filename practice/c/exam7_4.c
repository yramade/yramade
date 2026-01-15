#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void DisplayGuGuDan(void);

int Number;
int flag;

void main() {
  flag = 0;
  printf("구구단 출력 프로그램.\n");

  while (!flag)
  {
    printf("몇 단을 출력할까요? : ");
    scanf("%d", &Number);
    
    if(Number > 1 && Number < 10){
      flag = 1;
      printf("%d 단을 출력합니다.\n", Number);
      DisplayGuGuDan();
    }else
      printf("2~9 사이의 숫자를 입력하세요.\n");
  }
  

  return;
}

void DisplayGuGuDan(void){
  int i;
  for(i=1; i<10; i++){
    printf("%d X %d = %d\n", Number, i, ( Number * i ));
  }
}