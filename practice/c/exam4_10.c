#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int data;
  int i;

  printf("약수를 구할 정수값을 입력하세요.\n");
  printf("입력 : ");
  scanf("%d", &data);

  for (i = 1; i <= data; i++)
  {
    if ((data % i) == 0) /* 사용자가 입력한 수가 i로 나누어지는지 검사 */
    {
      printf("%4d", i); /* 사용자가 입력한 수가 i로 나누어지면 출력 */
    }
    
  }
  

  return;
}