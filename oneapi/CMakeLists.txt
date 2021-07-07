cmake_minimum_required(VERSION 3.16)
project(simple-vector-add)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(simple-vector-add
  simple-vector-add.cpp
)

target_compile_options(simple-vector-add PRIVATE 
  -std=c++20 -stdlib=libstdc++
)

