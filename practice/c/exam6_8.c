#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int TotalNumber, InputNumber;
  int i;

  printf("1부터 덧셈하는 프로그램입니다.\n");
  printf("마지막 값을 입력하세요.\n");
  printf("1부터 => ");
  scanf("%d", &InputNumber);

  printf("1부터 %d까지 덧셈합니다.\n", InputNumber);

  /*
    프로그램이 실행되기 전까지 제어 변수 i의 값을 알 수 없을 때,
    혹은 제어변수를 두 개이상 사용할 경우 for 문 외부에서 제어변수를 초기화하는 것이 더 편리합니다.
  */

  TotalNumber = 0;
  i = 1;
  for(; i <= InputNumber;) {
    TotalNumber += i;
    printf("TotalNumber의 값: %d\n", TotalNumber); // 중간 결과 출력
    i++;
  }

  /* 
    제어 변수의 연산 코드가 너무 길다면 for 문 밖에서 처리할 수 있습니다.
    이 경우 for 문의 세미콜론(;)은 반드시 필요합니다.
  */
  printf("1부터 %d까지의 덧셈 결과는 %d입니다.\n", InputNumber, TotalNumber);

  return;
}