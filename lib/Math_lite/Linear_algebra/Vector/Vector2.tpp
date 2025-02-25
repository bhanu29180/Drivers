#include "Vector2.h"

template <typename T>
constexpr Vector2<T>::Vector2(): x(0), y(0)
{
}

template <typename T>
constexpr Vector2<T>::Vector2(T x, T y): x(x), y(y)
{
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::zero()
{
    return Vector2<T>(0, 0);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::ones()
{
    return Vector2<T>(1, 1);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::add(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return Vector2<T>(v1.x + v2.x, v1.y + v2.y);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::sub(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return Vector2<T>(v1.x - v2.x, v1.y - v2.y);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::mul(const Vector2<T>& v, T s)
{
    return Vector2<T>(v.x * s, v.y * s);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::mul(T s, const Vector2<T>& v)
{
    return Vector2<T>(v.x * s, v.y * s);
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::div(const Vector2<T>& v, T s)
{
    return Vector2<T>(v.x / s, v.y / s);
}

template <typename T>
inline constexpr T Vector2<T>::dot(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
inline constexpr T Vector2<T>::cross(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

template <typename T>
inline constexpr Vector2<T> Vector2<T>::normalize(const Vector2<T>& v)
{
    T mag = magnitude(v);
    return Vector2<T>(v.x / mag, v.y / mag);
}

template <typename T>
inline constexpr T Vector2<T>::magnitude(const Vector2<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
inline constexpr T Vector2<T>::length(const Vector2<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
inline constexpr T Vector2<T>::norm(const Vector2<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
inline constexpr T Vector2<T>::angle(const Vector2<T>& v)
{
    return std::atan2(v.y, v.x);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator-() const
{
    return Vector2<T>(-x, -y);
}

template <typename T>
Vector2<T>& Vector2<T>::operator++()
{
    ++x;
    ++y;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator++(int)
{
    Vector2<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Vector2<T>& Vector2<T>::operator--()
{
    --x;
    --y;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator--(int)
{
    Vector2<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const
{
    return Vector2<T>(x + other.x, y + other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const
{
    return Vector2<T>(x - other.x, y - other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator*(T scalar) const
{
    return Vector2<T>(x * scalar, y * scalar);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator/(T scalar) const
{
    return Vector2<T>(x / scalar, y / scalar);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator%(T scalar) const
{
    return Vector2(x%scalar, y%scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(T scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=(T scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator%=(T scalar)
{
    x %= scalar;
    y %= scalar;
    return *this;
}

template <typename T>
constexpr bool Vector2<T>::operator==(const Vector2<T>& other) const
{
    return (x == other.x) && (y == other.y);
}

template <typename T>
constexpr bool Vector2<T>::operator!=(const Vector2<T>& other) const
{
    return !(*this == other);
}
