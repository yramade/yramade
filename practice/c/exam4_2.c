#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  printf("C 언어에서 제공하는 자료형의 크기를 알아봅니다.\n");

  printf("char 형의 크기 : %d\n", sizeof(char));
  printf("short 형의 크기 : %d\n", sizeof(short));
  printf("int 형의 크기 : %d\n", sizeof(int));
  printf("long 형의 크기 : %d\n", sizeof(long));
  printf("long long 형의 크기 : %d\n", sizeof(long long));
  printf("float 형의 크기 : %d\n", sizeof(float));
  printf("double 형의 크기 : %d\n", sizeof(double));
  printf("long double 형의 크기 : %d\n", sizeof(long double));

  return;
}