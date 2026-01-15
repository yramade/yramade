#include <stdio.h>
#include <stdlib.h>

void main()
{
  char *buf[5];
  int i;

  printf("malloc() 함수의 사용\n");
  for (i = 0; i < 5; i++)
  {
    buf[i] = (char *)malloc(sizeof(char) * 10);
    // 각 배열 요소마다 10바이트씩 할당
    *buf[i] = 'A' + i;
    // 각 항목의 첫 번째 바이트에 A를 할당 후, 1씩 증가.
    // A, B, C, D, E 저장
    printf("buf[i]의 시작 주소 : %p\n", buf[i]);
    printf("buf[i]의 첫 번째 항목 : %c\n", *buf[i]);
  }

  printf("free() 함수의 사용\n");
  for (i = 0; i < 5; i++)
  {
    free(buf[i]); // 할당된 메모리 해제
    printf("buf[i]의 시작 주소 : %p\n", buf[i]);
    printf("buf[i]의 첫 번째 항목 : %c\n", *buf[i]);
  }

  return;
}