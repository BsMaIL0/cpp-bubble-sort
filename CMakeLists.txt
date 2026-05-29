cmake_minimum_required(VERSION 3.17)
project(BubbleSort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests googleTests.cpp)  

target_link_libraries(tests PRIVATE gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)