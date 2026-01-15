#include <iostream>

int main()
{
  int* p = new int;
  *p = 10;

  std::cout << "*p : " << *p << std::endl;

  delete p; // new로 할당한 메모리는 반드시 delete로 해제
  return 0;
}