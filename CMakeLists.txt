cmake_minimum_required(VERSION 3.10)

project(FigureInheritance CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    main.cpp
    src/figure.cpp
    src/rhombus.cpp
    src/five_side.cpp
    src/six_side.cpp
    src/array.cpp
)

add_executable(figure_app ${SOURCE_FILES})
target_include_directories(figure_app PRIVATE include)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_lab
  ./gtests.cpp
  src/figure.cpp
  src/rhombus.cpp
  src/five_side.cpp
  src/six_side.cpp
  src/array.cpp
)

target_include_directories(test_lab PRIVATE include)

target_link_libraries(
    test_lab
    PRIVATE 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_lab)