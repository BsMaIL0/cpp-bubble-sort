#include <iostream>

template <typename T>
void bubbleSort(T A[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = size - 1; j > 0; --j) {
      if (A[j] < A[j - 1]) {
        std::swap(A[j], A[j - 1]);
      }
    }
  }
}