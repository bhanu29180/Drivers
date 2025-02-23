#ifndef POINTND_H
#define POINTND_H

#include <cstddef>

template <typename T, std::size_t N>
class PointND
{
public:
    T coordinates[N];

    //Constructors
    constexpr PointND();
    constexpr PointND(const T* coordinates_);
};

#include "PointND.tpp"

#endif