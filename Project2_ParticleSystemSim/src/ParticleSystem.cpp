#include "ParticleSystem.h"
#include <iostream>
#include <random>

void ParticleSystem::Emit(int count)
{
    std::default_random_engine rng;
    std::uniform_real_distribution<float> vel(-5.0f, 5.0f);

    for (int i = 0; i < count; ++i)
    {
        Particle p;
        p.position = Vector2(0.0f, 0.0f);
        p.velocity = Vector2(vel(rng), vel(rng) + 10.0f);
        p.lifetime = 3.0f;

        particles.push_back(p);
    }
}

void ParticleSystem::Update(float dt)
{
    for (auto& p : particles)
    {
        if (!p.IsAlive())
            continue;

        // Integrate velocity from gravity
        p.velocity = p.velocity + gravity * dt;

        // Integrate position from velocity
        p.position = p.position + p.velocity * dt;

        // Apply damping (air resistance)
        p.velocity = p.velocity * damping;

        // Simple ground collision
        if (p.position.y < 0.0f)
        {
            p.position.y = 0.0f;
            p.velocity.y *= -0.5f; // energy loss bounce
        }

        p.lifetime -= dt;
    }
}

void ParticleSystem::DebugPrint() const
{
    int alive = 0;
    for (const auto& p : particles)
        if (p.IsAlive()) alive++;

    std::cout << "Alive Particles: " << alive << "\n";
}
