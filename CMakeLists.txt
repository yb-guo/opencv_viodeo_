cmake_minimum_required(VERSION 3.10)
PROJECT(yolov8)

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")

message(*********************************************************)
message(STATUS CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR})
message(*********************************************************)
# 生成 config.h 头文件
configure_file(src/config.h.in config.h)

message(STATUS ${ALL_LIBS})

find_package(OpenCV REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS} 
  ${CMAKE_CURRENT_SOURCE_DIR}
)

message(*********************************************************)
message(STATUS ***OpenCV_INCLUDE_DIRS*** = ${OpenCV_INCLUDE_DIRS})
message(*********************************************************)

add_executable(vidio_executable 
              src/main.cpp 
)
target_link_libraries(vidio_executable ${OpenCV_LIBS} )  
