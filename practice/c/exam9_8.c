#include <stdio.h>

void main()
{
  int data[5] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = data;
  printf(" ptr : %p, data : %p, &data[0] : %p\n", ptr, data, &data[0]);

  return;
}