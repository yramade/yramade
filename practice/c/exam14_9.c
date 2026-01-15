#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int alphabet[26];

void CompareCharacter(int ch)
{
  int i;
  char temp = 'a';

  for (i = 0; i < 26; i++)
  {
    if (ch == (temp + i))
      alphabet[i]++;
  }
}

void main(int argc, char *argv[])
{
  FILE *fp;
  int ch;
  int i;

  if ((fp = fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "Error opening file.\n");
    exit(1);
  }

  while (!feof(fp))
  {
    ch = getc(fp);
    if (ch >= 'a' && ch <= 'z') {
      CompareCharacter(ch);
      while (isalpha(ch))
        ch = getc(fp);
    }
  }
  fclose(fp);
  
  for (i = 0; i < 26; i++)\
    printf("%c : %d 번\n", i + 'a', alphabet[i]);

  return;
}

/* 
c 폴더 내에서 실행
gcc exam14_9.c -o exam14_9
./exam14_9 ex9.txt
*/