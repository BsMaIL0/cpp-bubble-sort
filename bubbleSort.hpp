#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <functional>

template <typename T, typename Comparator = std::less<T>>
void bubbleSort(T A[], size_t size, Comparator comp = Comparator{}) {
  if (size <= 1) {
    return;
  }
  for (size_t i = 0; i < size - 1; ++i) {
    bool isSorted = true;
    for (size_t j = size - 1; j > i; --j) {
      if (comp(A[j],A[j - 1])) {
        std::swap(A[j], A[j - 1]);
        isSorted = false;
      }
    }
    if (isSorted) {
      break;
    }
  }
}

#endif