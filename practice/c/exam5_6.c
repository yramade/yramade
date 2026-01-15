#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
      // 개행 문자나 EOF까지 모든 문자 읽어서 버리기
  }
}

void main() {
  int data1, data2, ret;
  char code;

  printf("두 값을 입력받아 덧셈 및 뺄셈을 하는 프로그램입니다.\n");
  printf("첫 번째 값을 입력하세요 : ");
  scanf("%d", &data1);
  printf("두 번째 값을 입력하세요 : ");
  scanf("%d", &data2);
  printf("덧셈과 뺄셈 코드를 입력하세요.\n");
  
  fflush(stdin); /* 키보드 버퍼 값 지우기 (잘 동작하지 않으므로 추후 사용불가)*/
  //clear_input_buffer(); /* 입력 버퍼 비우기 */

  printf("덧셈 : + \n");
  printf("뺄셈 : - \n");
  printf("+ 와 - 중에서 하나를 선택하세요. : ");
  scanf(" %c", &code); /* 앞에 공백을 넣어 이전 입력의 엔터값을 무시 */

  ret = (code == '+') ? (data1 + data2) : (data1 - data2);
  printf("[결과] %d %c %d = %d\n", data1, code, data2, ret);

  return;
}