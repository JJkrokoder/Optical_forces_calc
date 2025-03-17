# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)    # include directory
add_library(OFC_core SHARED OFC_core.cpp)                   # create a shared library

