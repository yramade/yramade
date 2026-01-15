#include <stdio.h>


void main()
{
  int i;
  char str[3][16] = {
    "I am Inchoon",
    "Who are you?",
    "I'm Park"
  };

  for (i = 0; i < 3; i++)
    printf("%p : %s\n", &str[i], str[i]);

  return;
}