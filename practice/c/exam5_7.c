#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int num1, num2;
  char ch;
  float data;

  num1 = 2;
  num2 = 5;

  printf("정수형 나눗셈 : \t\t\t %d / %d = %d\n", num1, num2, num1 / num2);
  printf("정수형 나눗셈의 결과를 형변환 : \t %d / %d = %f\n", num1, num2, (float)num1 / num2);
  printf("부동소수점으로 형변환 후 나눗셈: \t %f / %f = %f\n", (float)num1, (float)num2, (float)num1 / (float)num2);

  ch = (char) 65.123;
  printf("부동소수점을 문자형으로 형변환 : \t %c \n", ch);

  data = 3.141592;
  printf("부동소수점을 정수형으로 형변환 : \t %d \n", (int)data);

  return;
}