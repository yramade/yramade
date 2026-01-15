#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;

  printf("data의 주소 : %p, data의 값 : %d\n", &data, data);
  ptr = &data;
  printf("ptr의 주소 : %p, ptr의 값 : %p\n", &ptr, ptr);

  return;
}