#include "Particle.h"

bool Particle::IsAlive() const
{
    return lifetime > 0.0f;
}
