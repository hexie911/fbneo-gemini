cmake_minimum_required(VERSION 3.22.1)
project("fbneo_native")

# Set C++ standard requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include current directory for headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the shared native library
add_library(
    fbneo_native
    SHARED
    jni_glue.cpp
    # Note: Drop your FBNeo core source files / folders here or include them via add_subdirectory()
)

# Find necessary Android system libraries
find_library(
    log-lib
    log
)

find_library(
    android-lib
    android
)

# Link libraries to fbneo_native
target_link_libraries(
    fbneo_native
    ${log-lib}
    ${android-lib}
)
