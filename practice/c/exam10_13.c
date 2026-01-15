#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define MAX 30

void main()
{
  char *buf[MAX];

  int i, j, k = 1;
  int size;

  printf(" 크기를 입력하세요. \n");
  scanf("%d", &size);

  printf("\n");

  for (i = 0; i < size; i++)
  {
    buf[i] = (char*)malloc(sizeof(char) * size);
    memset(buf[i], 0, sizeof(char) * size);
  }

  for (i = 0; i < size; i++)
    for (j = size - i - 1; j < size; j++)
      buf[i][j] = k++;
  
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (buf[i][j] == 0)
      {
        printf("   ");
      }
      else
      {
        printf("%4d", buf[i][j]);
      }
    }
    printf("\n");
  }

  return;
}