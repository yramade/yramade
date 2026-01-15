#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawStar(int a);

void main() {
  int i;
  int maxline;

  printf("공백과 * 문자 출력하기.\n");
  printf("몇 줄을 출력할까요? : ");
  scanf("%d", &maxline);
  
  printf("\n");

  for(i = 0; i < maxline; i++)
    drawStar(maxline);

  return;
}

void drawStar(int maxline) {
  static int line = 1;
  int i;

  for(i = 0; i < maxline - line; i++)
    printf("   ");

  for(i = 0; i < line; i++)
    printf(" * ");
    
  printf("\n");
  line++;
}