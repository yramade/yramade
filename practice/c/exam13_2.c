#include <stdio.h>
#include <string.h>
#include "common1.h"

/*
struct Grade {
  char Name[20]; // 이름
  int Number;  // 학번
  int Korean; // 국어 점수
  int English; // 영어 점수
  int Math; // 수학 점수
};
*/

void main()
{
  Grade ClassOfGrade_1;

  strcpy(ClassOfGrade_1.Name, "홍길동");
  ClassOfGrade_1.Number = 15;
  ClassOfGrade_1.Korean = 90;
  ClassOfGrade_1.English = 100;
  ClassOfGrade_1.Math = 95;

  printf(" [%d]번 [%s]의 성적표입니다.\n", ClassOfGrade_1.Number, ClassOfGrade_1.Name);

  printf("국어 : %d\n", ClassOfGrade_1.Korean);
  printf("영어 : %d\n", ClassOfGrade_1.English);
  printf("수학 : %d\n", ClassOfGrade_1.Math);

  return;
}