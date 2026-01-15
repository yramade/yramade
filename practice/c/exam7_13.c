#include <stdio.h>
#include <math.h>

double x1, x2;

void CalEquation(int, int, int);

void main() {
  int a, b, c;

  printf("2차 방정식 ax^2 + bx + c = 0의 해를 구합니다.\n");
  printf("다음과 같은 방식으로 방정식을 입력하세요.\n");
  printf("예) ax2 + bx + c5 = 의 형태입니다. a, b, c 값을 입력하세요.\n");
  printf("입력 => ");
  scanf("%d %d %d", &a, &b, &c);

  CalEquation(a, b, c);

  printf("방정식의 해는 다음과 같습니다.\n");
  printf("x1 = %10.5g\n", x1);
  printf("x2 = %10.5g\n", x2);

  return;
}

void CalEquation(int a, int b, int c) {
  x1 = (double) (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  x2 = (double) (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
  return;
}