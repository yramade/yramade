#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  float Width, Height;

  printf("사각형의 폭과 높이를 입력해 주세요.\n");
  printf("폭 : ");
  scanf("%f", &Width);
  printf("높이 : ");
  scanf("%f", &Height);

  printf("사각형의 넓이는 %.2f입니다.\n", Width * Height);

  return;
}