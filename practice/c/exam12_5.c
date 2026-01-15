#include <stdio.h>
#include <string.h>

void main()
{
  char array[6] = { 'a', 'b', 'c', 'd', 'e', '\0' };
  char buf[6] = "abcde\0";
  char *ptr = "abcde";

  printf("array : %zu, array : %s\n", strlen(array), array);
  printf("buf : %zu, buf : %s\n", strlen(buf), buf);
  printf("ptr : %zu, ptr : %s\n", strlen(ptr), ptr);

  return;
}