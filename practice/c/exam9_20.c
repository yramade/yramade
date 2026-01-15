#include <stdio.h>

#define NUM_CLASS 3
#define NUM_STUDENT 5

void main()
{
  int i, j;

  int data[][3] = {
    { 100, 90, 80 },
    { 90, 90, 80 },
    { 70, 90, 80 },
    { 100, 30, 70 },
    { 100, 90, 100 }
  };
  int (*ptr)[3];
  int *tptr[5];
  int Student[5][2];
  int class[3] = { 0, };

  ptr = data;
  tptr[0] = &data[0][0];
  tptr[1] = &data[1][0];
  tptr[2] = &data[2][0];
  tptr[3] = &data[3][0];
  tptr[4] = &data[4][0];

  // 학생들 총점 및 평균
  for (i = 0; i < NUM_STUDENT; i++)
  {
    Student[i][0] = *tptr[i] + *(tptr[i] + 1) + *(tptr[i] + 2);
    Student[i][1] = Student[i][0] / NUM_CLASS;
    printf(" [%d]학생의 총점 : %d, 평균 : %d\n", i, Student[i][0], Student[i][1]);
  }

  // 과목별 평균
  for (i = 0; i < NUM_STUDENT; i++)
  {
    class[0] += **ptr;
    class[1] += *(*ptr + 1);
    class[2] += *(*ptr + 2);
    ptr++;
  }
  
  printf(" 국어 과목의 평균 : %d\n", class[0] / NUM_STUDENT);
  printf(" 영어 과목의 평균 : %d\n", class[1] / NUM_STUDENT);
  printf(" 수학 과목의 평균 : %d\n", class[2] / NUM_STUDENT);

  return;
}