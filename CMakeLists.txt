cmake_minimum_required(VERSION 3.22)
project(UltravioletMVC VERSION 0.8.1)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set common include dirs
set(PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/uv" "${PROJECT_SOURCE_DIR}/lib")

# Pull in subdirectory libraries
add_subdirectory(lib/hashlibpp)
add_subdirectory(lib/uv/core)
add_subdirectory(lib/uv/cgi)
add_subdirectory(lib/uv/framework)
add_subdirectory(lib/uv/view)

# Index app file
add_executable(index)
target_sources(index PRIVATE "bin/index.cpp")
target_link_libraries(index hashlibpp uv_core_lib uv_cgi_lib uv_framework_lib uv_view_lib)
target_include_directories(index PRIVATE ${PROJECT_INCLUDE_DIRS})

# Info app file
add_executable(info)
target_sources(info PRIVATE "bin/info.cpp")
target_link_libraries(info hashlibpp uv_core_lib uv_cgi_lib uv_framework_lib uv_view_lib)
target_include_directories(info PRIVATE ${PROJECT_INCLUDE_DIRS})
