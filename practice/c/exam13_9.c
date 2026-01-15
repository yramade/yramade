#include <stdio.h>
#include <string.h>

typedef struct _Lang
{
  int Kor;
  int Eng;
} Lang;

typedef struct _Students
{
  char Name[20];
  Lang Language;
  int Society;
  int Music;
  int Sum;
  float Average;
} Students;

void main()
{
  Students Persons[2];
  strcpy(Persons[0].Name, "반 점수");
  Persons[0].Language.Kor = 90;
  Persons[0].Language.Eng = 95;
  Persons[0].Society = 88;
  Persons[0].Music = 80;
  Persons[0].Sum = Persons[0].Language.Kor + Persons[0].Language.Eng + Persons[0].Society + Persons[0].Music;
  Persons[0].Average = Persons[0].Sum / 4.0f;

  printf("본인의 이름을 적으시오. : ");
  scanf("%s", Persons[1].Name);
  printf("본인의 국어 점수를 적으시오. => ");
  scanf("%d", &Persons[1].Language.Kor);
  printf("본인의 영어 점수를 적으시오. => ");
  scanf("%d", &Persons[1].Language.Eng);
  printf("본인의 사회 점수를 적으시오. => ");
  scanf("%d", &Persons[1].Society);
  printf("본인의 음악 점수를 적으시오. => ");
  scanf("%d", &Persons[1].Music);

  Persons[1].Sum = Persons[1].Language.Kor + Persons[1].Language.Eng + Persons[1].Society + Persons[1].Music;
  Persons[1].Average = Persons[1].Sum / 4.0f;

  if(Persons[0].Sum < Persons[1].Sum)
    printf("[%s]는 반 평균 점수보다 과목 총점으로는 %d점, 과목 평균 점수로는 %f점 높습니다.\n", Persons[1].Name, (Persons[1].Sum - Persons[0].Sum), (Persons[1].Average - Persons[0].Average));
  else if(Persons[0].Sum > Persons[1].Sum)
    printf("[%s]는 반 평균 점수보다 과목 총점으로는 %d점, 과목 평균 점수로는 %f점 낮습니다.\n", Persons[1].Name, (Persons[0].Sum - Persons[1].Sum), (Persons[0].Average - Persons[1].Average));
  else
    printf("[%s]는 반 평균과 똑같습니다.\n", Persons[1].Name);

  return;
}