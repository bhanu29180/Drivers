#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

template <typename T>
class Vector2 
{
    public:
        T x = 0;
        T y = 0;

        // Constructors
        constexpr Vector2();
        constexpr Vector2(T x, T y);

        static inline constexpr Vector2<T> zero();
        static inline constexpr Vector2<T> ones();

        // Static member functions
        static inline constexpr Vector2<T> add(const Vector2<T>& v1, const Vector2<T>& v2);
        static inline constexpr Vector2<T> sub(const Vector2<T>& v1, const Vector2<T>& v2);
        static inline constexpr Vector2<T> mul(const Vector2<T>& v, T s);
        static inline constexpr Vector2<T> mul(T s, const Vector2<T>& v);
        static inline constexpr Vector2<T> div(const Vector2<T>& v, T s);

        static inline constexpr T dot(const Vector2<T>& v1, const Vector2<T>& v2);
        static inline constexpr T cross(const Vector2<T>& v1, const Vector2<T>& v2);
        static inline constexpr Vector2<T> normalize(const Vector2<T>& v);
        static inline constexpr T magnitude(const Vector2<T>& v);
        static inline constexpr T length(const Vector2<T>& v);
        static inline constexpr T norm(const Vector2<T>& v);
        static inline constexpr T angle(const Vector2<T>& v);

        constexpr Vector2<T> operator+() const;
        constexpr Vector2<T> operator-() const;
        Vector2<T>& operator++();
        Vector2<T> operator++(int);
        Vector2<T>& operator--();
        Vector2<T> operator--(int);

        constexpr Vector2<T> operator+(const Vector2<T>& other) const;
        constexpr Vector2<T> operator-(const Vector2<T>& other) const;
        constexpr Vector2<T> operator*(T scalar) const;
        constexpr Vector2<T> operator/(T scalar) const;
        constexpr Vector2<T> operator%(T scalar) const;

        Vector2<T>& operator+=(const Vector2<T>& other);
        Vector2<T>& operator-=(const Vector2<T>& other);
        Vector2<T>& operator*=(T scalar);
        Vector2<T>& operator/=(T scalar);
        Vector2<T>& operator%=(T scalar);

        constexpr bool operator==(const Vector2<T>& other) const;
        constexpr bool operator!=(const Vector2<T>& other) const;
};

#include "Vector2.tpp"

#endif
