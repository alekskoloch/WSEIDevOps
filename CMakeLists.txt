cmake_minimum_required( VERSION 3.28 )

project( WSEIDevOps )

add_executable( WSEIDevOps src/main.cpp src/DataLoader.hpp src/DataLoader.cpp src/Mountain.hpp )

enable_testing()

include( FetchContent )
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable( googletest )

FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.zip
)
FetchContent_MakeAvailable( nlohmann_json )

add_executable( exampleTest tests/exampleTest.cpp )

target_link_libraries( WSEIDevOps nlohmann_json )

target_link_libraries( exampleTest gtest_main )

add_test( NAME ExampleTest COMMAND exampleTest )