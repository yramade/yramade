#include <stdio.h>

void main()
{
  int i;
  char str[10] = "abcdefghij";

  for (i = 0; i < 10; i++)
  {
    printf("%c", i[str]);
  }
  printf("\n");

  for (i = 0; i < 10; i++)
  {
    printf("%c", *(i + str));
  }
  printf("\n");

  return;
}