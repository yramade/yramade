#include <stdio.h>

void main( void ) {
  printf("문자열 출력         : [%-20s]\n", "Hello, World!");
  printf("문자열 출력         : [%20s]\n", "Hello, World!");
  printf("문자   출력         : [%10c]\n", 'a');
  printf("문자   출력         : [%-10c]\n", 'a');
  printf("문자 정수값 출력     : [%-10d]\n", 'a');
  printf("왼쪽 정렬           : [%-10d]\n", 1234);
  printf("오른쪽 정렬         : [%10d]\n", 1234);
  printf("앞에 0 채우기       : [%010d]\n", 1234);
  printf("음수 0 채우기       : [%010d]\n", -1234);
  printf("부동소수점 출력      : [%8.2f]\n", 123.4567);
  printf("부동소수점 출력      : [%-8.2f]\n", 123.4567);
  printf("부동소수점 출력      : [%10.2f]\n", 0.0012345);
  printf("부동소수점 출력      : [%10.2e]\n", 0.0012345);
  printf("부동소수점 출력      : [%10.2g]\n", 0.0012345);

  printf("첫 번째 수 : %d, 두 번째 수: %d, 세 번째 수 : %d\n", 100, 1000, 10000);
  printf("%d\n", 123);
  printf("%f\n", 123.456);
  printf("%c\n", 'A');
  printf("%s\n", "안녕하세요.");
  
  int num = 10;
  float fdata = 123.456;
  char ch = 'A';
  char sdata[20] = "반갑습니다.";

  printf("%d\n", num);
  printf("%f\n", fdata);
  printf("%c\n", ch);
  printf("%s\n", sdata);
}