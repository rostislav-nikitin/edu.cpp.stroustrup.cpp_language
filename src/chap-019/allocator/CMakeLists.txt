cmake_minimum_required(VERSION 3.14)

project(Vector)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY "https://github.com/google/googletest.git"
  GIT_TAG "v1.14.0")

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(test_runner_allocator test_runner_allocator.cpp)
target_link_libraries(test_runner_allocator gtest gmock)

add_executable(test_runner_pool test_runner_pool.cpp)
target_link_libraries(test_runner_pool gtest gmock)

add_executable(test_runner_vector test_runner_vector.cpp)
target_link_libraries(test_runner_vector gtest gmock)
