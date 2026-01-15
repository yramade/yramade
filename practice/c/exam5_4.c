#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int a = 10;
  int b = 10;

  printf("a++의 값은 %d\n", a++); /* 출력 후 a를 1 증가 */
  printf("++a의 값은 %d\n", ++a); /* 출력 전 a를 1 증가 */

  printf("\n");
  printf("b--의 값은 %d\n", b--); /* 출력 후 b를 1 감소 */
  printf("--b의 값은 %d\n", --b); /* 출력 전 b를 1 감소 */

  return;
}