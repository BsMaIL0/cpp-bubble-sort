#include <gtest/gtest.h>

#include <vector>

#include "../src/bubbleSort.hpp"

// Тест 1
TEST(BubbleSortTest, SortsArray) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], 11);
  EXPECT_EQ(arr[1], 12);
  EXPECT_EQ(arr[2], 22);
  EXPECT_EQ(arr[3], 25);
  EXPECT_EQ(arr[4], 34);
  EXPECT_EQ(arr[5], 64);
  EXPECT_EQ(arr[6], 90);
}

// Тест 2: Уже отсортированный массив
TEST(BubbleSortTest, AlreadySorted) {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  for (int i = 0; i < size - 1; ++i) {
    EXPECT_LE(arr[i], arr[i + 1]);
  }
}

// Тест 3: Массив в обратном порядке
TEST(BubbleSortTest, ReverseOrder) {
  int arr[] = {5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);
}

// Тест 4: Массив с одинаковыми элементами
TEST(BubbleSortTest, AllEqual) {
  int arr[] = {5, 5, 5, 5, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], 5);
  }
}

// Тест 5: Массив из одного элемента
TEST(BubbleSortTest, SingleElement) {
  int arr[] = {42};
  int size = 1;

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], 42);
}

// Тест 6: Пустой массив
TEST(BubbleSortTest, EmptyArray) {
  std::vector<int> vec;
  bubbleSort(vec.data(), vec.size());  // data() вернет nullptr, size() = 0
  SUCCEED();
}

// Тест 7: Отрицательные числа
TEST(BubbleSortTest, NegativeNumbers) {
  int arr[] = {-5, -1, -9, -3, -7};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], -9);
  EXPECT_EQ(arr[1], -7);
  EXPECT_EQ(arr[2], -5);
  EXPECT_EQ(arr[3], -3);
  EXPECT_EQ(arr[4], -1);
}

// Тест 8: Смешанные числа (отрицательные, положительные, ноль)
TEST(BubbleSortTest, MixedNumbers) {
  int arr[] = {0, -5, 3, -1, 2, -8, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], -8);
  EXPECT_EQ(arr[1], -5);
  EXPECT_EQ(arr[2], -1);
  EXPECT_EQ(arr[3], 0);
  EXPECT_EQ(arr[4], 2);
  EXPECT_EQ(arr[5], 3);
  EXPECT_EQ(arr[6], 7);
}

// Тест 9: Проверка с разными типами данных
TEST(BubbleSortTest, DoubleType) {
  double arr[] = {3.14, 1.41, 2.71, 0.57};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_DOUBLE_EQ(arr[0], 0.57);
  EXPECT_DOUBLE_EQ(arr[1], 1.41);
  EXPECT_DOUBLE_EQ(arr[2], 2.71);
  EXPECT_DOUBLE_EQ(arr[3], 3.14);
}

// Тест 10 с компаратором для сортировки по убыванию
TEST(BubbleSortTest, SortsDescending) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  std::size_t size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size, std::greater<int>());

  EXPECT_EQ(arr[0], 90);
  EXPECT_EQ(arr[1], 64);
  EXPECT_EQ(arr[2], 34);
  EXPECT_EQ(arr[6], 11);
}

// Тест 11 с лямбда-компаратором
TEST(BubbleSortTest, SortsWithLambda) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  std::size_t size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size, [](int a, int b) {
    return a > b;  // по убыванию
  });

  EXPECT_EQ(arr[0], 90);
  EXPECT_EQ(arr[6], 11);
}

// Тест 12 с пользовательской структурой
struct Point {
  int x, y;
};

TEST(BubbleSortTest, SortsCustomStruct) {
  Point points[] = {{3, 4}, {1, 2}, {5, 1}, {0, 0}};
  std::size_t size = sizeof(points) / sizeof(points[0]);

  bubbleSort(points, size,
             [](const Point& a, const Point& b) { return a.x < b.x; });

  EXPECT_EQ(points[0].x, 0);
  EXPECT_EQ(points[1].x, 1);
  EXPECT_EQ(points[2].x, 3);
  EXPECT_EQ(points[3].x, 5);
}

// Тест 13 с std::string
TEST(BubbleSortTest, SortsStrings) {
  std::string arr[] = {"banana", "apple", "cherry", "date"};
  std::size_t size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], "apple");
  EXPECT_EQ(arr[1], "banana");
  EXPECT_EQ(arr[2], "cherry");
  EXPECT_EQ(arr[3], "date");
}

// Точка входа
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}