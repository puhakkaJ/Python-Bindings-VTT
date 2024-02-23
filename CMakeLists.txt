cmake_minimum_required(VERSION 3.12)
project(ImageModifierPython)

find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(ImageModifierModule bindings.cpp)
set_target_properties(ImageModifierModule PROPERTIES OUTPUT_NAME "ImageModifierModule")

target_include_directories(ImageModifierModule PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(ImageModifierModule PRIVATE ${OpenCV_LIBS})