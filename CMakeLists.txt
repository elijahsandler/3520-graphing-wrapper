cmake_minimum_required(VERSION 3.26)

project(3520_nn_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(matplotplusplus)
include(FetchContent)

FetchContent_Declare(
        commata
        GIT_REPOSITORY https://github.com/furfurylic/commata.git
        GIT_TAG        master       # In fact, a commit hash is better
)

FetchContent_MakeAvailable(commata)



add_executable(cpp_graphing main.cpp
        include/geoGrapher.h
        src/geoGrapher.cpp
        src/geoGrapher.cpp)
target_link_libraries(cpp_graphing PUBLIC matplot)
target_link_libraries(cpp_graphing PRIVATE commata)

