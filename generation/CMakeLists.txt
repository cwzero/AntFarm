project(generation)

include_directories(../core/src)
include_directories(src)

add_executable(generation src/generation/GenerationApp.cpp)

target_link_libraries(generation core curl)