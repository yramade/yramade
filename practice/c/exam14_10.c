#include <stdio.h>
#include <string.h>

typedef struct _DATA {
  char Name[15];
  char Title[50];
  int Number;
} DATA;

DATA R_Client[50];
DATA W_Client;

size_t number = 0;

int ReadFromFile(void);
int WriteToFile(void);
void InputUserData(void);
void OutputUserData(void);
int SearchByName(void);
int OutputBySearch(char *name);
void clear_input_buffer(void);

int main(int argc, char *argv[])
{
  char name[10];

  FILE *fout;

  if (argc < 2) {
    printf("사용법 exam14_10 옵션 \n");
    printf("옵션 : /i => 파일 초기 생성 \n");
    printf("옵션 : /r => 파일 읽기 \n");
    printf("옵션 : /w => 파일 쓰기 \n");
    printf("옵션 : /s => 파일 검색 \n");
    return -1;
  }

  if(!strcmp(argv[1], "/i"))
  {
    fout = fopen("Num1.dat", "wb");
    fwrite(&number, sizeof(number), 1, fout);
    fclose(fout);
    fout = fopen("Video1.dat", "wb");
    fclose(fout);
  }
  else if(!strcmp(argv[1], "/r"))
    ReadFromFile();
  else if(!strcmp(argv[1], "/w"))
    WriteToFile();
  else if(!strcmp(argv[1], "/s"))
    SerachByName();
  else  
    printf("옵션이 정확하지 않습니다.\n");

  return 0;
}

int ReadFromFile(void)
{
  FILE *fin1, *fin2;

  if((fin1 = fopen("Video1.dat", "rb")) == NULL) {
    printf("파일1을 열 수 없습니다.\n");
    return -1;
  }

  if((fin2 = fopen("Num1.dat", "rb")) == NULL) {
    printf("파일2를 열 수 없습니다.\n");
    return -1;
  }

  if(fread(&number, sizeof(number), 1, fin2) != 1)
  {
    printf("데이터2 읽기에 오류가 있습니다.\n");
    fclose(fin2);
    return -1;
  }

  if(fread(R_Client, sizeof(DATA), number, fin1) != number)
  {
    printf("데이터1 읽기에 오류가 있습니다.\n");
    fclose(fin1);
    return -1;
  }

  fclose(fin1);
  fclose(fin2);

  OutputUserData();

  return 0;
}

int WriteToFile(void)
{
  FILE *fout1, *fout2, *fin;

  fin = fopen("Num1.dat", "rb");

  fread(&number, sizeof(number), 1, fin);

  fclose(fin);

  if((fout1 = fopen("Video1.dat", "ab")) == NULL) {
    printf("파일을 생성할 수 없습니다.\n");
    return -1;
  }

  if((fout1 = fopen("Num1.dat", "wb")) == NULL) {
    printf("파일을 생성할 수 없습니다.\n");
    return -1;
  }

  InputUserData();

  if(fwrite(&W_Client, sizeof(DATA), 1, fout1) != 1)
  {
    printf("데이터1 쓰기에 오류가 있습니다.\n");
    fclose(fout1);
    return -1;
  }

  if(fwrite(&W_Client, sizeof(DATA), 1, fout2) != 1)
  {
    printf("데이터1 쓰기에 오류가 있습니다.\n");
    fclose(fout2);
    return -1;
  }

  fclose(fout1);
  fclose(fout2);
  return 0;
}

void InputUserData(void)
{
  printf("/고객이름/비디오제목/ 을 입력하세요.\n\n");
  W_Client.Number = number;

  printf("[비디오 번호] : %d\n", W_Client.Number);
  ++number;

  printf("[고객 이름] : ");
  gets(W_Client.Name);
  clear_input_buffer();
  printf("[비디오 제목] : ");
  gets(W_Client.Title);
  printf("-----------------------------\n");
  clear_input_buffer();
}

void OutputUserData(void)
{
  int i;

  printf("번호/고객이름/비디오제목 입니다.\n");

  for (i = 0; i < number; i++)
  {
    printf("[비디오 번호] : %d\n", R_Client[i].Number);
    printf("[고객 이름] : %s\n", R_Client[i].Name);
    printf("[비디오 제목] : %s\n", R_Client[i].Title);
    printf("-----------------------------\n");
  }
}

int SearchByName(void)
{
  char name[15];
  FILE *fin1, *fin2;

  printf("조회할 이름을 붙여서 입력하시오. : ");
  scanf("%s", name);

  if((fin1 = fopen("Video1.dat", "rb")) == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return -1;
  }

  if ((fin2 = fopen("Num1.dat", "rb")) == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return -1;
  }

  if (fread(&number, sizeof(number), 1, fin2) != 1)
  {
    printf("데이터2 읽기에 오류가 있습니다.\n");
    fclose(fin2);
    return -1;
  }

  if (fread(R_Client, sizeof(DATA), number, fin1) != number)
  {
    printf("데이터1 읽기에 오류가 있습니다.\n");
    fclose(fin1);
    return -1;
  }

  fclose(fin1);
  fclose(fin2);

  OutputBySearch(name);

  return 0;
}

int OutputBySearch(char *name)
{
  int i;

  for (i = 0; i < number; i++)
  {
    if (!strcmp(R_Client[i].Name, name)) {
      printf("번호/이름/제목 입니다.\n");
      printf("[번호] : %d\n", R_Client[i].Number);
      printf("[이름] : %s\n", R_Client[i].Name);
      printf("[제목] : %s\n", R_Client[i].Title);
      printf("-----------------------------\n");
    }
  }
  
  return 0;
}

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
      // 개행 문자나 EOF까지 모든 문자 읽어서 버리기
  }
}