#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int i, num, count = 0;
  long sum = 0;

  printf("주어진 수의 배수가 1~1000 사이에 몇 개 있으며, 그 합을 얼마인지를 구하는 프로그램.\n");
  printf("1부터 1000까지의 수 중에서 하나 입력하세요. ==> ");
  scanf("%d", &num);

  for(i = 1; i <= 1000; i++){
    if(i % num == 0){
      sum += i;
      count++;
    }
  }

  printf("1부터 1000까지의 %d의 배수의 개수 : %d, 배수의 합 : %ld.\n", num, count, sum);

  return;
}