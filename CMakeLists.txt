cmake_minimum_required(VERSION 3.20)
project(exercise02_solution)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(exercise02_solution
    solution.cpp base64.cpp)
