#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _DATA {
  int No;
  char Name[80];
  struct _DATA *next;
} DATA;

DATA *first, *last;

void print_list(DATA *a);
void create_item(int a, char *name);

void main()
{
  char buf[80];
  int i = 0;
  int no;
  int number;

  printf("몇 명을 입력하시겠습니까?");
  scanf("%d", &number);

  first = (DATA *)malloc(sizeof(DATA));  // first 노드 생성
  // first->No와 first->Name이 초기화되지 않음 (쓰레기 값)
  last = (DATA *)malloc(sizeof(DATA));

  first->next = last;
  last->next = first;

  while (i < number)
  {
    printf("학번을 입력하세요. => ");
    scanf("%d", &no);
    printf("이름을 입력하세요. => ");
    scanf("%s", buf);
    create_item(no, buf);
    i++;
  }
  print_list(first);
  
  return;
}

void print_list(DATA *ptr)
{
  ptr = ptr->next;  // first 노드 건너뛰고 시작
  while (ptr != last)
  {
    printf("%d 번 %s\n", ptr->No, ptr->Name);
    ptr = ptr->next;
  }
}

void create_item(int num, char* name)
{
  DATA *ptr, *newperson;
  
  ptr = first;

  while (ptr->next != last)
    ptr = ptr->next;

  if (ptr->next == last)
  {
    newperson = (DATA *)malloc(sizeof(DATA));

    newperson->No = num;
    strcpy(newperson->Name, name);

    ptr->next = newperson;
    newperson->next = last;
  }
}