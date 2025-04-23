cmake_minimum_required(VERSION 3.10)
project(BadApple)

find_package(OpenCV REQUIRED)
find_package(Curses REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${CURSES_INCLUDE_DIR})

add_executable(BadApple main.cpp)
target_link_libraries(BadApple ${OpenCV_LIBS} ${CURSES_LIBRARIES})