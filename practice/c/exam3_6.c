#include <stdio.h>

void main() {
  char key;
  int data;

  printf("10진수 -> 16진수 변환 프로그램입니다.\n");
  printf("10진수를 16진수로 변환하려면 a키를 누르고, \n");
  printf("16진수를 10진수로 변환하려면 b키를 누르세요.\n");
  printf("변환할 진법을 선택하세요 : ");
  scanf("%c", &key);

  printf("변환할 숫자를 입력하세요.\n");
  if(key == 'a'){
    scanf("%d", &data);
    printf("10진수 %d는 16진수로 %x입니다.\n", data, data);
  }else if(key == 'b'){
    scanf("%x", &data);
    printf("16진수 %x는 10진수로 %d입니다.\n", data, data);
  }else {
    printf("a 또는 b만 입력하세요.\n");
  }

  return;
}