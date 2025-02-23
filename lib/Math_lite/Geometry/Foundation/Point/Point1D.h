#ifndef POINT1D_H
#define POINT2D_H

template <typename T>
class Point1D
{
public:
    T x = T(0);
    
    constexpr Point1D();
    constexpr Point1D(T x);
};

#include "Point1D.tpp"

#endif