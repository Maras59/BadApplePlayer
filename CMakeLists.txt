cmake_minimum_required(VERSION 3.10)
project(OpenCVTest)

find_package(OpenCV REQUIRED)

add_executable(OpenCVTest main.cpp)
target_link_libraries(OpenCVTest ${OpenCV_LIBS})