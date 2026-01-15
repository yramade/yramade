#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;

  ptr = &data; // 포인터에 명확한 주소 할당
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  *ptr = *ptr + 10; // 포인터 변수를 일반 변수처럼 사용
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  return;
}