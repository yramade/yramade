#include <stdio.h>

int Square(int, int ); // 제곱근과 세제곱근을 구하는 함수

void main()
{
  int Number, Level;
  int ret;
  printf("C 프로그래밍에서의 포인터 사용 예제\n");

  Level = 2;
  Number = 3;
  ret = Square(Level, Number); // 2의 세제곱
  printf("Level : %d Return Value : %d\n", Level, ret);
  printf("\n");

  Level = 3;
  Number = 4;
  ret = Square(Level, Number); // 3의 4제곱
  printf("Level : %d Return Value : %d\n", Level, ret);

  return;
}

int Square(int lv, int num) // 제곱근과 세제곱근을 구하는 함수
{
  if(lv == 2)
    return num * num;
  else if(lv == 3)
    return num * num * num;
  else
    return 0;
}