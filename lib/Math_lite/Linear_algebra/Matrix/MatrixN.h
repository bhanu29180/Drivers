#ifndef MATRIXM_H
#define MATRIXM_H

#include <cmath>

template <typename T, size_t N>
class MatrixN {
public:
    T m[N][N] = {};  // Static 2D array initialized to zero

    constexpr MatrixN();
    constexpr MatrixN(const std::initializer_list<std::initializer_list<T>>& list);

    static inline constexpr MatrixN<T,N> zero();
    static inline constexpr MatrixN<T,N> ones();
    static inline constexpr MatrixN<T,N> identity();

    static inline constexpr MatrixN<T,N> add(const MatrixN<T,N>& M1, const MatrixN<T,N>& M2);
    static inline constexpr MatrixN<T,N> sub(const MatrixN<T,N>& M1, const MatrixN<T,N>& M2);
    static inline constexpr MatrixN<T,N> mul(const MatrixN<T,N>& M1, const MatrixN<T,N>& M2);
    static inline constexpr MatrixN<T,N> add(const MatrixN<T,N>& M1, T val);
    static inline constexpr MatrixN<T,N> add(T val, const MatrixN<T,N>& M1);
    static inline constexpr MatrixN<T,N> sub(const MatrixN<T,N>& M1, T val);
    static inline constexpr MatrixN<T,N> sub(T val, const MatrixN<T,N>& M1);
    static inline constexpr MatrixN<T,N> mul(const MatrixN<T,N>& M1, T val);
    static inline constexpr MatrixN<T,N> mul(T val, const MatrixN<T,N>& M1);
    static inline constexpr MatrixN<T,N> div(const MatrixN<T,N>& M1, T val);
    static inline constexpr MatrixN<T,N> trans(const MatrixN<T,N>& M);
    static inline constexpr T det(const MatrixN<T,N>& M);
    static inline constexpr T trace(const MatrixN<T,N>& M);
    static inline constexpr MatrixN<T,N> minor(const MatrixN<T,N>& M);
    static inline constexpr MatrixN<T,N> cofactor(const MatrixN<T,N>& M);
    static inline constexpr MatrixN<T,N> adj(const MatrixN<T,N>& M);
    static inline constexpr MatrixN<T,N> inv(const MatrixN<T,N>& M);

    constexpr MatrixN<T,N> operator+(const MatrixN<T,N>& other) const;
    constexpr MatrixN<T,N> operator-(const MatrixN<T,N>& other) const;
    constexpr MatrixN<T,N> operator*(const MatrixN<T,N>& other) const;
    constexpr MatrixN<T,N> operator*(T scalar) const;
    constexpr MatrixN<T,N> operator/(T scalar) const;
    constexpr MatrixN<T,N> operator%(T scalar) const;

    constexpr MatrixN<T,N> operator+() const;
    constexpr MatrixN<T,N> operator-() const;
    MatrixN<T,N>& operator++();
    MatrixN<T,N> operator++(int);
    MatrixN<T,N>& operator--();
    MatrixN<T,N> operator--(int);

    MatrixN<T,N>& operator+=(const MatrixN<T,N>& other);
    MatrixN<T,N>& operator-=(const MatrixN<T,N>& other);
    MatrixN<T,N>& operator*=(const MatrixN<T,N>& other);
    MatrixN<T,N>& operator/=(const MatrixN<T,N>& other);
    MatrixN<T,N>& operator*=(T scalar);
    MatrixN<T,N>& operator/=(T scalar);
    MatrixN<T,N>& operator%=(T scalar);

    constexpr bool operator==(const MatrixN<T,N>& other) const;
    constexpr bool operator!=(const MatrixN<T,N>& other) const;

    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;

    static constexpr size_t size() { return N; }
};

#include "MatrixN.tpp"

#endif
