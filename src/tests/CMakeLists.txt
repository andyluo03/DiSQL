cmake_minimum_required(VERSION 3.28.2)
project(DiSQL_Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

enable_testing()

add_executable(
  parse_test
  parse_tests.cpp
)

add_library(
  lexxer
  ../lexxer.cpp
)

add_library(
  parser
  ../parser.cpp
)

target_link_libraries(
  parse_test
  lexxer
  parser
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(parse_test)