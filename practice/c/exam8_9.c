#include <stdio.h>
#include <string.h>

void main() {
  int Length;
  int i;
  char buf[80];
  char *p;

  printf("숫자를 입력하세요.\n");
  printf("입력 => ");
  scanf("%s", buf);

  Length = strlen(buf);
  p = buf;
  printf("출력 => ");

  for (i = Length; i > 0;)
  {
    printf("%c", *p++);
    i--;
    if(i > 0 && (i % 3) == 0)
      printf(",");
  }
  printf("\n");

  return;
}