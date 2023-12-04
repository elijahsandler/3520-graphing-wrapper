# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-src"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-build"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/tmp"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/src/commata-populate-stamp"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/src"
  "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/src/commata-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/src/commata-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/elija/OneDrive/Documents/courses/cs3520/3520-nn-project/cmake-build-debug/_deps/commata-subbuild/commata-populate-prefix/src/commata-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
