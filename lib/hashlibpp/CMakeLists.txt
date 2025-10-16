add_library(hashlibpp
    hl_exception.h
    hl_hashwrapper.h
    hl_md5.cpp
    hl_md5.h
    hl_md5wrapper.cpp
    hl_md5wrapper.h
    hl_types.h
)
target_include_directories(hashlibpp PUBLIC "${PROJECT_SOURCE_DIR}/lib/hashlibpp")
