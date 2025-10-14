cmake_minimum_required(VERSION 3.22)
project(UltravioletMVC VERSION 0.8)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(hashlibpp lib/hashlibpp/hl_md5.cpp lib/hashlibpp/hl_md5wrapper.cpp)
target_include_directories(hashlibpp PUBLIC lib/hashlibpp)

add_executable(index)
target_sources(index PRIVATE "bin/index.cpp")
target_link_libraries(index hashlibpp)
target_include_directories(index PRIVATE
    "${PROJECT_SOURCE_DIR}/lib/uv"
    "${PROJECT_SOURCE_DIR}/lib"
)
add_subdirectory(lib/uv/cgi)
add_subdirectory(lib/uv/core)
add_subdirectory(lib/uv/framework)
add_subdirectory(lib/uv/view)
