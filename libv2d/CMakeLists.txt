cmake_minimum_required (VERSION 3.10)

project(libv2d)


aux_source_directory(src SOURCE_LIST)

add_library(libv2d SHARED ${SOURCE_LIST})
set_property(TARGET libv2d PROPERTY CMAKE_C_STANDARD 11)
set_property(TARGET libv2d PROPERTY CMAKE_C_STANDARD_REQUIRED ON)
set_property(TARGET libv2d PROPERTY CMAKE_C_EXTENSIONS OFF)

target_compile_definitions(libv2d PRIVATE DLL_EXPORT)


target_include_directories(libv2d PUBLIC include)



find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(libv2d PUBLIC SDL3::SDL3)

find_package(SDL3_ttf CONFIG REQUIRED)
target_link_libraries(libv2d PUBLIC SDL3_ttf::SDL3_ttf)

find_package(ICU REQUIRED COMPONENTS uc)
target_link_libraries(libv2d PUBLIC ${ICU_LIBRARIES})
target_include_directories(libv2d PUBLIC ${ICU_INCLUDE_DIRS})

find_package(cglm CONFIG REQUIRED)
    target_link_libraries(libv2d PRIVATE cglm::cglm)
