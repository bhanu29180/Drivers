#ifndef VECTOR4_H
#define VECTOR4_H

#include <cmath>

template <typename T>
class Vector4
{
    public:
        T x = 0;
        T y = 0;
        T z = 0;
        T w = 0;

        // Constructors
        constexpr Vector4();
        constexpr Vector4(T x, T y, T z, T w);

        static inline constexpr Vector4<T> zero();
        static inline constexpr Vector4<T> ones();

        // Static member functions
        static inline constexpr Vector4<T> add(const Vector4<T>& v1, const Vector4<T>& v2);
        static inline constexpr Vector4<T> sub(const Vector4<T>& v1, const Vector4<T>& v2);
        static inline constexpr Vector4<T> mul(const Vector4<T>& v, T s);
        static inline constexpr Vector4<T> mul(T s, const Vector4<T>& v);
        static inline constexpr Vector4<T> div(const Vector4<T>& v, T s);

        static inline constexpr T dot(const Vector4<T>& v1, const Vector4<T>& v2);
        static inline constexpr Vector4<T> normalize(const Vector4<T>& v);
        static inline constexpr T magnitude(const Vector4<T>& v);
        static inline constexpr T length(const Vector4<T>& v);
        static inline constexpr T norm(const Vector4<T>& v);

        constexpr Vector4<T> operator+() const;
        constexpr Vector4<T> operator-() const;
        Vector4<T>& operator++();
        Vector4<T> operator++(int);
        Vector4<T>& operator--();
        Vector4<T> operator--(int);

        constexpr Vector4<T> operator+(const Vector4<T>& other) const;
        constexpr Vector4<T> operator-(const Vector4<T>& other) const;
        constexpr Vector4<T> operator*(T scalar) const;
        constexpr Vector4<T> operator/(T scalar) const;
        constexpr Vector4<T> operator%(T scalar) const;

        Vector4<T>& operator+=(const Vector4<T>& other);
        Vector4<T>& operator-=(const Vector4<T>& other);
        Vector4<T>& operator*=(T scalar);
        Vector4<T>& operator/=(T scalar);
        Vector4<T>& operator%=(T scalar);

        constexpr bool operator==(const Vector4<T>& other) const;
        constexpr bool operator!=(const Vector4<T>& other) const;
};

#include "Vector4.tpp"

#endif
