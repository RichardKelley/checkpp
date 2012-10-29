cmake_minimum_required(VERSION 2.8)

project(check++)

set(CMAKE_CXX_FLAGS "-std=c++0x")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

option(BUILD_TESTS FALSE)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src/main
  ${PROJECT_SOURCE_DIR}/src/test
)

# Google test
if (BUILD_TESTS)
add_subdirectory(${PROJECT_SOURCE_DIR}/gtest-1.6.0)
include_directories(${PROJECT_SOURCE_DIR}/gtest-1.6.0/include)

# Build test programs
add_executable(test_arbitrary
  src/main/arbitrary.cpp
  src/main/result.cpp
  src/test/test_arbitrary.cpp
)
target_link_libraries(test_arbitrary gtest_main)

add_executable(test_property
  src/main/result.cpp
  src/test/test_property.cpp
)
target_link_libraries(test_property gtest_main)

add_executable(test_checkpp
  src/main/arbitrary.cpp
  src/main/result.cpp
  src/test/test_checkpp.cpp
)
target_link_libraries(test_checkpp gtest_main)

add_executable(test_condition
  src/main/result.cpp
  src/test/test_condition.cpp 
)
target_link_libraries(test_condition gtest_main)
endif(BUILD_TESTS)

# Build library
add_library(checkpp SHARED
  src/main/result.cpp
  src/main/arbitrary.cpp
)
