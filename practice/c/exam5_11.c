#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  char data;

  printf("알파벳 대소문자 중에서 하나를 입력해 보세요.\n");
  printf("입력 => ");
  scanf("%c", &data);

  data = (data >= 'A' && data <= 'Z') 
  ? data + ('a' - 'A') 
  : (data >= 'a' && data <= 'z') 
    ? data - ('a' - 'A') 
    : data;

  printf("출력 => : %c \n", data);
  return;
}