#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ELEMENT 100
#define Sentinel 0

#define TRUE 1
#define FALSE 0

int GenIntegerArray(int array[], int max, int sentinel);
int GenInteger(void);
void PrintIntegerArray(int array[], int n);
void ReverseIntegerArray(int array[], int n);
void SwapIntergerElements(int array[], int p1, int p2);

void main() {
  int list[MAX_ELEMENT], n;

  printf("임의의 정수 값을 입력하세요.\n");
  printf("0을 입력하면 입력을 종료합니다.\n");

  n = GenIntegerArray(list, MAX_ELEMENT, Sentinel);
  ReverseIntegerArray(list, n);
  PrintIntegerArray(list, n);

  return;
}

int GenIntegerArray(int array[], int max, int sentinel) {
  int n, value;
  n = 0;

  while (TRUE)
  {
    printf("==>");
    value = GenInteger();
    if(value == sentinel) break;
    if (n == max) printf("총 개수를 초과했습니다.\n");
    
    array[n] = value;
    n++;
  }

  return n;
}

int GenInteger(void) {
  int n;

  scanf("%d", &n);
  return n;
}

void PrintIntegerArray(int array[], int n) {
  int i;

  for(i = 0; i < n; i++)
    printf("%d\n", array[i]);
}

void ReverseIntegerArray(int array[], int n) {
  int i;

  for (i = 0; i < n / 2; i++)
    SwapIntergerElements(array, i, n - i - 1);
}

void SwapIntergerElements(int array[], int p1, int p2) {
  int tmp;

  tmp = array[p1];
  array[p1] = array[p2];
  array[p2] = tmp;
}