#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

template <typename T>
class Vector2
{
    public:
        Vector2();
        Vector2(T x=0, T y=0);
        Vector2<T> add(Vector2<T> v1, Vector2<T> v2);
        Vector2<T> sub(Vector2<T> v1, Vector2<T> v2);
        Vector2<T> mul(Vector2<T> v1, T s);
        Vector2<T> mul(T s, Vector2<T> v1);
        Vector2<T> div(Vector2<T> v1, T s);
        T normalize(Vector2<T> v1);
        T abs(Vector2<T> v1);
        T norm(Vector2<T> v1);
        T len(Vector2<T> v1);
        T angle(Vector2<T> v1);
        T dot(Vector2<T> v1, Vector2<T> v2);
        T cross(Vector2<T> v1, Vector2<T> v2);

        Vector2<T> operator+(Vector2<T> v1, Vector2<T> v2);
        Vector2<T> operator-(Vector2<T> v1, Vector2<T> v2);
        Vector2<T> operator-(Vector2<T> v1);
        Vector2<T> operator*(Vector2<T> v1, T s);
        Vector2<T> operator*(T s, Vector2<T> v1);
        Vector2<T> operator/(Vector2<T> v1, T s);

        boolean operator<(Vector2<T> v1, Vector2<T> v2);
        boolean operator>(Vector2<T> v1, Vector2<T> v2);
        boolean operator==(Vector2<T> v1, Vector2<T> v2);
        boolean operator<=(Vector2<T> v1, Vector2<T> v2);
        boolean operator>=(Vector2<T> v1, Vector2<T> v2);

    private:
        T x = 0;
        T y = 0;
};

#include "Vector2.tpp"

#endif