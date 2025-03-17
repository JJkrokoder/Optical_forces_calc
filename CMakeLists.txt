# CMakeLists.txt for OFC
cmake_minimum_required(VERSION 3.28)    # CMake version check
project(OFC VERSION 1.0.0)              # Create project "OFC"
set(PROJECT_AUTHOR "Joan Ronquillo")    # Set the author of the project
set(PROJECT_DESCRIPTION "Optical Forces Calculation with C++") # Set the description of the project

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)   # Require c++20 standard

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # Generate compile_commands.json

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)     # Set the output directory for executables
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)     # Set the output directory for libraries

# Add the subdirectories
add_subdirectory(src)                   # Add the src directory
add_subdirectory(test)                  # Add the test directory
add_subdirectory(doc)                   # Add the doc directory

enable_testing()                        # Enable testing


