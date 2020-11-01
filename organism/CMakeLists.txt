project(organism)

include_directories(../core/src)
include_directories(src)

add_executable(organism src/organism/OrganismApp.cpp)

target_link_libraries(organism core curl)