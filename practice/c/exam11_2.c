#include <stdio.h>

void main()
{
  char str[100];
  int i;

  for (i = 0; i < 10; i++)
    str[i] = i + '0';
  str[30] = NULL;
  // NULL 포인터는 문자열 끝에 삽입한다.

  for (i = 0; i < 30; i++)
    printf("%2c", str[i]);
  printf("\n");
  printf("%s\n", str);
  // NULL 포인터를 만날 때까지 출력

  return;
}