#include "Vector3.h"

template <typename T>
constexpr Vector3<T>::Vector3(): x(0), y(0), z(0)
{
}

template <typename T>
constexpr Vector3<T>::Vector3(T x, T y, T z): x(x), y(y), z(z)
{
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::zero()
{
    return Vector3<T>(0, 0, 0);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::ones()
{
    return Vector3<T>(1, 1, 1);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::add(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::sub(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::mul(const Vector3<T>& v, T s)
{
    return Vector3<T>(v.x * s, v.y * s, v.z * s);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::mul(T s, const Vector3<T>& v)
{
    return Vector3<T>(v.x * s, v.y * s, v.z * s);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::div(const Vector3<T>& v, T s)
{
    return Vector3<T>(v.x / s, v.y / s, v.z / s);
}

template <typename T>
inline constexpr T Vector3<T>::dot(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::cross(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::normalize(const Vector3<T>& v)
{
    T mag = magnitude(v);
    return Vector3<T>(v.x / mag, v.y / mag, v.z / mag);
}

template <typename T>
inline constexpr T Vector3<T>::magnitude(const Vector3<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
inline constexpr T Vector3<T>::length(const Vector3<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
inline constexpr T Vector3<T>::norm(const Vector3<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
inline constexpr Vector3<T> Vector3<T>::angle(const Vector3<T>& v)
{
    T L = magnitude(v);
    return Vector3<T> (std::acos(v.x/L), std::acos(v.y/L), std::acos(v.z/L));
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z);
}

template <typename T>
Vector3<T>& Vector3<T>::operator++()
{
    ++x;
    ++y;
    ++z;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator++(int)
{
    Vector3<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Vector3<T>& Vector3<T>::operator--()
{
    --x;
    --y;
    --z;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator--(int)
{
    Vector3<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const
{
    return Vector3<T>(x + other.x, y + other.y, z + other.z);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const
{
    return Vector3<T>(x - other.x, y - other.y, z - other.z);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator*(T scalar) const
{
    return Vector3<T>(x * scalar, y * scalar, z * scalar);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator/(T scalar) const
{
    return Vector3<T>(x / scalar, y / scalar, z / scalar);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator%(T scalar) const
{
    return Vector3(x%scalar, y%scalar, z%scalar);
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(T scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator/=(T scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator%=(T scalar)
{
    x %= scalar;
    y %= scalar;
    z %= scalar;
    return *this;
}

template <typename T>
constexpr bool Vector3<T>::operator==(const Vector3<T>& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

template <typename T>
constexpr bool Vector3<T>::operator!=(const Vector3<T>& other) const
{
    return !(*this == other);
}
