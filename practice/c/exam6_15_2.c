#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int i, j, count = 1;
  long sum = 0;

  printf("1부터 1000까지의 소수를 구하는 프로그램.\n");

  printf("%d\t", 1);
  for (i = 1; i <= 1000; i++)
  {
    for (j = 2; j < i; j++)
    {
      if ( (i % j) == 0 )
        break;
    }
    if(i == j) { // 소수 출력
      printf("%d\t", i);
      count++;

      if( (count % 8) == 0 ) // 소수 8개 출력 후 줄바꿈
        printf("\n");
    }    
  }
  
  printf("\n1부터 1000까지의 소수의 개수 : %d.\n", count);
  return;
}