#include <stdio.h>

struct TEST_STRUCT
{
  int i_data;
  char c_data[4];
};

union TEST_UNION
{
  int i_data;
  char c_data[4];
};

void main()
{
  printf("구조체와 공용체의 크기를 비교해 봅시다.\n");
  printf("구조체 TEST_STRUCT의 크기 : %zu bytes\n", sizeof(struct TEST_STRUCT));
  printf("공용체 TEST_UNION의 크기 : %zu bytes\n", sizeof(union TEST_UNION));

  return;
}