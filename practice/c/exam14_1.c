#include <stdio.h>

int main()
{
  FILE *fp;

  if((fp = fopen("exam11_1.c", "r")) == NULL){
    printf("파일이 없습니다.");
    return -1;
  }

  while(!feof(fp))
    printf("%c", fgetc(fp));

  fclose(fp);
  return 0;
}