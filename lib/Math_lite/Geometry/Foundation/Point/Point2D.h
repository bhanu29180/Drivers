#ifndef POINT2D_H
#define POINT2D_H

template <typename T>
class Point2D
{
public:
    T x = T(0);
    T y = T(0);

    constexpr Point2D();
    constexpr Point2D(T x, T y);
};

#include "Point2D.tpp"

#endif