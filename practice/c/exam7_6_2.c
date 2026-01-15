#include <stdio.h>

void DisplayGuGuDan(void);
int Number;

void DisplayGuGuDan(void) {
  int i;
  for(i = 1; i < 10; i++)
    printf("%d * %d = %d\n", Number, i, (Number * i));
}