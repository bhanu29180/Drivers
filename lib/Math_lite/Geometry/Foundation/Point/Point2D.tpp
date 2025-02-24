#include "Point2D.h"

template <typename T>
constexpr Point2D<T>::Point2D() : x(0), y(0)
{
}

template <typename T>
constexpr Point2D<T>::Point2D(T x, T y): x(x), y(y)
{
}

template <typename T>
inline constexpr T distance(const Point2D<T>& p1, const Point2D<T>& p2)
{
    return std::sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}