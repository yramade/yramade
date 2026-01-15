#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fin, *fout;

  if(argc < 3) {
    printf("다음 형식을 입력하세요! : exam14_3 원본_파일 복사_파일");
    return -1;
  }

  if((fin = fopen(argv[1], "r")) == NULL) {
    printf("원본 파일을 열 수 없습니다.");
    return -1;
  }

  if((fout = fopen(argv[2], "w")) == NULL) {
    printf("복사 파일을 열 수 없습니다.");
    return -1;
  }

  while(!feof(fin))
    fputc(fgetc(fin), fout);

  fclose(fin);
  fclose(fout);

  return 0;
}

/* 
c 폴더 내에서 실행
gcc exam14_3.c -o exam14_3
echo "Hello World!" > test.txt
./exam14_3 test.txt copy.txt
*/