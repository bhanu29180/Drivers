#ifndef POINT1D_H
#define POINT1D_H

#include <cmath>

template <typename T>
class Point1D
{
public:
    T x = T(0);
    
    constexpr Point1D();
    constexpr Point1D(T x);
    static inline constexpr T distance(const Point1D<T>& p1, const Point1D<T>& p2);
    static inline constexpr bool is_coincident(const Point1D<T>& p1, const Point1D<T>& p2);
};

#include "Point1D.tpp"

#endif