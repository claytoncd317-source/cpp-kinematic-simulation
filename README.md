# physics-simulation-infrastructure

This repository contains small C++ programs used to study fixed-timestep simulation and how those programs can be packaged and executed as reproducible workloads.

The repository has two main parts:

* The `Project*` directories contain the simulation code.
* The `infra/` directory will contain container and infrastructure definitions used to run simulations locally or in the cloud.

---

## Projects

### Project1_KinematicMover

Simulates a single body moving under a constant force using a semi-implicit Euler integrator.

This project focuses on:

* A deterministic update loop
* Numerical integration of motion
* Clear separation between math types, physical state, and the stepping routine

### Project2_ParticleSystemSim

Simulates many independent particles similar to CPU-side particle updates used before rendering in a graphics engine.

This project focuses on:

* Updating large numbers of simple bodies
* Gravity, damping, and a ground constraint
* Lifetime tracking and removal of expired particles

Each project builds independently using its own CMake configuration.

---

## Build (Windows)

Requirements:

* Visual Studio 2022
* CMake 3.20 or newer

Use the “x64 Native Tools Command Prompt for VS 2022”.

Example build:

cmake -S Project1_KinematicMover -B Project1_KinematicMover/build -G "Visual Studio 17 2022"
cmake --build Project1_KinematicMover/build

---

## Infrastructure (Work in Progress)

The `infra/` directory will contain:

* Docker definitions for packaging simulation binaries
* Terraform configuration for provisioning compute resources
* Scripts for running batch simulation jobs

---

## Intent

The goal is to treat simulation code as a workload that can be executed repeatedly and predictably, not just as a standalone application.
