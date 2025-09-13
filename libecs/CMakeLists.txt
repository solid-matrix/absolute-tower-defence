cmake_minimum_required (VERSION 3.10)

project(libecs)

aux_source_directory(src SOURCE_LIST)

add_library(libecs SHARED ${SOURCE_LIST})

set_property(TARGET libecs PROPERTY CMAKE_C_STANDARD 11)
set_property(TARGET libecs PROPERTY CMAKE_C_STANDARD_REQUIRED ON)
set_property(TARGET libecs PROPERTY CMAKE_C_EXTENSIONS OFF)

target_compile_definitions(libecs PRIVATE DLL_EXPORT)

target_include_directories(libecs PUBLIC include)