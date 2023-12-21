cmake_minimum_required(VERSION 3.14)

project(itors)

include(FetchContent)

FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest
		GIT_TAG v1.14.0)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	message("Downaloading GoogleTest")
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(use use.cpp)

add_executable(test_runner_vector test_runner_vector.cpp)
target_link_libraries(test_runner_vector gtest gmock)
