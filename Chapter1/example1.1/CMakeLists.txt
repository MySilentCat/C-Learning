cmake_minimum_required(VERSION 3.0)

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(example1_1 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

add_executable(example1_1 example1_1.c)