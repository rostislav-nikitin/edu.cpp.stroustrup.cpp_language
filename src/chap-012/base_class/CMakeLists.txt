cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(test_runner base.cpp derived_one.cpp derived_two.cpp test_runner.cpp)

target_link_libraries(test_runner gtest)
