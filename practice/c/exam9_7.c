#include <stdio.h>

void main()
{
  int data[5] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = data;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  ptr = &data[0];
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  return;
}