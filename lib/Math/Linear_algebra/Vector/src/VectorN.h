#ifndef VECTORN_H
#define VECTORN_H

#include <cmath>
#include <cstddef>

template <typename T, std::size_t N>
class VectorN 
{
public:
    T elements[N];

    constexpr VectorN();
    constexpr VectorN(const T* elems);

    // Static member functions
    static inline constexpr VectorN<T, N> zero();
    static inline constexpr VectorN<T, N> ones();

    static inline constexpr VectorN<T, N> add(const VectorN<T, N>& v1, const VectorN<T, N>& v2);
    static inline constexpr VectorN<T, N> sub(const VectorN<T, N>& v1, const VectorN<T, N>& v2);
    static inline constexpr VectorN<T, N> mul(const VectorN<T, N>& v, T s);
    static inline constexpr VectorN<T, N> mul(T s, const VectorN<T, N>& v);
    static inline constexpr VectorN<T, N> div(const VectorN<T, N>& v, T s);
    static inline constexpr VectorN<T, N> div(T s, const VectorN<T, N>& v);

    static inline constexpr T dot(const VectorN<T, N>& v1, const VectorN<T, N>& v2);
    // Note: The cross product is not generally defined for N dimensions.
    static inline constexpr VectorN<T, N> normalize(const VectorN<T, N>& v);
    static inline constexpr T magnitude(const VectorN<T, N>& v);
    static inline constexpr T length(const VectorN<T, N>& v);
    static inline constexpr T norm(const VectorN<T, N>& v);
    // Angle is ambiguous in N dimensions and is therefore omitted.

    // Unary operators
    constexpr VectorN<T, N> operator+() const;
    constexpr VectorN<T, N> operator-() const;
    VectorN<T, N>& operator++();
    VectorN<T, N> operator++(int);
    VectorN<T, N>& operator--();
    VectorN<T, N> operator--(int);

    // Binary arithmetic operators
    constexpr VectorN<T, N> operator+(const VectorN<T, N>& other) const;
    constexpr VectorN<T, N> operator-(const VectorN<T, N>& other) const;
    constexpr VectorN<T, N> operator*(T scalar) const;
    constexpr VectorN<T, N> operator/(T scalar) const;
    constexpr VectorN<T, N> operator%(T scalar) const;

    VectorN<T, N>& operator+=(const VectorN<T, N>& other);
    VectorN<T, N>& operator-=(const VectorN<T, N>& other);
    VectorN<T, N>& operator*=(T scalar);
    VectorN<T, N>& operator/=(T scalar);
    VectorN<T, N>& operator%=(T scalar);

    // Comparison operators
    constexpr bool operator==(const VectorN<T, N>& other) const;
    constexpr bool operator!=(const VectorN<T, N>& other) const;
    constexpr bool operator<(const VectorN<T, N>& other) const;
    constexpr bool operator<=(const VectorN<T, N>& other) const;
    constexpr bool operator>(const VectorN<T, N>& other) const;
    constexpr bool operator>=(const VectorN<T, N>& other) const;

    // Logical operators
    constexpr bool operator!() const;
    constexpr bool operator&&(const VectorN<T, N>& other) const;
    constexpr bool operator||(const VectorN<T, N>& other) const;
};

#endif // VECTORN_H