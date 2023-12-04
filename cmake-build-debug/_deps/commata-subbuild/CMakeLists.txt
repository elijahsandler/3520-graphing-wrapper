# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.26.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(commata-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[C:/Program Files/Git/cmd/git.exe]==])
set(GIT_VERSION_STRING [==[2.39.1.windows.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[C:/Program Files/Git/cmd/git.exe;2.39.1.windows.1]==]
)


include(ExternalProject)
ExternalProject_Add(commata-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/furfurylic/commata.git" "GIT_TAG" "master"
                    SOURCE_DIR          "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-src"
                    BINARY_DIR          "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


