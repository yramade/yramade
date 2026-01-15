#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Square(int);
int TripleSquare(int);

void main() {
  int num_1, num_2, ret;
  num_1 = 5;
  num_2 = 7;
  printf("함수의 사용 예제\n");

  ret = Square(num_1);
  printf("%d의 제곱은 %d입니다.\n", num_1, ret);

  ret = Square(num_2);
  printf("%d의 제곱은 %d입니다.\n", num_2, ret);

  ret = TripleSquare(num_1);
  printf("%d의 세 배의 제곱은 %d입니다.\n", num_1, ret);
  
  ret = TripleSquare(num_2);
  printf("%d의 세 배의 제곱은 %d입니다.\n", num_2, ret);

  return;
}

int Square(int x) {
  int ret;

  ret = x * x;
  return ret;
}

int TripleSquare(int x) {
  int ret;

  ret = x * x * x;
  return ret;
}