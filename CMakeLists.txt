cmake_minimum_required(VERSION 3.22)
project(UltravioletMVC VERSION 0.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(index)
target_sources(index PRIVATE "bin/index.cpp")
target_include_directories(index PRIVATE
    "${PROJECT_SOURCE_DIR}/lib/uv"
    "${PROJECT_SOURCE_DIR}/lib"
)
add_subdirectory(lib/hashlibpp)
add_subdirectory(lib/uv/cgi)
add_subdirectory(lib/uv/core)
add_subdirectory(lib/uv/framework)
add_subdirectory(lib/uv/view)
