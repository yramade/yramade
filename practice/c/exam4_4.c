#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  float a = 1.123456789123456789; /* float 형 */
  double b = 1.123456789123456789; /* double 형 */

  printf("a의 출력 결과 : %1.20G\n", a);
  printf("b의 출력 결과 : %1.20G\n", b);


  return;
}