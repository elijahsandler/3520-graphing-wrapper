cmake_minimum_required(VERSION 3.26)

# This is for frugaly-deep
#include("cmake/HunterGate.cmake") # teach your project about Hunter (before project())
#HunterGate( # Latest release shown here: https://github.com/ruslo/hunter/releases
#        URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
#        SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
#        LOCAL # <----- load cmake/Hunter/config.cmake
#)

project(3520_nn_project)

set(CMAKE_CXX_STANDARD 17)

#hunter_add_package(frugally-deep)
#find_package(frugally-deep CONFIG REQUIRED)

add_subdirectory(matplotplusplus)

add_executable(3520_nn_project main.cpp)
target_link_libraries(3520_nn_project PUBLIC matplot)
#target_link_libraries(3520_nn_project PUBLIC frugally-deep::fdeep)