#include "Vector2.h"

template <typename T>
Vector2<T>::Vector2()
{
}

template <typename T>
Vector2<T>::Vector2(T x_=0, T y_=0)
{
    x = x_;
    y = y_;
}

template <typename T>
Vector2<T> Vector2<T>::add(Vector2<T> v1, Vector2<T> v2)
{
    return {v1.x+v2.x, v1.y+v2.y};
}

template <typename T>
Vector2<T> Vector2<T>::sub(Vector2<T> v1, Vector2<T> v2)
{
    return {v1.x-v2.x, v1.y-v2.y};
}

template <typename T>
Vector2<T> Vector2<T>::mul(Vector2<T> v1, T s)
{
    return {s*v1.x, s*v1.y};
}

template <typename T>
Vector2<T> Vector2<T>::mul(T s, Vector2<T> v2)
{
    return {s*v1.x, s*v1.y};
}

template <typename T>
Vector2<T> Vector2<T>::div(Vector2<T> v1, T s)
{
    return {v1.x/s, v1.y/s};
}

template <typename T>
Vector2<T> Vector2<T>::normalize(Vector2<T> v1)
{
    T norm_v1 = sqrt(v1.x*v1.x + v1.y*v1.y);
    return {v1.x/norm_v1, v1.y/norm_v1};
}

template <typename T>
T Vector2<T>::norm(Vector2<T> v1)
{
    return sqrt(v1.x*v1.x + v1.y*v1.y);
}

template <typename T>
T Vector2<T>::len(Vector2<T> v1)
{
    return sqrt(v1.x*v1.x + v1.y*v1.y);
}

template <typename T>
T Vector2<T>::angle(Vector2<T> v1)
{
    return atan2(v1.y, v1.x);
}

template <typename T>
T Vector2<T>::dot(Vector2<T> v1, Vector2<T> v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

template <typename T>
T Vector2<T>::cross(Vector2<T> v1, Vector2<T> v2)
{
    return v1.x*v2.y - v1.y*v2.x;
}