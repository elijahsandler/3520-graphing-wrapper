cmake_minimum_required(VERSION 3.26)
project(3520_nn_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(matplotplusplus)

add_executable(3520_nn_project main.cpp)
target_link_libraries(3520_nn_project PUBLIC matplot)