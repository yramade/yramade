#include <stdio.h>

void main()
{
  float *ptr;
  float b = 1.2;

  ptr = &b;

  printf("포인터 ptr의 주소 : %p\n", ptr);
  printf("포인터 ptr이 가리키는 데이터 : %f\n", *ptr);

  return;
}