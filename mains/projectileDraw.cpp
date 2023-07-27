#include "../src/ppm_writer.hpp"
#include "../src/canvas.hpp"


int main()
{
    auto pos = Point(0, 1, 0);
    auto vel = Vector::normalize(Vector(1, 1.8, 0));
    vel = vel * 11.25;

    const auto gravity = Vector(0, -0.1, 0);
    const auto wind    = Vector(-0.01, 0, 0);

    Canvas *canvas = new Canvas(900, 550);

    while (pos.y() > 0)
    {
        int y = 550 - pos.y();
        int x = pos.x();

        canvas->writePixel(x, y, Color(1, 1, 1));

        pos = Point(pos + vel);
        vel = vel + gravity + wind;
    }

    PPMWriter writer = PPMWriter(canvas);
    writer.writeFile("projectile.ppm");

    return 0;
}
