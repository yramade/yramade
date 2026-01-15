#include <stdio.h>
#include <string.h>

typedef struct _Grade {
  char Name[10];
  int Number;
  int Grade;
} Grade;

Grade Data[3];

int DoReadAction(void);
int DoWriteAction(void);
void InputUserData(void);
void OutputUserData(void);
void clear_input_buffer(void);

int main(int argc, char *argv[])
{
  if(argc < 2) {
    printf("다음 형식으로 입력하세요! : exam14_5 옵션 \n");
    printf("옵션 /r : 학점 파일 읽어오기 \n");
    printf("옵션 /w : 학점 파일 작성하기 \n");

    return -1;
  }

  if (!strcmp(argv[1], "/r"))
    DoReadAction();
  else if (!strcmp(argv[1], "/w"))
    DoWriteAction();
  else {
    printf("옵션이 정확하지 않습니다.\n");
    printf("다시 확인해 주세요.\n");
    return -1;
  }

  return 0;
}

int DoReadAction(void)
{
  FILE *fin;
  if((fin = fopen("grade.dat", "rb")) == NULL) {
    printf("파일을 열 수 없습니다.");
    return -1;
  }

  if(fread(Data, sizeof(Grade), 3, fin) != 3)
  {
    printf("데이터 읽기에 오류가 발생하였습니다.");
    fclose(fin);
    return -1;
  }

  fclose(fin);
  OutputUserData();
  return 0;
}

int DoWriteAction(void)
{
  FILE *fout;

  if((fout = fopen("grade.dat", "wb")) == NULL)
  {
    printf("파일을 작성할 수 없습니다.");
    return -1;
  }

  InputUserData();

  if(fwrite(Data, sizeof(Grade), 3, fout) != 3)
  {
    printf("데이터 쓰기에 오류가 발생하였습니다.");
    fclose(fout);
    return -1;
  }

  fclose(fout);
  return 0;
}

void InputUserData(void)
{
  int i;

  printf("학번/학생이름/학점을 입력하세요\n");

  for (i = 0; i < 3; i++)
  {
    printf("[학번] : ");
    scanf("%d", &Data[i].Number);
    printf("[학생이름] : ");
    scanf("%s", Data[i].Name);
    printf("[학점] : ");
    scanf("%d", &Data[i].Grade);
    printf("---------------------------------\n");
    clear_input_buffer();
  }
}

void OutputUserData(void)
{
  int i;

  printf("학번/학생이름/학점입니다.\n");

  for (i = 0; i < 3; i++)
  {
    printf("[학번] : %d\n", Data[i].Number);
    printf("[학생이름] : %s\n", Data[i].Name);
    printf("[학점] : %d\n", Data[i].Grade);
    printf("---------------------------------\n");
  }
}

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
      // 개행 문자나 EOF까지 모든 문자 읽어서 버리기
  }
}

/* 
c 폴더 내에서 실행
gcc exam14_5.c -o exam14_5
./exam14_5 /w
./exam14_5 /r
*/