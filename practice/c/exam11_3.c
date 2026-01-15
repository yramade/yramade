#include <stdio.h>

void main()
{
  int i;
  char str[10] = "abcdefghi";

  for (i = 0; i < 10; i++)
  {
    printf("%c", str[i]);
  }
  printf("\n");

  for (i = 0; i < 10; i++)
  {
    printf("%c", *(str + i));
  }
  printf("\n");

  return;
}