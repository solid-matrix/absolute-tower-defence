cmake_minimum_required (VERSION 3.10)

project(game)


aux_source_directory(src SOURCE_LIST)

add_executable (game ${SOURCE_LIST})
set_property(TARGET game PROPERTY CMAKE_C_STANDARD 11)
set_property(TARGET game PROPERTY CMAKE_C_STANDARD_REQUIRED ON)
set_property(TARGET game PROPERTY CMAKE_C_EXTENSIONS OFF)

target_include_directories(game PRIVATE include)

target_link_libraries(game PRIVATE libv2d)

