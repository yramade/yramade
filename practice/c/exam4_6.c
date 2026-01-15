#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int Person[3]; /* 학생의 국어 성적을 저장하기 위한 배열 */
  int i;
  int TotalCountOfKorean = 0;
  int AverageOfKorean = 0;

  printf("학급의 국어 성적에 대한 총점과 평균 구하기.\n");

  Person[0] = 95;
  Person[1] = 80;
  Person[2] = 92;

  for (i = 0; i < 3; i++)
  {
    printf("%d번째 학생의 국어 성적 : %d\n", i + 1, Person[i]);
  }

  for (i = 0; i < 3; i++)
  {
    TotalCountOfKorean += Person[i]; /* 모든 학생의 총점 구하기*/
  }
  
  AverageOfKorean = TotalCountOfKorean / 3; /* 평균 구하기 */
  printf("\n");
  printf("학급의 국어 총점 : %d\n", TotalCountOfKorean);
  printf("학급의 국어 평균 : %d\n", AverageOfKorean);

  return;
}