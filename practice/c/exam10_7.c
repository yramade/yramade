#include <stdio.h>

void main()
{
  int i;
  char str[3][20] = {
    "I am Inchoon",
    "Who are you?",
    "I'm Park"
  };

  for (i = 0; i < 3; i++)
    printf("str[%d] : %s\n", i, str[i]);

  return;
}