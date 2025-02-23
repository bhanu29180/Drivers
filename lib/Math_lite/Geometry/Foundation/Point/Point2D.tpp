#include "Point2D.h"

template <typename T>
constexpr Point2D<T>::Point2D() : x(0), y(0)
{
}

template <typename T>
constexpr Point2D<T>::Point2D(T x, T y): x(x), y(y)
{
}