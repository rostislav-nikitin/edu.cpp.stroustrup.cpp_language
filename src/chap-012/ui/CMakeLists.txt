cmake_minimum_required(VERSION 3.14)
project(UILibrary)

find_package(glfw3)

#add_library(ui_system STATIC system/)

add_library(ui_abstractions STATIC abstractions/color.cpp  abstractions/point.cpp abstractions/point2i.cpp abstractions/ishape.cpp abstractions/compositeshape.cpp abstractions/icolorshape.cpp abstractions/icircle.cpp abstractions/irectangle.cpp abstractions/itriangle.cpp abstractions/iline.cpp abstractions/idot.cpp abstractions/igrid.cpp abstractions/ixycoordinates.cpp)

add_library(ui_engine STATIC engine/collisiondetector.cpp)
target_link_libraries(ui_engine ui_abstractions)

add_library(ui_opengl_impl STATIC opengl_impl/xycoordinates.cpp opengl_impl/grid.cpp opengl_impl/circle.cpp opengl_impl/rectangle.cpp opengl_impl/triangle.cpp opengl_impl/line.cpp opengl_impl/dot.cpp opengl_impl/drawcontext.cpp opengl_impl/applicationwindow.cpp opengl_impl/applicationconfig.cpp opengl_impl/application.cpp)
target_link_libraries(ui_opengl_impl ui_abstractions ui_engine GL glfw3)

add_executable(app_opengl app_opengl.cpp)
target_link_libraries(app_opengl ui_opengl_impl)


include(FetchContent)
FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest
		GIT_TAG v1.14.0)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(engine_tests_runner engine.tests/tests_runner.cpp)
target_link_libraries(engine_tests_runner gtest gmock ui_abstractions ui_engine)

add_executable(abstractions_tests_runner abstractions.tests/tests_runner.cpp)
target_include_directories(abstractions_tests_runner PRIVATE ./)
target_link_libraries(abstractions_tests_runner ui_abstractions gtest gmock)
