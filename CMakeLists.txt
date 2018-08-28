cmake_minimum_required(VERSION 2.6)
project (CppSceptor)
set(CppSceptor_VERSION_MAJOR 1)
set(CppSceptor_VERSION_MINOR 1)

# actually place the version numbers into a header file.
configure_file(
  "${PROJECT_SOURCE_DIR}/CppSceptor.h.in"
  "${PROJECT_BINARY_DIR}/CppSceptor.h"
  )

# add the binary tree to the search path for some include files
include_directories("${PROJECT_BINARY_DIR}")

add_executable(CppSceptor CppSceptor.cpp)
