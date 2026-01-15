#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CalMouth(int);
int CalDay(int);

void main() {
  int number;
  int month, day;

  printf("당신의 생일을 맞춰볼게요.\n\n");

  printf("1. 당신이 태어난 달을 5배하고 12를 더하세요.\n");
  printf("2. 그 결과를 20배 하고 태어난 달을 더하세요.\n");
  printf("3. 여기서 365를 빼면 얼마나 되나요?\n");
  printf("그 값을 입력해 보세요. => ");
  scanf("%d", &number);
  printf("%d + 125 = %d\n", number, number + 125);

  month = CalMouth(number);
  day = CalDay(number);

  printf("당신은 %d월 %d일에 태어났군요.\n", month, day);

  return;
}

int CalMouth(int x) {
  return x / 100;
}

int CalDay(int y) {
  return y % 100;
}