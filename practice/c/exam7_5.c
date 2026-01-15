#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void IncreaseAge(int);

static int Age;

void main() {
  int i;

  Age = 33;
  printf("여기는 main() 함수입니다.\n");
  printf(" Age : %d\n\n", Age);

  for(i = 0; i < 5; i++)
    IncreaseAge(10);

  printf("\n여기는 main() 함수입니다.\n");
  printf(" Age : %d\n", Age);
  return;
}

void IncreaseAge(int num){
  static int Age = 25;

  Age = Age + num;
  // IncreaseAge() 함수 안에서 static으로 선언한 변수 Age는
  // IncraseAge() 함수 내부의 코드 블록에만 적용됩니다.
  // 따라서 main() 함수의 Age 변수와는 다른 변수입니다.

  printf("여기는 IncreaseAge() 함수입니다.\n");
  printf(" Age : %d\n", Age);
}
