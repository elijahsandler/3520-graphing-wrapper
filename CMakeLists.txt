cmake_minimum_required(VERSION 3.26)

project(geographer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(matplotplusplus)
include(FetchContent)

FetchContent_Declare(
        commata
        GIT_REPOSITORY https://github.com/furfurylic/commata.git
        GIT_TAG        master       # In fact, a commit hash is better
)

FetchContent_MakeAvailable(commata)

add_executable(geographer main.cpp
        lib/include/geoGrapher.h
        lib/src/geoGrapher.cpp)
target_link_libraries(geographer PUBLIC matplot)
target_link_libraries(geographer PRIVATE commata)

