#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int data1, data2;
  int i, num, max;

  printf("약수를 구할 두 정수값을 입력하세요.\n");
  printf(" 입력1 : ");
  scanf("%d", &data1);
  printf(" 입력2 : ");
  scanf("%d", &data2);

  if (data1 < data2)
    num = data1;
  else
    num = data2;

  for (i = 1; i <= num; i++)
  {
    if( ((data1 % i) == 0) && ((data2 % i) == 0) )
      max = i;
  }

  printf("%d와 %d의 최대공약수는 %d입니다.\n", data1, data2, max);
  

  return;
}