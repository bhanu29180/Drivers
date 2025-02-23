#ifndef LINE2D_H
#define LINE2D_H

#include "../Point/Point2D.h"
#include "../../../Linear_algebra/Vector/src/Vector2.h"

template <typename T>
class Line2D
{
public:
    Point2D<T> p(0, 0);
    Vector2<T> v(1, 0);

    constexpr Line2D();
    constexpr Line2D(Point2D<T> p_, Vector2<T> v_);

    static inline constexpr T distance(const Line2D<T>& l, const Point2D<T>& p1);
    bool is_coincident(const Point2D<T>& p1) const;
    bool is_coincident(const Line2D<T>& l2) const;
};

#include "Line2D.tpp"

#endif