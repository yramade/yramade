#include <stdio.h>
#include <malloc.h>

void main()
{
  char *pBuf, *iBuf;
  int i;

  printf("C 프로그래밍에서의 포인터를 이용한 메모리 할당 예제\n");

  pBuf = (char *)malloc(10);
  iBuf = pBuf;
  for (i = 0; i < 10; i++)
    *pBuf++ = i + 'A'; // 문자 저장

  pBuf = iBuf;
  for (i = 0; i < 10; i++)
    printf("%c ", *pBuf++); // 문자 출력
  
  free(iBuf);

  // malloc()과 free()는 반드시 한 쌍으로 사용해야 한다.
  // malloc()으로 할당한 메모리는 반드시 할당받은 위치(주소)에서 free()로 해제해야 한다.
  // 변수의 이름과 관계없이 해당 주소의 메모리를 해제해야 한다.

  return;
}