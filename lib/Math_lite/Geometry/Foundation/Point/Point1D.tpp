#include "Point1D.h"

template <typename T>
constexpr Point1D<T>::Point1D() : x(0)
{
}

template <typename T>
constexpr Point1D<T>::Point1D(T x): x(x)
{
}

template <typename T>
inline constexpr T Point1D<T>::distance(const Point1D<T>& p1, const Point1D<T>& p2)
{
    return std::abs(p1.x - p2.x);
}

template <typename T>
inline constexpr bool Point1D<T>::is_coincident(const Point1D<T>& p1, const Point1D<T>& p2)
{
}