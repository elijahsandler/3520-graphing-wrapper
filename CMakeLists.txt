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
#target_link_libraries(3520_nn_project PRIVATE frugally-deep::fdeep)

