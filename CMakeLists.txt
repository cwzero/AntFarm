cmake_minimum_required(VERSION 3.16)

project(ant_farm)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(cluster)
add_subdirectory(core)
add_subdirectory(generation)
add_subdirectory(organism)