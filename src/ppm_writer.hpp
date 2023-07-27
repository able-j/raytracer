#ifndef PPM_WRITER_HPP_
#define PPM_WRITER_HPP_

#include "canvas.hpp"
#include "color.hpp"

#include <ostream>
#include <string>

class PPMWriter
{
public:
    PPMWriter(const Canvas *canvas) : canvas_(canvas) {};
    ~PPMWriter() = default;

    void constructHeader(std::ostream& os) const;
    void constructPixels(std::ostream& os) const;
    void writeStream(std::ostream& os) const;
    void writeFile(std::string f) const;

private:
    const Canvas *canvas_;
};

#endif
