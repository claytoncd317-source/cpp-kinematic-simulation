cmake_minimum_required(VERSION 3.20)

project(ParticleSystemSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ParticleSystemSim
    main.cpp
    src/Particle.cpp
    src/ParticleSystem.cpp

    # Reuse math implementation from Project 1
    ../Project1_KinematicMover/src/Vector2.cpp
)

target_include_directories(ParticleSystemSim PRIVATE
    include
    ../Project1_KinematicMover/include
)
