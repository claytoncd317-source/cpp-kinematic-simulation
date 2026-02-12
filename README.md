# physics-simulation-infrastructure

C++ simulation examples paired with infrastructure for running them as repeatable compute workloads.

This repository focuses on how simulation code is structured, stepped deterministically, and eventually packaged for execution outside a local development environment.

---

## About

The code explores fixed-timestep numerical simulation and treats the resulting executables as batch-style workloads rather than interactive applications.

Two small simulation modules are included now.
Infrastructure support is being added alongside them to enable containerized and cloud execution.

---

## Modules

### kinematic_mover

A minimal single-body simulation advanced under constant force using a semi-implicit Euler step.

Used to isolate the core motion integration logic found in real-time physics systems.

### particle_system

A many-body particle update similar to CPU-side passes used before rendering particle effects.

Includes gravity, damping, a ground constraint, and lifetime-based removal.

Each module builds independently with CMake.

---

## Build (Windows)

Requirements:

* Visual Studio 2022
* CMake 3.20 or newer

Use the **x64 Native Tools Command Prompt for VS 2022**.

Example:

cmake -S kinematic_mover -B kinematic_mover/build -G "Visual Studio 17 2022"
cmake --build kinematic_mover/build

The same pattern applies to `particle_system`.

---

## Running

Executables can be run directly from their build directories.
They output state information to the console and perform no rendering.

These are compute-only simulations.

---

## Infrastructure (in progress)

The `infra/` directory will contain:

* Docker definitions for packaging simulation runners
* Terraform configuration for provisioning execution environments
* Scripts for running simulations locally or remotely

---

## Roadmap

Planned additions:

* `sim_runner` module for config-driven batch simulation
* Container packaging for reproducible runs
* Terraform deployment for scheduled execution

---

## Intent

The goal is to bridge the gap between writing simulation code and operating it as part of a reproducible compute pipeline.
