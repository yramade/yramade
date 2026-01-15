#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int Score;

  printf("학점 산출 프로그램입니다. 국어 점수를 입력하세요.\n");
  printf("국어 점수 : ");
  scanf("%d", &Score);
  printf("\n");

  if(Score >= 90){
    printf("A학점입니다.\n");
    printf("최고입니다!\n");
  }else if(Score >= 80){
    printf("B학점입니다.\n");
    printf("조금만 더 노력해 보세요.\n");
  }else if(Score >= 70){
    printf("C학점입니다.\n");
    printf("딱 중간입니다!\n");
  }else if(Score >= 60){
    printf("D학점입니다.\n");
    printf("낙제 직전입니다!\n");
  }else {
    printf("F학점입니다.\n");
    printf("다음 학기에 다시 도전하세요!\n");
  }

  return;
}