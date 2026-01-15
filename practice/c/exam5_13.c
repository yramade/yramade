#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int n, t;
  printf("팩토리얼 계산 \n");
  printf("숫자를 입력하세요. : ");

  scanf("%d", &n);
  t = 1;

  while (n >= 1)
    t *= n--; 
  /* 팩토리얼 값 t에 변수 n값을 곱하여 저장한 뒤 다시 1을 감소 */
  
  printf("결과 값 : %d \n", t);
  return;
}