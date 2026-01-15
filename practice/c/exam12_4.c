#include <stdio.h>
#include <string.h>

void main()
{
  char array[5] = { 'a', 'b', 'c', 'd', 'e' };
  char buf[5] = "abcde";
  char *ptr = "abcde";

  printf("array : %zu, array : %s\n", strlen(array), array);
  printf("buf : %zu, buf : %s\n", strlen(buf), buf);
  printf("ptr : %zu, ptr : %s\n", strlen(ptr), ptr);

  return;
}