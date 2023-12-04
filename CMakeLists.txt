cmake_minimum_required(VERSION 3.26)

project(3520_nn_project)

set(CMAKE_CXX_STANDARD 17)

#include(FindPackageHandleStandardArgs)
#set(CMAKE_PREFIX_PATH "vcpkg/packages/eigen3_x64-windows/share/eigen3")
#find_package(Eigen3 REQUIRED)
#
#set(CMAKE_PREFIX_PATH "vcpkg/packages/fplus_x64-windows/share/FunctionalPlus")
#find_package(FunctionalPlus REQUIRED)
#
#set(CMAKE_PREFIX_PATH "vcpkg/packages/nlohmann-json_x64-windows/share/nlohmann_json")
#find_package(nlohmann_json REQUIRED)
#
#set(CMAKE_PREFIX_PATH "frugally-deep")
#find_package(frugally-deep CONFIG REQUIRED)

add_subdirectory(matplotplusplus)

add_executable(3520_nn_project main.cpp)
target_link_libraries(3520_nn_project PUBLIC matplot)
#target_link_libraries(3520_nn_project PRIVATE frugally-deep::fdeep)

