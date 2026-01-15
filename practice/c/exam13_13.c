#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
  int number;
  char name[20];
  struct _NODE *next;
} NODE;

NODE *init_list();
void print_list(NODE *);
void clear_input_buffer();
void add_node(NODE *, int, char *);

int main()
{
  int i, j, num, count, len;
  char buf[20], letter;

  NODE *INITIAL[26];

  for (i = 0; i < 26; i++)
    INITIAL[i] = init_list();

  printf("인원수를 입력하세요.\n");
  scanf("%d", &count);
  for (i = 0; i < count; i++)
  {
    printf("번호 : ");
    scanf("%d", &num);
    printf("이름 : ");
    scanf("%s", buf);
    len = strlen(buf);

    j = buf[0] - 'a';
    if (j >= 0 && j < 26)
      add_node(INITIAL[j], num, buf);
    else {
      printf("알파벳 소문자만 입력 가능합니다.");
      return -1;
    }
  }

  clear_input_buffer();
  printf("출력할 INITIAL을 입력하세요. : ");
  scanf("%c", &letter);

  j = letter - 'a';
  print_list(INITIAL[j] -> next); // 첫 글자 입력시 그에 해당하는 리스트 출력

  return 0;
}

NODE *init_list()
{
  NODE *head;

  head = (NODE *)malloc(sizeof(NODE));
  head->next = NULL;
  return head;
}

void print_list(NODE *ptr)
{
  while (ptr != NULL)
  {
    printf("번호 : [%d], 이름 : [%s] \n", ptr->number, ptr->name);
    ptr = ptr->next;
  }
}

void add_node(NODE *init, int bunho, char *irum)
{
  NODE *ptr, *newnode;

  ptr = init;
  while (ptr->next != NULL)
    ptr = ptr->next;

  if (ptr->next ==NULL) {
    newnode = (NODE *)malloc(sizeof(NODE));

    newnode->number = bunho;
    strcpy(newnode->name, irum);
    ptr->next = newnode;
    newnode->next = NULL;
  }
}

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
      // 개행 문자나 EOF까지 모든 문자 읽어서 버리기
  }
}