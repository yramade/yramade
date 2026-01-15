#include <stdio.h>

void main(){

  int num1, num2;
  printf("두 개의 정수를 입력하세요.\n");
  printf("num1 -> ");
  scanf("%d", &num1);
  printf("num2 -> ");
  scanf("%d", &num2);

  printf("덧셈의 결과를 보여줍니다.\n");
  printf("%d + %d = %d\n", num1, num2, (num1 + num2));
  return;
}