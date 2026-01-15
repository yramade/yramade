#include <stdio.h>

void main()
{
  char *str = "I am Inchoon"; // 문자열 포인터 선언 후 초기화시 문자열 상수가 된다.

  *str = 'Y';
  str[1] = 'X';
  printf(" str : %s\n", str); // 상수이므로 수정 불가

  return;
}