cmake_minimum_required(VERSION 3.14)

project(FileSystem)

include(FetchContent)

FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest
		GIT_TAG v1.14.0)

#FetchContent_MakeAvailable(GoogleTest)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)

	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()
		

add_library(filesystem fs.cpp)

add_executable(use_fs use_fs.cpp)
target_link_libraries(use_fs filesystem)
