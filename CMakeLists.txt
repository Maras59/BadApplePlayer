cmake_minimum_required(VERSION 3.10)
project(OpenCVTest)

find_package(OpenCV REQUIRED)
find_package(Curses REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${CURSES_INCLUDE_DIR})

add_executable(OpenCVTest main.cpp)
target_link_libraries(OpenCVTest ${OpenCV_LIBS} ${CURSES_LIBRARIES})