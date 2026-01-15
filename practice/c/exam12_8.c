#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void main()
{
  char *buf;

  int i, size;

  printf(" 4 이상의 수를 입력하시오. ");
  scanf("%d", &size);

  printf("\n");

  buf = (char *)malloc(sizeof(char) * size * size);

  i = 0;
  while (i < size)
  {
    memset(buf + (size * i++), '*', size);
    if (i < size)
      memset(buf + (size * i++), '$', size);
    else
      break;
  }

  for (i = 1; i <= size * size; i++)
  {
    printf("%3c", buf[i - 1]);
    if (i % size == 0) printf("\n");
  }
  free(buf);

  return;
}