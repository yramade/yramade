#include <stdio.h>
#include <stdarg.h>

int Add(int, ...);

void main()
{
  int ret;

  ret = Add(2, 1, 2);
  printf(" 두 개의 숫자의 덧셈 결과 : %d\n", ret);

  ret = Add(3, 1, 2, 3);
  printf(" 세 개의 숫자의 덧셈 결과 : %d\n", ret);

  ret = Add(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  printf(" 열 개의 숫자의 덧셈 결과 : %d\n", ret);

  return;
}

int Add(int num, ...)
{
  va_list ptr;
  int sum = 0;
  int i = 0;

  va_start(ptr, num);

  while (i++ < num)
  {
    sum += va_arg(ptr, int);
  }

  va_end(ptr);
  return sum;
}