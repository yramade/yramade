#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Exponential(int, int);

void main() {
  int ret;

  printf("자승 값을 구해봅시다.\n");

  printf("2의 3승은 얼마일까요?\n");
  ret = Exponential(2, 3);
  printf("2의 3승은 %d이군요.\n", ret);

  printf("\n");
  printf("3의 6승은 얼마일까요?\n");
  ret = Exponential(3, 6);
  printf("3의 6승은 %d이군요.\n", ret);

  return;
}

int Exponential(int Num, int Range) {
  int ret = Num; // 변수 Range가 1씩 감소하며, Num값은 고정

  if(Range > 1){ // 파라미터로 넘어온 변수 Range의 값을 비교하여 1보다 작으면 중지
    ret = Num * Exponential(Num, Range - 1);
    return ret; 
  }
  return ret; // 재귀 호출이 중지되면, 현재의 Num값을 리턴
}