add_library(uv_core_lib
    Ini.cpp
    Ini.h
    Random.cpp
    Random.h
    Strlib.cpp
    Strlib.h
)
target_include_directories(uv_core_lib PUBLIC lib/core)
