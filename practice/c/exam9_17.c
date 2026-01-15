#include <stdio.h>

void Square(int, int *); // 제곱근과 세제곱근을 구하는 함수

void main()
{
  int Number, Level;

  printf("C 프로그래밍에서 포인터 사용 예제 - 두 번째\n");

  Level = 2;
  Number = 3;
  Square(Level, &Number); // 3의 제곱
  printf("Level : %d Return Value : %d\n", Level, Number);
  printf("\n");

  Level = 3;
  Number = 4;
  Square(Level, &Number); // 4의 세제곱
  printf("Level : %d Return Value : %d\n", Level, Number);

  return;
}

void Square(int lv, int *ret)
{
  if(lv == 2)
    *ret = (*ret) * (*ret); // 제곱
  else if(lv == 3)
    *ret = (*ret) * (*ret) * (*ret); // 세제곱
}