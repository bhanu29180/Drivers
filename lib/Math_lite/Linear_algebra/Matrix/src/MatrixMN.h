#ifndef MATRIXMN_H
#define MATRIXMN_H

#include <cmath>
#include <array>
#include <stdexcept>

template <typename T, size_t M, size_t N>
class MatrixMN
{
public:
    T m[M][N] = {{0}};

    constexpr MatrixMN();
    constexpr MatrixMN(const T (&values)[M][N]);
    
    static inline constexpr MatrixMN<T,M,N> zero();
    static inline constexpr MatrixMN<T,M,N> ones();
    static inline constexpr MatrixMN<T,M,N> identity();

    static inline constexpr MatrixMN<T,M,N> add(const MatrixMN<T,M,N>& M1, const MatrixMN<T,M,N>& M2);
    static inline constexpr MatrixMN<T,M,N> sub(const MatrixMN<T,M,N>& M1, const MatrixMN<T,M,N>& M2);
    template <size_t P>
    static inline constexpr MatrixMN<T,M,P> mul(const MatrixMN<T,M,N>& M1, const MatrixMN<T,N,P>& M2);
    static inline constexpr MatrixMN<T,M,N> add(const MatrixMN<T,M,N>& M1, T val);
    static inline constexpr MatrixMN<T,M,N> add(T val, const MatrixMN<T,M,N>& M1);
    static inline constexpr MatrixMN<T,M,N> sub(const MatrixMN<T,M,N>& M1, T val);
    static inline constexpr MatrixMN<T,M,N> sub(T val, const MatrixMN<T,M,N>& M1);
    static inline constexpr MatrixMN<T,M,N> mul(const MatrixMN<T,M,N>& M1, T val);
    static inline constexpr MatrixMN<T,M,N> mul(T val, const MatrixMN<T,M,N>& M1);
    static inline constexpr MatrixMN<T,M,N> div(const MatrixMN<T,M,N>& M1, T val);
    static inline constexpr MatrixMN<T,M,N> trans(const MatrixMN<T,M,N>& M);
    static inline constexpr T det(const MatrixMN<T,M,N>& M);
    static inline constexpr T trace(const MatrixMN<T,M,N>& M);
    static inline constexpr MatrixMN<T,M,N> minor(const MatrixMN<T,M,N>& M);
    static inline constexpr MatrixMN<T,M,N> cofactor(const MatrixMN<T,M,N>& M);
    static inline constexpr MatrixMN<T,M,N> adj(const MatrixMN<T,M,N>& M);
    static inline constexpr MatrixMN<T,M,N> inv(const MatrixMN<T,M,N>& M);

    constexpr MatrixMN<T,M,N> operator+(const MatrixMN<T,M,N>& other) const;
    constexpr MatrixMN<T,M,N> operator-(const MatrixMN<T,M,N>& other) const;
    template <size_t P>
    constexpr MatrixMN<T,M,P> operator*(const MatrixMN<T,N,P>& other) const;
    constexpr MatrixMN<T,M,N> operator*(T scalar) const;
    constexpr MatrixMN<T,M,N> operator/(T scalar) const;
    constexpr MatrixMN<T,M,N> operator%(T scalar) const;

    constexpr MatrixMN<T,M,N> operator+() const;
    constexpr MatrixMN<T,M,N> operator-() const;
    MatrixMN<T,M,N>& operator++();
    MatrixMN<T,M,N> operator++(int);
    MatrixMN<T,M,N>& operator--();
    MatrixMN<T,M,N> operator--(int);

    MatrixMN<T,M,N>& operator+=(const MatrixMN<T,M,N>& other);
    MatrixMN<T,M,N>& operator-=(const MatrixMN<T,M,N>& other);
    MatrixMN<T,M,N>& operator*=(const MatrixMN<T,M,N>& other);
    MatrixMN<T,M,N>& operator/=(const MatrixMN<T,M,N>& other);
    MatrixMN<T,M,N>& operator*=(T scalar);
    MatrixMN<T,M,N>& operator/=(T scalar);
    MatrixMN<T,M,N>& operator%=(T scalar);

    constexpr bool operator==(const MatrixMN<T,M,N>& other) const;
    constexpr bool operator!=(const MatrixMN<T,M,N>& other) const;

    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;
};

#include "MatrixMN.tpp"

#endif
