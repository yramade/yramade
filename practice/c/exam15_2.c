#include <stdio.h>

// #define DATA 2
#define DATA 3

struct _DATA
{
  char* Name;
  int Age;
};

#if DATA == 2
  char name[20] = "이재혁";
  int age = 32;
#elif DATA == 3
  char name[20] = "김미정";
  int age = 31;
#else
  char name[20] = "너 누구니?";
  int age = 0;
#endif

void main()
{
  struct _DATA FRI;

  FRI.Name = name;
  FRI.Age = age;

  printf("%s 님의 나이는 %d살입니다.\n", FRI.Name, FRI.Age);
  printf("이 소스 코드의 컴파일 일시 : %s\n", __DATE__);
  printf("이 소스 코드의 파일 이름 : %s\n", __FILE__);
  printf("이 소스 코드의 총 행수 : %d\n", __LINE__);
  printf("이 ㅗ스 코드의 컴파일 시간 : %s\n", __TIME__);
  printf("이 소스 코드의 최종 수정 시간 : %s\n", __TIMESTAMP__);

  return;
}