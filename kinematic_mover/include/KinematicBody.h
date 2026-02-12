#pragma once
#include "Vector2.h"

class KinematicBody
{
public:
    void ApplyForce(const Vector2& force);
    void Update(float dt);

    const Vector2& GetPosition() const;

private:
    Vector2 position;
    Vector2 velocity;
    Vector2 accumulatedForce;
};
