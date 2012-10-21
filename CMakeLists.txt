cmake_minimum_required(VERSION 2.8)

project(check++)

set(CMAKE_CXX_FLAGS "-std=c++0x")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src/main
  ${PROJECT_SOURCE_DIR}/src/test
)

# Google test
add_subdirectory(${PROJECT_SOURCE_DIR}/gtest-1.6.0)
include_directories(${PROJECT_SOURCE_DIR}/gtest-1.6.0/include)

# Build library

# TODO

# Build test programs
