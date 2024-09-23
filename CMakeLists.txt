cmake_minimum_required(VERSION 3.30.3)
project(cpp_stl)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/Product.cpp
    src/Order.cpp
    src/main.cpp
)

include_directories(include)

add_executable(cpp_stl ${SOURCES})

