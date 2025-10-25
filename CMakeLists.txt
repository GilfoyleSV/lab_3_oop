cmake_minimum_required(VERSION 3.10)

project(FigureInheritance CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    main.cpp
    figure.cpp
    rhombus.cpp
    five_side.cpp
    six_side.cpp
    array.cpp
)

add_executable(figure_app ${SOURCE_FILES})

target_include_directories(figure_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})