#include <iostream>
#include "KinematicBody.h"

int main()
{
    KinematicBody body;

    const float dt = 0.016f; // 60 Hz simulation

    for (int i = 0; i < 120; ++i)
    {
        body.ApplyForce(Vector2(10.0f, 0.0f));
        body.Update(dt);

        const Vector2& pos = body.GetPosition();

        std::cout << "Time: " << i * dt
            << "  Position: (" << pos.x << ", " << pos.y << ")\n";
    }

    return 0;
}
