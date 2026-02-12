#include "ParticleSystem.h"
#include <iostream>

int main()
{
    ParticleSystem system;
    system.Emit(100);

    const float dt = 0.016f;

    for (int i = 0; i < 300; ++i)
    {
        system.Update(dt);

        if (i % 30 == 0)
        {
            std::cout << "Time: " << i * dt << " ";
            system.DebugPrint();
        }
    }

    return 0;
}
