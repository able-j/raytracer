#include <iostream>
#include "../src/tuple.hpp"

int main()
{
    auto pos = Point(0, 1, 0);
    auto vel = Vector::normalize(Vector(1, 1, 0));

    const auto gravity = Vector(0, -0.1, 0);
    const auto wind    = Vector(-0.01, 0, 0);

    int tick = 0;

    while (pos.y() > 0)
    {
        std::cout << "Tick: " << tick << " pos(" << pos.x() << ", " << pos.y() << ", " << pos.z() << ")" << "\n";

        pos = Point(pos + vel);
        vel = vel + gravity + wind;

        tick++;
    }

    return 0;
}
