#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>

template <typename T>
class Quaternion
{
    public:
        T q0 = 0;
        T q1 = 0;
        T q2 = 0;
        T q3 = 0;

        // Constructors
        constexpr Quaternion();
        constexpr Quaternion(T q0, T q1, T q2, T q3);

        static inline constexpr Quaternion<T> zero();
        static inline constexpr Quaternion<T> ones();
        static inline constexpr Quaternion<T> identity();

        // Static member functions
        static inline constexpr Quaternion<T> add(const Quaternion<T>& q_1, const Quaternion<T>& q_2);
        static inline constexpr Quaternion<T> sub(const Quaternion<T>& q_1, const Quaternion<T>& q_2);
        static inline constexpr Quaternion<T> mul(const Quaternion<T>& q_1, const Quaternion<T>& q_2);
        static inline constexpr Quaternion<T> mul(const Quaternion<T>& q, T s);
        static inline constexpr Quaternion<T> mul(T s, const Quaternion<T>& q);
        static inline constexpr Quaternion<T> div(const Quaternion<T>& q, T s);

        static inline constexpr Quaternion<T> conj(const Quaternion<T>& q);
        static inline constexpr Quaternion<T> normalize(const Quaternion<T>& q);
        static inline constexpr T magnitude(const Quaternion<T>& q);
        static inline constexpr T length(const Quaternion<T>& q);
        static inline constexpr T norm(const Quaternion<T>& q);
        static inline constexpr Quaternion<T> inv(const Quaternion<T>& q);
        static inline constexpr Quaternion<T> log_e(const Quaternion<T>& q);
        static inline constexpr Quaternion<T> exp(const Quaternion<T>& q);
        static inline constexpr Quaternion<T> pow(const Quaternion<T>& q, T r);
        static inline constexpr Quaternion<T> LERP(const Quaternion<T>& q_1, const Quaternion<T>& q_2, T tau);
        static inline constexpr Quaternion<T> SLERP(const Quaternion<T>& q_1, const Quaternion<T>& q_2, T tau);

        constexpr Quaternion<T> operator+() const;
        constexpr Quaternion<T> operator-() const;
        Quaternion<T>& operator++();
        Quaternion<T> operator++(int);
        Quaternion<T>& operator--();
        Quaternion<T> operator--(int);

        constexpr Quaternion<T> operator+(const Quaternion<T>& other) const;
        constexpr Quaternion<T> operator-(const Quaternion<T>& other) const;
        constexpr Quaternion<T> operator*(T scalar) const;
        constexpr Quaternion<T> operator/(T scalar) const;
        constexpr Quaternion<T> operator%(T scalar) const;

        Quaternion<T>& operator+=(const Quaternion<T>& other);
        Quaternion<T>& operator-=(const Quaternion<T>& other);
        Quaternion<T>& operator*=(const Quaternion<T>& other);
        Quaternion<T>& operator*=(T scalar);
        Quaternion<T>& operator/=(T scalar);
        Quaternion<T>& operator%=(T scalar);

        constexpr bool operator==(const Quaternion<T>& other) const;
        constexpr bool operator!=(const Quaternion<T>& other) const;
};

#include "Quaternion.tpp"

#endif