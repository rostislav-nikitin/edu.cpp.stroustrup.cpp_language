cmake_minimum_required(VERSION 3.14)

find_package(glfw3)

add_library(ui_abstractions STATIC abstractions/color.cpp  abstractions/point.cpp abstractions/point2i.cpp abstractions/compositeshape.cpp abstractions/icolorshape.cpp abstractions/idot.cpp)

add_library(ui_opengl_impl STATIC opengl_impl/dot.cpp opengl_impl/drawcontext.cpp opengl_impl/applicationwindow.cpp opengl_impl/application.cpp)
target_link_libraries(ui_opengl_impl ui_abstractions GL glfw3)

add_executable(app_opengl app_opengl.cpp)
target_link_libraries(app_opengl ui_opengl_impl)
