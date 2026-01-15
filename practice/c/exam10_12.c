#include <stdio.h>
#include <string.h>

void main()
{
  int i, j;
  int count = 0;

  char str[5][54];
  char *token;
  strcpy(str[0], "The most important step in implementing DVFS is");
  strcpy(str[1], "prediction of the future workload, which allows");
  strcpy(str[2], "one to choose the minimum required voltage/frequency");
  strcpy(str[3], "levels while satisfying key constraints on energy");
  strcpy(str[4], "and QoS. As propsed in this paper, a simple interval-");

  for (i = 0; i < 5; i++)
  {
    token = strtok(str[i], " ");

    while (token)
    {
      count++;
      printf("%s\n", token);
      token = strtok(NULL, " ");
    }
  }
  printf("단어의 개수 : %d\n", count);

  return;
}