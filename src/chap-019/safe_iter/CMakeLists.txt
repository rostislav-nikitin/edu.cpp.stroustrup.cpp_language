cmake_minimum_required(VERSION 3.14)

project(SafeContainer)

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


add_executable(use_safe_container use_safe_container.cpp)

add_executable(safe_container_test_runner safe_container_test_runner.cpp)
target_link_libraries(safe_container_test_runner gtest gmock)
