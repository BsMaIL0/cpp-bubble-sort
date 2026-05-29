#include <iostream>

#include "bubbleSort.hpp"

void printArr(int A[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
}

int main() {
  int arr[] = {1, 4, 6, 2, 1, 5, 6, 1, 26, 17, 732, 72, 5, 15, 14, 214, 143};
  bubbleSort(arr, 17);
  printArr(arr, 17);
}