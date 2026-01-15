#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;

  *ptr = data; // 포인터 ptr이 초기화되지 않아 정의되지 않은 동작 발생
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  return;
}