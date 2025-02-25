#include "Vector4.h"

template <typename T>
constexpr Vector4<T>::Vector4(): x(0), y(0), z(0), w(0)
{
}

template <typename T>
constexpr Vector4<T>::Vector4(T x, T y, T z, T w): x(x), y(y), z(z), w(w)
{
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::zero()
{
    return Vector4<T>(0, 0, 0, 0);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::ones()
{
    return Vector4<T>(1, 1, 1, 1);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::add(const Vector4<T>& v1, const Vector4<T>& v2)
{
    return Vector4<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::sub(const Vector4<T>& v1, const Vector4<T>& v2)
{
    return Vector4<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::mul(const Vector4<T>& v, T s)
{
    return Vector4<T>(v.x * s, v.y * s, v.z * s, v.w * s);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::mul(T s, const Vector4<T>& v)
{
    return Vector4<T>(v.x * s, v.y * s, v.z * s, v.w * s);
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::div(const Vector4<T>& v, T s)
{
    return Vector4<T>(v.x / s, v.y / s, v.z / s, v.w / s);
}

template <typename T>
inline constexpr T Vector4<T>::dot(const Vector4<T>& v1, const Vector4<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

template <typename T>
inline constexpr Vector4<T> Vector4<T>::normalize(const Vector4<T>& v)
{
    T mag = magnitude(v);
    return Vector4<T>(v.x / mag, v.y / mag, v.z / mag, v.w / mag);
}

template <typename T>
inline constexpr T Vector4<T>::magnitude(const Vector4<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

template <typename T>
inline constexpr T Vector4<T>::length(const Vector4<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

template <typename T>
inline constexpr T Vector4<T>::norm(const Vector4<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator-() const
{
    return Vector4<T>(-x, -y, -z, -w);
}

template <typename T>
Vector4<T>& Vector4<T>::operator++()
{
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator++(int)
{
    Vector4<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Vector4<T>& Vector4<T>::operator--()
{
    --x;
    --y;
    --z;
    --w;
    return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator--(int)
{
    Vector4<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator+(const Vector4<T>& other) const
{
    return Vector4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator-(const Vector4<T>& other) const
{
    return Vector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator*(T scalar) const
{
    return Vector4<T>(x * scalar, y * scalar, z * scalar, w * scalar);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator/(T scalar) const
{
    return Vector4<T>(x / scalar, y / scalar, z / scalar, w / scalar);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator%(T scalar) const
{
    return Vector4(x%scalar, y%scalar, z%scalar, w%scalar);
}

template <typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator*=(T scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator/=(T scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator%=(T scalar)
{
    x %= scalar;
    y %= scalar;
    z %= scalar;
    w %= scalar;
    return *this;
}

template <typename T>
constexpr bool Vector4<T>::operator==(const Vector4<T>& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}

template <typename T>
constexpr bool Vector4<T>::operator!=(const Vector4<T>& other) const
{
    return !(*this == other);
}
