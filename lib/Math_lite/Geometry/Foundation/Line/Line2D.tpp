#include "Line2D.h"

template <typename T>
constexpr Line2D<T>::Line2D() : p(0,0), v(1,0)
{
}

template <typename T>
constexpr Line2D<T>::Line2D(Point2D<T> p_, Vector2<T> v_) : p(p_), v(v_)
{
}

template <typename T>
T inline constexpr Line2D<T>::distance(const Line2D<T>& l, const Point2D<T>& p1)
{
}

template <typename T>
inline constexpr T Line2D<T>::angle(const Line2D<T>& l1, const Line2D<T>& l2)
{
}

template <typename T>
bool Line2D<T>::is_coincident(const Point2D<T>& p1) const
{
}

template <typename T>
bool Line2D<T>::is_coincident(const Line2D<T>& l2) const
{
}

template <typename T>
bool Line2D<T>::is_parallel(const Line2D<T>& l2) const
{
}

template <typename T>
bool Line2D<T>::is_intersecting(const Line2D<T>& l2) const
{
}