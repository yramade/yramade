#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int num, i, data;

  srand(time(NULL));
  num = rand() % 10; // 0~9 사이의 난수 발생

  i = 1;
  printf("0부터 9까지 숫자를 입력하세요.\n");

  while(1){
    printf("[%2d번째 도전] : ", i);
    scanf("%d", &data);

    if(data < num)
      printf("%d보다는 큽니다.\n", data);
    else if(data > num)
      printf("%d보다는 작습니다.\n", data);
    else {
      printf("정답입니다! %2d번째 만에 맞췄습니다.\n", i);
      break;
    }
    i++;
  }

  return;
}

