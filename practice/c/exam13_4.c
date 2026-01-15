#include <stdio.h>
#include <string.h>

typedef struct _Grade {
  char Name[20];
  int Number;
  int Korean;
} Grade;

void ShowTable(Grade);
int Total;

void main()
{
  Grade ClassOfGrade_1[3];
  char buf[20];
  int i;
  Total = 0;

  printf("1학년의 성적 관리 프로그램입니다.\n");

  for (i = 0; i < 3; i++)
  {
    printf("%d째 학생의 이름을 입력하세요. : ", i + 1);
    scanf("%s", ClassOfGrade_1[i].Name);
    printf("학번을 입력하세요. : ");
    scanf("%d", &ClassOfGrade_1[i].Number);
    printf("국어 점수를 입력하세요. : ");
    scanf("%d", &ClassOfGrade_1[i].Korean);
    printf("\n");
  }

  printf("=====================================\n");
  printf("학번\t\t이름\t\t국어 성적\n");
  for (i = 0; i < 3; i++)
    ShowTable(ClassOfGrade_1[i]);

  printf("=====================================\n");
  printf("평균\t%d\n", Total / 3);

  return;
}

void ShowTable(Grade tbl)
{
  printf(" [%d]번\t\t[%s]\t", tbl.Number, tbl.Name);
  printf(" [%d]\n", tbl.Korean);
  Total += tbl.Korean;
}