#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

template <typename T>
class Vector2 
{
    public:
        T x;
        T y;

        // Constructors
        constexpr Vector2();
        constexpr Vector2(T x, T y);

        static constexpr Vector2<T> zero();
        static constexpr Vector2<T> ones();

        // Static member functions
        static constexpr Vector2<T> add(const Vector2<T>& v1, const Vector2<T>& v2);
        static constexpr Vector2<T> sub(const Vector2<T>& v1, const Vector2<T>& v2);
        static constexpr Vector2<T> mul(const Vector2<T>& v, T s);
        static constexpr Vector2<T> div(const Vector2<T>& v, T s);
        static constexpr Vector2<T> div(T s, const Vector2<T>& v);

        // Static member functions
        static constexpr T dot(const Vector2<T>& v1, const Vector2<T>& v2);
        static constexpr T cross(const Vector2<T>& v1, const Vector2<T>& v2);
        static constexpr Vector2<T> normalize(const Vector2<T>& v);
        static constexpr T magnitude(const Vector2<T>& v);
        static constexpr T length(const Vector2<T>& v);
        static constexpr T norm(const Vector2<T>& v);
        static constexpr T angle(const Vector2<T>& v);

        constexpr Vector2<T> operator+(const Vector2<T>& other) const;
        constexpr Vector2<T> operator-(const Vector2<T>& other) const;
        constexpr Vector2<T> operator*(T scalar) const;
        constexpr Vector2<T> operator/(T scalar) const;

        Vector2<T>& operator+=(const Vector2<T>& other);
        Vector2<T>& operator-=(const Vector2<T>& other);
        Vector2<T>& operator*=(T scalar);
        Vector2<T>& operator/=(T scalar);

        constexpr bool operator==(const Vector2<T>& other) const;
        constexpr bool operator!=(const Vector2<T>& other) const;
        constexpr bool operator<(const Vector2<T>& other) const;
        constexpr bool operator<=(const Vector2<T>& other) const;
        constexpr bool operator>(const Vector2<T>& other) const;
        constexpr bool operator>=(const Vector2<T>& other) const;
};

#endif