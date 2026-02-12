#include "KinematicBody.h"

void KinematicBody::ApplyForce(const Vector2& force)
{
    accumulatedForce = accumulatedForce + force;
}

void KinematicBody::Update(float dt)
{
    velocity = velocity + accumulatedForce * dt;
    position = position + velocity * dt;

    accumulatedForce = Vector2(0.0f, 0.0f);
}

const Vector2& KinematicBody::GetPosition() const
{
    return position;
}
