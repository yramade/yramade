#include <stdio.h>

#define OUTPRT1(a) printf("a : %d\n", a)
#define OUTPRT2(a) printf("#a : %d\n", a)

void main(void)
{
  int num = 23;

  OUTPRT1(num);
  OUTPRT2(num);

  return;
}