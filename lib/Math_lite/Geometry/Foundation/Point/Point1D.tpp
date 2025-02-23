#include "Point1D.h"

template <typename T>
constexpr Point1D<T>::Point1D() : x(0)
{
}

template <typename T>
constexpr Point1D<T>::Point1D(T x): x(x)
{
}