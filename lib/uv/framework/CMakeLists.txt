add_library(uv_framework_lib
    Application.h
    Config.cpp
    Config.h
)
target_link_libraries(uv_framework_lib uv_core_lib)
target_include_directories(uv_framework_lib PRIVATE ${PROJECT_INCLUDE_DIRS})
