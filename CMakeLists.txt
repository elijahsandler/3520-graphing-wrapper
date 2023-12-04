cmake_minimum_required(VERSION 3.26)

project(3520_nn_project)

set(CMAKE_CXX_STANDARD 17)

include(FindPackageHandleStandardArgs)

# Set the main vcpkg directory
set(VCPKG_DIR "vcpkg/packages")

# Find Eigen3
find_package(Eigen3 REQUIRED)
include_directories(${Eigen3_INCLUDE_DIRS})

# Find FunctionalPlus
find_package(FunctionalPlus REQUIRED)
include_directories(${FunctionalPlus_INCLUDE_DIRS})

# Find nlohmann_json
find_package(nlohmann_json REQUIRED)
include_directories(${nlohmann_json_INCLUDE_DIRS})

# Find frugally-deep
find_package(frugally-deep CONFIG REQUIRED)
include_directories(${frugally-deep_INCLUDE_DIRS})

add_executable(3520_nn_project main.cpp)
target_link_libraries(3520_nn_project PRIVATE frugally-deep::fdeep)

