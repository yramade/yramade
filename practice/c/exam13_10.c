#include <stdio.h>
#include <malloc.h>

typedef struct _DATA {
  int index;
  int front;
  int back;
  int number;
} DATA;

void main()
{
  DATA *datum;
  int i, j;
  int height;

  printf("출력된 삼각형의 높이를 입력하시오. : ");
  scanf("%d", &height);

  datum = (DATA *)malloc(sizeof(DATA) * height);

  for (i = 0; i < height; i++) {
    datum[i].index = i;
    datum[i].front = height - i;
    datum[i].back = height - i;
    datum[i].number = (2 * i) + 1;
  }

  for (i = 0; i < height; i++)
  {
    for (j = 0; j < datum[i].front; j++) printf("  ");
    for (j = 0; j < datum[i].number; j++) printf("*");
    for (j = 0; j < datum[i].back; j++) printf("  ");
    printf("\n");
  }
  free(datum);

  return;
}