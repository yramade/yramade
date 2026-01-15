#include <stdio.h>

typedef struct _Node {
  int number;
  char name[15];
  struct _Node* next;
} Node;

void print_list(Node *);

void main()
{
  Node person[3] = {
    { 1, "이재혁" },
    { 2, "여인춘" },
    { 3, "김미정" }
  };
  int i;

  for (i = 0; i < 2; i++)
    person[i].next = &person[i + 1];
  
  person[2].next = NULL;

  print_list(person);

  return;
}

void print_list(Node *ptr)
{
  while (ptr != NULL)
  {
    printf("번호 : %d, 이름 : %s\n", ptr->number, ptr->name);
    ptr = ptr->next;
  }
}