#include "Point3D.h"

template <typename T>
constexpr Point3D<T>::Point3D() : x(0), y(0), z(0)
{
}

template <typename T>
constexpr Point3D<T>::Point3D(T x, T y, T z): x(x), y(y), z(z)
{
}