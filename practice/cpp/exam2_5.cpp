#include <iostream>

int main()
{
  int &ref = 4; // 상수 값을 변경하는 것과 같기에 에러 표시
  // const int &ref = 4;

  std::cout << ref << std::endl;

  return 0;
}