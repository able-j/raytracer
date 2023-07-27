#include "ppm_writer.hpp"

#include <fstream>
#include <string>

constexpr int MAX_LINE_PPM = 70;

static inline int mapFloatToInt(const float f)
{
    const int mappedValue = static_cast<int>(f * 256.f);

    if (mappedValue < 0) return 0;
    else if (mappedValue > 255) return 255;
    else return mappedValue;
}

static inline void writeFloat(std::ostream& os, const float value, int& len)
{
    const int c = mapFloatToInt(value);
    const int cLen = std::to_string(c).size();

    if (len + cLen + 1 > MAX_LINE_PPM)
    {
        os << "\n";
        len = 0;
    }
    else if (len > 0)
    {
        os << " ";
        len++;
    }

    os << c;
    len += cLen;
}

void PPMWriter::constructHeader(std::ostream& os) const
{
    os << "P3\n" << canvas_->width() << " " << canvas_->height() << "\n255\n";
}

void PPMWriter::constructPixels(std::ostream& os) const
{
    int len = 0;

    for (int y = 0; y < canvas_->height(); y++)
    {
        for (int x = 0; x < canvas_->width(); x++)
        {
            Color c = canvas_->pixelAt(x, y);

            writeFloat(os, c.r(), len);
            writeFloat(os, c.g(), len);
            writeFloat(os, c.b(), len);
        }

        os << "\n";
        len = 0;
    }
}

void PPMWriter::writeStream(std::ostream& os) const
{
    constructHeader(os);
    constructPixels(os);
}

void PPMWriter::writeFile(std::string f) const
{
    std::ofstream out;

    out.open(f);
    writeStream(out);
    out.close();
}
