cmake_minimum_required(VERSION 3.18.3)
project(LeetCode)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(Utils)
add_subdirectory(SearchAlgorithms)
add_subdirectory(ArrayAndString)
add_subdirectory(DataStructures)
add_subdirectory(LinkedList)
