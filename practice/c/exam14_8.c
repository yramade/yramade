#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE* fin, *fout;

  int ch;
  int i = 0;

  if(argc < 2)
  {
    printf("사용법 : exam14_8 파일_이름 \n");
    return -1;
  }

  if((fin = fopen(argv[1], "rt")) == NULL)
  {
    printf("읽어들일 파일이 없습니다.\n");
    return -1;
  }

  if((fout = fopen("temp.txt", "wt")) == NULL)
  {
    printf("파일을 생성할 수 없습니다.\n");
    return -1;
  }

  while (!feof(fin))
  {
    ch = fgetc(fin);

    if (ch >= 'a' && ch <= 'z') // 소문자를 대문자로 변환
      ch = ch - ('a' - 'A');

    fputc(ch, fout);
  }
  fclose(fin);
  fclose(fout);

  fout = fopen(argv[1], "wt");
  fin = fopen("temp.txt", "rt");

  while (!feof(fin))
  {
    ch = fgetc(fin);
    fputc(ch, fout);
  }
  fclose(fin);
  fclose(fout);
  
  system("rm temp.txt");

  return 0;
}

/* 
c 폴더 내에서 실행
gcc exam14_8.c -o exam14_8
./exam14_8 aaa.txt
*/