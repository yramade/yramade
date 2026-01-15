#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.141592

void main() {
  float r;
  
  printf("반지름을 입력해 주세요.\n");
  printf("반지름 : ");
  scanf("%f", &r);
  printf("원의 넓이 : %.2f\n", r * r * PI);
  printf("원의 둘레 : %.2f\n", 2 * r * PI);

  return;
}