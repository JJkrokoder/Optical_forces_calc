include(FetchContent)                             # Include the FetchContent module
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test_core test_core.cpp) # Compile a test source
# Link against any required libraries. The library is compiled in src/
target_link_libraries(test_core OFC_core)
gtest_discover_tests(test_core)            # Register the tests to gtest

add_executable(test_permittivity test_permittivity.cpp) # Compile a test source
target_link_libraries(test_permittivity dielectric_optcoeff)
gtest_discover_tests(test_permittivity)    # Register the tests to gtest