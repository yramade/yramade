#include <stdio.h>

int NumberOfString(char *);

void main()
{
  char data[80];
  int ret;
  printf("문자열을 입력하세요 : ");
  scanf("%s", data);

  ret = NumberOfString(data);
  printf("data의 문자열 : %s\n", data);
  printf("data의 문자 개수 : %d\n", ret);

  return;
}

int NumberOfString(char *src)
{
  int num = 0;

  while (*src++)
    num++;
  return num;
}