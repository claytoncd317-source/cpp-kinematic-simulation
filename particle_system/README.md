# ParticleSystemSim

Lightweight multi-body simulation similar to the CPU-side update used for real-time particle effects.

The program advances independent particles under simple forces and removes them once their lifetime expires.

## State

Each particle stores:

* position
* velocity
* remaining lifetime

Particles do not interact with each other. This keeps the system simple and easy to scale.

## Forces

Gravity is applied every step as a constant downward acceleration.

`v = v + g * dt`

Velocity is slightly reduced each frame to approximate drag.

`v = v * damping`

If a particle moves below the ground plane, its position is clamped and the vertical velocity is reflected with energy loss.

Each particle’s lifetime is reduced by the timestep and the particle is removed once it reaches zero.

## Integration

Motion is advanced using the same semi-implicit Euler step as the kinematic example.

Velocity is updated first, then position is updated using the new velocity.

`x = x + v * dt`

## Update Loop

Each frame performs the same sequence:

1. Emit particles
2. Integrate motion
3. Apply ground constraint
4. Age particles
5. Remove expired particles

## Build

From the Visual Studio Native Tools prompt:

```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build
build\Debug\ParticleSystemSim.exe
```

## Notes

This project focuses only on the simulation stage typically executed before particle data is uploaded to the GPU.
