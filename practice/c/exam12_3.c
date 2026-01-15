#include <stdio.h>
#include <memory.h> // memcpy() 함수 사용을 위한 헤더 파일
#include <stdlib.h> // malloc(), free() 함수 사용을 위한 헤더 파일

void main()
{
  char *buf;

  int i;

  printf("buf의 할당\n");
  buf = (char *)malloc(sizeof(char) * 5);

  for (i = 0; i < 5; i++)
    printf("%d번째의 값 : %p\n", i, (void *)buf++); // buf가 가리키는 메모리 값 출력

  buf -= 5; // 포인터 buf를 원래 위치로 복귀

  printf("memset() 함수를 사용해 볼까요?\n");
  memset(buf, '*', 5); // buf가 가리키는 메모리 공간을 '*' 문자로 초기화

  for (i = 0; i < 5; i++)
    printf("%d번째의 값 : %c\n", i, *buf++); // buf가 가리키는 메모리 값 출력

  buf -= 5; // 포인터 buf를 원래 위치로 복귀
  free(buf); // buf가 가리키는 메모리 공간 해제
  
  return;
}