#include <stdio.h>
#include <memory.h>

void main()
{
  char src[5] = { 'a', 'b', 'c', 'd', 'e' };
  char dst[5] = { 'f', 'g', 'h', 'i', 'j' };

  int i;

  printf("src와 dst의 초기값 출력\n");
  printf("\tsrc[]\t\tdst[]\n");
  for (i = 0; i < 5; i++)
  {
    printf("src[%d] : %c\t", i, src[i]);
    printf("dst[%d] : %c\n", i, dst[i]);
  }

  printf("memcpy()를 사용해볼까요?\n");
  memcpy(dst, src, sizeof(src));
  // memcpy() 함수를 사용하여 배열 src[]의 내용을 dst[]로 복사

  for (i = 0; i < 5; i++)
  {
    printf("src[%d] : %c\t", i, src[i]);
    printf("dst[%d] : %c\n", i, dst[i]);
  }
  
  return;
}