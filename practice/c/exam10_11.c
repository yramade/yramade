#include <stdio.h>
#include <string.h>

void main()
{
  int i, j;
  int count = 0;

  char *str[5];
  str[0] = "The most important step in implementing a DVFS is";
  str[1] = "prediction of the future workload, which allows";
  str[2] = "one to choose the minimum required voltage/frequency";
  str[3] = "levels while satisfying key constraints on energy";
  str[4] = "and QoS. As propsed in this paper, a simple interval-";

  for (i = 0; i < 5; i++)
  {
    count++; // 각 줄의 첫 번째 단어 카운트
    for (j = 0; j < strlen(str[i]); j++)
    {
      while (*str[i]++ != ' ');
      count++;
      // printf("%s : %d\n", str[i], count);
    }
  }
  printf("단어의 개수 : %d\n", count);
  
  return;
}