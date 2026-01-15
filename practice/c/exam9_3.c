#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;

  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);
  ptr = &data;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);
  *ptr = data;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  return;
}