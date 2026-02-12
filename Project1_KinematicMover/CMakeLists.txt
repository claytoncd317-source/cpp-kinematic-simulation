cmake_minimum_required(VERSION 3.20)

project(KinematicMover LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(KinematicMover
    main.cpp
    src/Vector2.cpp
    src/KinematicBody.cpp
)

target_include_directories(KinematicMover PRIVATE include)
