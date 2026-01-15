#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f(int);

void main() {
  int coin = 100;
  int NumOfCoffee;

  printf("함수는 자동판매기와 같습니다.\n");
  printf("동전을 넣어주세요. : ");
  scanf("%d", &coin);
  NumOfCoffee = f(coin);

  printf("%d잔의 커피가 나왔습니다.\n", NumOfCoffee);

  return;
}

int f(int x) {
  int ret;
  printf("%d원을 넣으셨군요.\n", x);

  if(x == 100)
    ret = 1;
  else if(x == 200)
    ret = 2;
  else if(x == 300)
    ret = 3;
  else {
    printf("금액이 부족합니다. 커피가 나오지 않습니다.\n");
    ret = 0;
  }
  
  return ret;
}