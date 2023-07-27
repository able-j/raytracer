#include "canvas.hpp"

void Canvas::writePixel(const int x, const int y, const Color& c)
{
    if (x < 0 || y < 0 || x >= this->width() || y >= this->height()) return;

    pixels_[y][x] = c;
}

Color Canvas::pixelAt(const int x, const int y) const
{
    return pixels_[y][x];
}

void Canvas::fill(const Color& c)
{
    for(int x = 0; x < this->width(); x++)
    {
        for(int y = 0; y < this->height(); y++)
        {
            this->writePixel(x, y, c);
        }
    }
}
