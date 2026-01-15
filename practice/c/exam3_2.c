#include <stdio.h>

void main(){
  char name[30];
  int num_10, num_8, num_16;
  float num_float1;

  printf("scanf() 함수의 기능에 대해 알아봅시다.\n");
  printf("문자열 입력을 받습니다. : ");
  scanf("%s", name);
  printf("10진수 입력을 받습니다. : ");
  scanf("%d", &num_10);
  printf("8진수 입력을 받습니다. : ");
  scanf("%o", &num_8);
  printf("16진수 입력을 받습니다. : ");
  scanf("%x", &num_16);
  printf("실수 입력을 받습니다. : ");
  scanf("%f", &num_float1);

  printf("\n");
  printf("입력한 값을 출력합니다.\n");
  printf("%s\n", name);
  printf("10진수 : [%d], 8진수 : [%o], 16진수 : [%x]\n", num_10, num_10, num_10);
  printf("10진수 : [%d], 8진수 : [%o], 16진수 : [%x]\n", num_8, num_8, num_8);
  printf("10진수 : [%d], 8진수 : [%o], 16진수 : [%x]\n", num_16, num_16, num_16);
  printf("실수 : [%10.2g]\n", num_float1);

  return;
}