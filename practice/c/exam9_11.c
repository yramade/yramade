#include <stdio.h>

void main()
{
  int i, j;

  int data[][2] = { {10, 20}, {30, 40}, {50, 60}, {70, 80}, {90, 100} };
  int (*ptr)[2];

  ptr = data;
  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf(" ptr : %p, *ptr : %d\n", ptr[i] + j, *(ptr[i] + j));
    }
    
  }
  

  return;
}