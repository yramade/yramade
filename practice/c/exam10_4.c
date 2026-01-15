#include <stdio.h>
#include <string.h>

void main()
{
  int i;
  int num;
  char *str = "I am Inchoon";
  char array[] = "I am Inchoon";

  printf("문자열 str의 크기 : %zu\n", strlen(str));
  printf("문자열 array의 크기 : %zu\n\n", strlen(array));

  num = strlen(str);
  printf("str의 주소 : %p\n", &str);
  printf("str이 가리키는 첫 문자의 주소 : %p\n", &str[0]);
  printf("array의 주소 : %p\n", &array);
  printf("array의 첫 문자의 주소 : %p\n\n", &array[0]);

  return;
}