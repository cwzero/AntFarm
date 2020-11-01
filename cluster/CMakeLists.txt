project(cluster)

include_directories(../core/src)
include_directories(src)

add_executable(cluster src/cluster/ClusterApp.cpp)

target_link_libraries(cluster core curl)