#include <stdio.h>

void main()
{
  int a = 10;
  char b = 'A';
  float c = 100.11; // 정수, 문자, 부동소수점형 변수 선언 및 초기화
  void *ptr; // void 포인터 선언

  ptr = &a;
  printf("ptr의 주소 : %p ptr가 가리키는 곳의 데이터 : %d\n", &ptr, *((int *)ptr));
  ptr = &b;
  printf("ptr의 주소 : %p ptr가 가리키는 곳의 데이터 : %c\n", &ptr, *((char *)ptr));
  ptr = &c;
  printf("ptr의 주소 : %p ptr가 가리키는 곳의 데이터 : %.2f\n", &ptr, *((float *)ptr));

  return;
}