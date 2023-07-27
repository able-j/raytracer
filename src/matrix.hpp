#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>
#include <cstdint>
#include <initializer_list>
#include "math.hpp"

template <size_t rows, size_t cols>
class Matrix
{
public:
    Matrix() : data_(rows * cols, 0) {};
    Matrix(const std::initializer_list<float> il) : data_(il) {};

    float &operator()(const int row, const int col)
        { return data_[row * cols + col]; }
    float const& operator()(const int row, const int col) const
        { return data_[row * cols + col]; }

    size_t width() const { return cols; }
    size_t height() const { return rows; }

    bool operator==(const Matrix &m) const
        {
            if (m.width() != cols || m.height() != rows)
                return false;

            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    if (!epsilonEquals((*this)(i, j), m(i, j)))
                        return false;
                }
            }

            return true;
        }

    bool operator!=(const Matrix &m) const
        {
            return !((*this) == m);
        }

private:
    std::vector<float> data_;
};

#endif
