#include <iostream>

void bubbleSort(int A[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - 1; ++j) {
      if (A[j] < A[j - 1]) {
        std::swap(A[j], A[j - 1]);
      }
    }
  }
}

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