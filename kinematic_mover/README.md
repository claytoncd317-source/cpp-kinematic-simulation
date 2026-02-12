# KinematicMover

Small deterministic simulation that advances a single body under constant force using a fixed timestep.

This example isolates the core integration step used inside real-time physics systems.

## Model

The motion follows Newton's second law.

`F = m * a`

Mass is set to one, so applied force directly defines acceleration.

The program does not solve the equation analytically.
Instead, it advances the state numerically at a fixed interval (`dt = 0.016` seconds).

## Integration

A semi-implicit Euler step is used.

Velocity update:

`v = v + a * dt`

Position update:

`x = x + v * dt`

This ordering is commonly used in real-time engines because it is stable and inexpensive.

## Update Step

Each simulation tick performs:

1. Accumulate force
2. Update velocity
3. Update position
4. Clear the force accumulator

Because the timestep is fixed, results are deterministic.

## Build

From the Visual Studio Native Tools prompt:

```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build
build\Debug\KinematicMover.exe
```

## Notes

This project is intentionally minimal and serves as a reference implementation of fixed-step motion integration.
