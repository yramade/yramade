#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print();

int cnt = 1;

void main() {
  int i;
  int line;

  printf("* 모양을 사선으로 출력하는 프로그램.\n");
  printf("몇 줄을 출력할까요? : ");
  scanf("%d", &line);

  printf("\n");

  for(i = 0; i < line; i++) {
    print();
    cnt++;
  }

  return;
}

void print() {
  int i;

  for(i = 0; i < cnt; i++)
    printf(" * ");

  printf("\n");
}