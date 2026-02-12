#pragma once
#include "Particle.h"
#include <vector>

class ParticleSystem
{
public:
    void Emit(int count);
    void Update(float dt);
    void DebugPrint() const;

private:
    std::vector<Particle> particles;

    Vector2 gravity = Vector2(0.0f, -9.8f);
    float damping = 0.98f;
};
