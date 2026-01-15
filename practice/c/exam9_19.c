#include <stdio.h>
#include <malloc.h>

void addr(int );

void main()
{
  int num;

  printf("크기를 입력하시오 : ");
  scanf("%d", &num);
  addr(num);

  return;
}

void addr(int x)
{
  int *ptr;

  int i = 0, sum = 0;

  ptr = (int*)malloc(sizeof(char) * x);
  printf("\n할당된 메모리에 들어갈 값을 입력하시오.\n");
  
  while (i < x)
  {
    printf("ptr[%d] => ", i);
    scanf("%d", &ptr[i]);
    i++;
  }

  for (i = 0; i < x; i++)
    sum = sum + ptr[i];
  
  printf("\n%p에서 %p까지 저장된 값들의 합은 %d이다.\n", ptr, ptr + x, sum);
  free(ptr);
}