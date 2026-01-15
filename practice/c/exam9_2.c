#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;
  printf("data의 주소 : %lx, data의 값: %d\n", &data, data);

  ptr = &data;
  printf("ptr의 주소 : %lx, ptr의 값 : %lx\n", &ptr, ptr);

  printf("ptr가 가리키는 곳의 값 : %d, data의 값 : %d\n", *ptr, data);
  printf("ptr의 주소 : %lx, ptr의 값: %lx, ptr가 가리키는 값 : %d\n", &ptr, ptr, *ptr);

  return;
}