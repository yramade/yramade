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
  int data;

  printf("양수와 음수의 절대값을 구하는 프로그램입니다.\n");
  printf("0을 입력하면 프로그램을 종료합니다.\n");

  printf("[입력] => ");
  scanf("%d", &data);

  while(data != 0) {
    if(data > 0)
      printf("양수군요. 절대값은 %d입니다.\n", data);
    else
      printf("음수군요. 절대값은 %d입니다.\n", -data);

    clear_input_buffer();
    printf("[입력] => ");
    scanf("%d", &data);
  }

  return;
}