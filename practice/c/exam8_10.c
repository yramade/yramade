#include <stdio.h>

void main()
{
  int buf[5][5];
  int CountOfSquare = 25;

  int LimitOf_X = 0;
  int LimitOf_Y = 0;

  int i, j, num;
  i = j = 0;
  num = 1;
  printf("나선형으로 숫자 출력하기\n");
  
  while (1)
  {
    for (i = LimitOf_X; i < (5 - LimitOf_X); i++)
      buf[i][j] = num++;
    i--;

    for (j = LimitOf_Y + 1; j < (5 - LimitOf_Y); j++)
      buf[i][j] = num++;
    j--;

    for (i = (5 - LimitOf_X - 2); i >= LimitOf_X; i--)
      buf[i][j] = num++;
    i = LimitOf_X;

    for (j = (5 - LimitOf_Y - 2); j > LimitOf_Y; j--)
      buf[i][j] = num++;
    
    LimitOf_X++;
    LimitOf_Y++;
    i = LimitOf_X;
    j = LimitOf_Y;

    if(j == 2)
    {
      buf[i][j] = num++;
      break;
    }
  }

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 5; j++)
      printf("%3d\t", buf[i][j]);
    printf("\n");
  }
  

  return;
}