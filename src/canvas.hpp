#ifndef CANVAS_HPP_
#define CANVAS_HPP_

#include "color.hpp"
#include <vector>

class Canvas
{
public:
    Canvas(const int width, const int height) : width_(width), height_(height),
                                                pixels_(height,
                                                        std::vector<Color>(width, Color(0, 0, 0))) {};
    ~Canvas() = default;

    int width() const { return width_; }
    int height() const { return height_; }

    void  writePixel(const int x, const int y, const Color& c);
    Color pixelAt(const int x, const int y) const;
    void fill(const Color& c);

private:
    int width_, height_;
    std::vector<std::vector<Color>> pixels_;
};

#endif
