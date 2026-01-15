#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int count, num, i, sum = 0, mul = 1;
  float aver = 0;

  printf("입력할 정수는 몇 개인가요? ");
  scanf("%d", &count);

  printf("%d개 정수의 절대갑의 곱과 합, 평균을 출력합니다.\n\n", count);
  printf("입력하세요. : ");

  for (i = 0; i < count; i++)
  {
    scanf("%d", &num);

    if(num < 0) /* 음수일 경우 양수값으로 변환 */
      num = -num;

    mul *= num;
    sum += num;
    aver = (float)sum / count;
  }

  printf("곱   : %10d\n", mul);
  printf("합   : %10d\n", sum);
  printf("평균 : %10.2f\n", aver);

  return;
}