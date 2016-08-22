cmake_minimum_required(VERSION 2.8.7)
project(HughAlg C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Includes
set(HUGHALG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${HUGHALG_INCLUDE_DIR} ${PROJECT_BINARY_DIR})
include_directories(BEFORE test)

add_subdirectory(test/gtest)
#add_subdirectory(test/test)

