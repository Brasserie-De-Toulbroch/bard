cmake_minimum_required(VERSION 3.1.0)

project(bard)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing(true)

add_subdirectory(src)
add_subdirectory(tests)
