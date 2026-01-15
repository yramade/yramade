#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int, int); // 최대공약수
int lcm(int, int, int); // 최소공배수

void main() {
  int Gcd, Lcm;
  int num1, num2;

  printf("최대공약수 및 최대공배수를 구하는 프로그램\n");
  printf("두 개의 수를 입력하세요.\n");
  printf("입력 => ");
  scanf("%d %d", &num1, &num2);

  Gcd = gcd(num1, num2);
  printf("최대공약수 : %d\n", Gcd);

  Lcm = lcm(num1, num2, Gcd);
  printf("최소공배수 : %d\n", Lcm);

  return;
}

int gcd(int x, int y) {
  static int ExecNum = 1;
  printf("%d회 실행합니다.\n", ExecNum++);
  if(y != 0){
    printf("x : %d, y : %d\n", x, y);
    return gcd(y, x % y);
  }else
    return x;
}

int lcm(int x, int y, int gcd) {
  return (x * y) / gcd;
}