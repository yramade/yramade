#include <stdio.h>

// #define DEBUG // 주석 처리하면 릴리즈 모드가 됩니다.

void main(void)
{
  printf("전처리문에 대해 알아봅시다.\n\n");

#ifdef DEBUG
  printf("여기는 디버깅을 위한 코드들입니다.\n");
  printf("릴리즈할 때는 실행되지 않아요.\n");
  printf("실행은 커녕 컴파일도 되지 않죠.\n");
#else
  printf("여기는 릴리즈할 때 실행되는 코드들입니다.\n");
#endif
  printf("이 문장은 항상 출력됩니다.\n");

  return;
}