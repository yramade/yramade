#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long plus(int a, int b);
long minus(int a, int b);
long multiple(int a, int b);
double divide(int a, int b);

void main() {
  int input1, input2;
  char op;
  long result;

  printf("계산기 프로그램.\n");
  printf("[입력 예] 1 + 2\n");
  printf("입력 => ");
  scanf("%d %c %d", &input1, &op, &input2);

  switch (op)
  {
  case '+':
    result = plus(input1, input2);
    printf("%d %c %d = %ld\n", input1, op, input2, result);
    break;
  case '-':
    result = minus(input1, input2);
    printf("%d %c %d = %ld\n", input1, op, input2, result);
    break;
  case '*':
    result = multiple(input1, input2);
    printf("%d %c %d = %ld\n", input1, op, input2, result);
    break;
  case '/':
    if (input2 == 0) {
      printf("0으로 나눌 수 없습니다.\n");
      return;
    }
    double div_result = divide(input1, input2);
    printf("%d %c %d = %.6f\n", input1, op, input2, div_result);
    break;
  default:
    printf("지원하지 않는 연산자입니다.\n");
    printf("프로그램을 종료합니다.\n");
    break;
  }

  return;
}

long plus(int a, int b) {
  return (a + b);
}

long minus(int a, int b) {
  return (a - b);
}

long multiple(int a, int b) {
  return (a * b);
}

double divide(int a, int b) {
  return (a / b);
} 