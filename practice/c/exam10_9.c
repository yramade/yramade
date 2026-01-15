#include <stdio.h>

void main()
{
  int i;
  char *str[3] = {
    "I am Inchoon",
    "Who are you?",
    "I'm Park"
  };
  // str은 char* 배열 (포인터 배열)
  // 64비트 시스템에서 포인터 크기는 8바이트
  // str[0], str[1], str[2]의 주소가 8바이트씩 차이남

  for(i=0; i<3; i++)
    printf("%p : %s\n", &str[i], str[i]);

  return;
}