#include "PointND.h"

template <typename T, std::size_t N>
constexpr PointND<T, N>::PointND()
{
    for (std::size_t i = 0; i < N; i++)
    {
        coordinates[i] = T(0);
    }
}

template <typename T, std::size_t N>
constexpr PointND<T, N>::PointND(const T* coordinates_)
{
    for (std::size_t i = 0; i < N; i++)
    {
        coordinates[i] = coordinates_[i];
    }
}