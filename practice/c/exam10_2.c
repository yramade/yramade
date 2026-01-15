#include <stdio.h>
#include <string.h>

void main()
{
  int i;
  int num;
  char *str = "I am Inchoon";

  printf("문자열 str의 크기 : %d\n\n", strlen(str));

  num = strlen(str);
  for (i = 0; i < num; i++)
  {
    printf("%2dth : %c\n", i, *str++);
  }

  return;
}