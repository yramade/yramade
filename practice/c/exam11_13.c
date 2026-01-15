#include <stdio.h>

char *TrimString(char *);

void main()
{
  char data[80] = "##I am Inchoon. Who are you?";
  char *ret;

  printf("data의 문자열 : %s\n", data);
  ret = TrimString(data);
  
  printf("ret의 문자열 : %s\n", ret);

  return;
}

char *TrimString(char *src)
{
  char *ret, *ptr;
  ret = src; // ret이 src를 가리키도록 지정
  ptr = src; // ptr이 src를 가리키도록 지정

  while (*src)
  {
    if ((*src >= 'A' && *src <= 'Z' || *src >= 'a' && *src <= 'z'))
    {
      // 현재 포인터 src이 가리키는 데이터가 영문자인지 확인
      *ptr++ = *src++; // ptr이 가리키는 곳에 src가 가리키는 데이터를 복사
    }
    else
    {
      src++; // 영문자가 아니면 src 포인터만 하나 증가
    }
  }
  *ptr = '\0'; // 문자열의 끝을 표시
  return ret;  // ret이 가리키는 곳의 주소를 반환
  
}