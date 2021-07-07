cmake_minimum_required(VERSION 3.16)
project(non-parallel-simple-vector-add)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(non-parallel-simple-vector-add
  non-parallel-simple-vector-add.cpp
)

target_compile_options(non-parallel-simple-vector-add PRIVATE 
  -std=c++20 -stdlib=libstdc++
)

