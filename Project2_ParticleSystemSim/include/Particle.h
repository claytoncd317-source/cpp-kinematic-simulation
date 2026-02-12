#pragma once
#include "../../Project1_KinematicMover/include/Vector2.h"

struct Particle
{
    Vector2 position;
    Vector2 velocity;
    float lifetime;

    bool IsAlive() const;
};
