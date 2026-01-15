#include <iostream>

int main()
{
  int arr[3] = { 1, 2, 3 };
  int (&ref)[3] = arr; 
  // 포인터와는 다르게 배열 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시

  ref[0] = 2;
  ref[1] = 3;
  ref[2] = 1;

  std::cout << arr[0] << arr[1] << arr[2] << std::endl;
  return 0;

}