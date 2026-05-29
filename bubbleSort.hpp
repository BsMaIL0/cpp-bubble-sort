#include <iostream>

template <typename T>
void bubbleSort(T A[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    bool isSorted = true;
    for (int j = size - 1; j > i; --j) {
      if (A[j] < A[j - 1]) {
        std::swap(A[j], A[j - 1]);
        isSorted = false;
      }
    }
    if (isSorted) {
      break;
    }
  }
}