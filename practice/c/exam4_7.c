#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERSON 3

void main() {
  int Person[MAX_PERSON];
  int i;
  int TotalCountOfKorean = 0;
  int AverageOfKorean = 0;

  printf("학급의 국어 성적에 대한 총점과 평균 구하기\n");

  Person[0] = 95;
  Person[1] = 80;
  Person[2] = 92;

  for (i = 0; i < MAX_PERSON; i++)
    printf("%d번째 학생의 국어 성적 : %d\n" , i + 1, Person[i]);

  for (i = 0; i < MAX_PERSON; i++)
    TotalCountOfKorean += Person[i];

  AverageOfKorean = TotalCountOfKorean / MAX_PERSON;
  printf("\n");
  printf("총점 : %d\n", TotalCountOfKorean);
  printf("평균 : %d\n", AverageOfKorean);
  

  return;
}