#include <stdio.h>
#include <string.h>

void main()
{
  int a;
  char b = 'a';
  char *str = "a";

  printf("정수형 a의 크기 : %zu\n", sizeof(a));
  printf("문자형 b의 크기 : %zu\n", sizeof(b));
  printf("문자열 str의 크기 : %zu\n", strlen(str));

  return;
}