#include <stdio.h>
#include <string.h>

typedef struct _Grade {
  char Name[10];
  int Number;
  int Grade;
} Grade;

Grade Data[3];

int DoReadAction(char *name);
int OutputUserData(char *name);

int main(int argc, char *argv[])
{
  char name[10];

  if(argc < 2) {
    printf("[사용법] exam14_6 검색_단어 \n");
    printf("예 : exam14_6 park \n");
    return -1;
  }

  strcpy(name, argv[1]);

  DoReadAction(name);

  return 0;
}

int DoReadAction(char* name)
{
  FILE* fin;

  if((fin = fopen("grade.dat", "r")) == NULL) {
    printf("파일을 열 수 없습니다.");
    return -1;
  }

  if(fread(Data, sizeof(Grade), 3, fin) != 3) {
    printf("데이터 읽기에 오류가 있습니다.");
    fclose(fin);
    return -1;
  }

  fclose(fin);

  OutputUserData(name);
  return 0;
}

int OutputUserData(char* name)
{
  int i;

  for (i = 0; i < 3; i++)
  {
    if (!strcmp(Data[i].Name, name)) {
      printf("\n[%s]에 대한 학번과 점수입니다.\n", name);
      printf("--------------------------------------------\n");
      printf("[학번] : %d\n", Data[i].Number);
      printf("[이름] : %s\n", Data[i].Name);
      printf("[점수] : %d\n", Data[i].Grade);
      printf("--------------------------------------------\n");
      return 0;
    }
  }

  printf("[%s]라는 이름이 없군요. 다시 실행해 주세요.", name);
  return -1;
  
}

/* 
c 폴더 내에서 실행
gcc exam14_6.c -o exam14_6
./exam14_6 홍길동
*/