project(core)

add_compile_definitions(ANT_FARM_BUILD_CORE)

add_library(core SHARED src/core/Application.cpp src/core/docker/Docker.cpp src/core/docker/Container.cpp)

target_link_libraries(core PUBLIC curl)
target_include_directories(core PUBLIC src vendor/rapidjson/include /usr/include/x86_64-linux-gnu)
target_precompile_headers(core PUBLIC src/core/pch.h)