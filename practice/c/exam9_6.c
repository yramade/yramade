#include <stdio.h>

void main()
{
  int data = 10;
  int *ptr;

  ptr = &data;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  *ptr = *ptr + 10;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  (*ptr)++;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  *ptr++;
  printf(" ptr : %p, *ptr : %d\n", ptr, *ptr);

  return;
}