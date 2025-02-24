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
    static inline constexpr T distance(const Point2D<T>& p1, const Point2D<T>& p2)
};

#include "Point2D.tpp"

#endif