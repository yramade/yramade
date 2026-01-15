#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fin, *fout;
  char buf[80];
  int LineNumber = 1;

  if(argc < 3) {
    printf("다음 형식으로 입력하세요! : exam14_4 원본_파일 복사_파일\n");
    return -1;
  }

  if((fin = fopen(argv[1], "r")) == NULL) {
    printf("원본 파일을 열 수 없습니다.\n");
    return -1;
  }

  if((fout = fopen(argv[2], "w")) == NULL) {
    printf("복사할 파일을 생성할 수 없습니다.\n");
    fclose(fin);
    return -1;
  }

  while (fgets(buf, 80, fin) != NULL)
  {
    fprintf(fout, "%d: ", LineNumber++);  // 직접 출력
    fputs(buf, fout);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}

/* 
c 폴더 내에서 실행
gcc exam14_4.c -o exam14_4
./exam14_4 exam14_4.c backup.txt
*/