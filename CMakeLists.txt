cmake_minimum_required( VERSION 3.28 )

project( WSEIDevOps )

add_executable( WSEIDevOps src/main.cpp )

enable_testing()

include( FetchContent )
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable( googletest )

add_executable( exampleTest tests/exampleTest.cpp )

target_link_libraries( exampleTest gtest_main )

add_test( NAME ExampleTest COMMAND exampleTest )