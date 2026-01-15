#include <stdio.h>
#include <stdint.h>

void main()
{
  int data = 10;
  int *ptr = &data;
  intptr_t temp; // int 대신 intptr_t 사용
  // 포인터는 64비트 시스템에서 8바이트
  // 4바이트 정수를 8바이트 포인터로 캐스팅하면 데이터 손실 위험

  printf("포인터 ptr의 주소 : %p\n", &ptr);
  printf("포인터 ptr의 데이터 : %p\n", ptr);
  printf("data의 주소 : %p\n", &data);
  printf("포인터 ptr가 가리키는 데이터 : %d\n", *ptr);

  temp = (intptr_t)ptr; // 정수형 변수에 포인터를 대입하면 주소가 아닌 데이터
  printf("변수 temp의 주소 : %p\n", &temp); // 형변환을 해주면 다시 포인터처럼 사용 가능
  printf("변수 temp의 데이터 : %p\n", (void *)temp);
  printf("변수 temp가 가리키는 데이터 : %d\n", *((int *)temp)); // 다시 포인터형으로 형변환 후 역참조

  return;
}