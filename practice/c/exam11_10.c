#include <stdio.h>

void main()
{
  int data[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
  void *ptr;

  ptr = &data;
  printf("%d\n", *(int *)ptr++);
  printf("%d\n\n", *(int *)ptr); // 이런 식으로는 사용불가

  ptr = &data;
  printf("%d\n", (*(int *)ptr)++);
  printf("%d\n\n", *(int *)ptr);

  ptr = &data;
  printf("%d\n", *(int *)ptr);
  ptr = (int *)ptr + 1;  // 포인터 증가를 별도로 처리
  printf("%d\n\n", *(int *)ptr);

  ptr = &data;
  printf("%d\n", *(int *)ptr);
  ptr = (double *)ptr + 1;  // 포인터 증가를 별도로 처리
  printf("%d\n\n", *(int *)ptr);

  printf("int형의 크기 : %zu\n", sizeof(int));
  printf("int 크기 : %zu\n", sizeof(double));

  return;
}