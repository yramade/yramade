#include <stdio.h>
#include <stdint.h>

void main()
{
  int data = 10;
  int *ptr = &data;
  int temp; // 정수형 변수

  printf("포인터 ptr의 주소 : %p\n", &ptr);
  printf("포인터 ptr의 데이터 : %p\n", ptr);
  printf("data의 주소 : %p\n", &data);
  printf("포인터 ptr가 가리키는 데이터 : %p\n", (void *)(intptr_t)*ptr);

  temp = (intptr_t)ptr; // 정수형 변수에 포인터를 대입하면 주소가 아닌 데이터
  printf("변수 temp의 주소 : %p\n", (void *)(intptr_t)&temp); // 형변환을 해주면 다시 포인터처럼 사용 가능
  printf("변수 temp의 데이터 : %p\n", (void *)(intptr_t)temp);
  // printf("변수 temp가 가리키는 데이터 : %p\n", *temp);

  return;
}