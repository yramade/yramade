#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
      // 입력 버퍼 비우기
  }
}

void main() {
  int n, i;
  int binary = 0;

  printf("10진수를 입력하세요.\n");
  printf("[10진수] ==> ");
  scanf("%d", &n);
  i = 1;

  while(1){
    binary += (n % 2) * i;
    i *= 10;
    n /= 2;
    if(n == 0) break;
  }

  printf("[2진수] ==> %d\n", binary);
  return;
}