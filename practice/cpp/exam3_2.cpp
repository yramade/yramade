#include <iostream>

int main()
{
  int arr_size;
  std::cout << "array size : ";
  std::cin >> arr_size;
  std::cin.ignore(); // 입력 버퍼 정리

  // 입력 버퍼 정리를 위해서는 std::cin.ignore() 사용 후
  // std::cout를 사용하여 출력 버퍼를 비워야 함
  
  int *list = new int[arr_size];
  for (int i = 0; i < arr_size; i++) {
    std::cout << "Enter " << arr_size << " numbers: ";
    std::cin >> list[i];
    std::cin.ignore(); // 입력 버퍼 정리
  }
  for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th element of list : " << list[i] << std::endl;
  }

  delete[] list;
  return 0;
}