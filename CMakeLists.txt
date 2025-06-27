cmake_minimum_required(VERSION 4.0)

project(DoThing CXX)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# file(GLOB_RECURSE HDR_FILES ${PROJECT_SOURCE_DIR}/src/*.hpp)

source_group(TREE "${PROJECT_SOURCE_DIR}" PREFIX "Source Files" FILES ${SRC_FILES})
# source_group(TREE "${PROJECT_SOURCE_DIR}" PREFIX "Header Files" FILES ${HDR_FILES})

add_subdirectory(${PROJECT_SOURCE_DIR}/minhook)

add_executable(DoThing ${SRC_FILES} ${HDR_FILES})
target_sources(DoThing PRIVATE)

target_link_libraries(DoThing minhook)

target_include_directories(DoThing PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

add_dependencies(DoThing minhook)
