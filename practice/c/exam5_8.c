#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int x, y, z;
  x = 15;
  y = 17;

  z = x + y * 2 - ++x * ( y++ / 3 ); /* 이런 코드는 사용하지 말 것 */

  printf("x의 값은 : %d\n", x);
  printf("y의 값은 : %d\n", y);
  printf("x + y * 2 - ++x * ( y++ / 3 )의 결과는 : %d\n", z);
  printf("\n");

  x = 1;
  y = 0;

  x = x << 1 || y;
  y += ++y;

  printf("x의 값은 : %d\n", x);
  printf("y의 값은 : %d\n", y);

  return;
}