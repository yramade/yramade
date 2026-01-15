#include <stdio.h>
#include <stdint.h>

void main()
{
  int a = 3;
  float b = 1.2;
  char c = 'A';

  printf("정수형을 부동소수점형으로 : %f\n", (float)a);
  printf("부동소수점형을 정수형으로 : %d\n", (int)b);
  printf("문자형을 정수형으로 : %d\n", (int)c);
  printf("정수형을 포인터형으로 : %p\n", (void *)(intptr_t)a);
  printf("문자형을 포인터형으로 : %p\n", (void *)(intptr_t)c);

  return;
}