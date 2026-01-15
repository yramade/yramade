#include <stdio.h>

#define X 7
#define Y 7

void main() {
  int i, j;
  int k;
  char buf[X][Y];

  for (i = 0; i < 7; i++)
  {
    for (j = 0;j < 7;j++)
    {
      buf[i][j] = ' ';
    }
  }

  for (k = 0; k < 7; k++)
  {
    if (k <= 3)
    {
      buf[k][3 - k] = '*';
      buf[k][3 + k] = '*';
    }else
    {
      buf[k][k - 3] = '*';
      buf[k][9 - k] = '*';
    }
  }

  for (i = 0; i < 7; i++)
  {
    for (j = 0; j < 7; j++)
    {
      printf("%c", buf[i][j]);
    }
    printf("\n");
  }

  return;
}