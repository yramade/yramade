#include <stdio.h>

void main()
{
  int i;

  int data[5] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = data;
  for (i = 0; i < 5; i++)
  {
    printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);
    ptr++;
  }
  
  for (i = 0; i < 5; i++)
  {
    printf(" data : %p, *data : %d\n", &data[i], data[i]);
  }
  
  

  return;
}