cmake_minimum_required(VERSION 2.8.7)
project(HughAlg C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -pthread")

# Includes
set(HUGHALG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${HUGHALG_INCLUDE_DIR} ${PROJECT_BINARY_DIR})
include_directories(BEFORE test)

# build
set(HUGHALG_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${HUGHALG_BUILD_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${HUGHALG_BUILD_DIR}/lib)

# libs
link_directories(${HUGHALG_BUILD_DIR}/lib)

add_subdirectory(test/gtest)
add_subdirectory(test)

