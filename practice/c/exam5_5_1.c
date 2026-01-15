#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  float num1, num2;
  float data1, data2;

  num1 = num2 = 4.352;
  data1 = data2 = 3.141592;

  printf("대입 연산자에 댛해 알아봅시다.\n");
  num1 += num2 -= data1 *= data2 /= 2; 
  /* 괄호가 없으면 가장 오른쪽의 대입 연산자부터 실행 */

  printf("num1: [%-.3f]\n", num1);
  printf("num2: [%-.3f]\n", num2);
  printf("data1: [%-.3f]\n", data1);
  printf("data2: [%-.3f]\n", data2);

  return;
}