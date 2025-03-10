#ifndef MATRIX2_H
#define MATRIX2_H

#include <cmath>

template <typename T>
class Matrix2
{
public:
    T m[2][2] = {{0, 0}, {0, 0}};

    constexpr Matrix2();
    constexpr Matrix2(T m11, T m12, T m21, T m22);
    
    constexpr Matrix2(const Matrix2<T>& other);
    constexpr Matrix2<T>& operator=(const Matrix2<T>& other);
    
    static inline constexpr Matrix2<T> zero();
    static inline constexpr Matrix2<T> ones();
    static inline constexpr Matrix2<T> identity();

    static inline constexpr Matrix2<T> add(const Matrix2<T>& M1, const Matrix2<T>& M2);
    static inline constexpr Matrix2<T> sub(const Matrix2<T>& M1, const Matrix2<T>& M2);
    static inline constexpr Matrix2<T> mul(const Matrix2<T>& M1, const Matrix2<T>& M2);
    static inline constexpr Matrix2<T> add(const Matrix2<T>& M1, T val);
    static inline constexpr Matrix2<T> add(T val, const Matrix2<T>& M1);
    static inline constexpr Matrix2<T> sub(const Matrix2<T>& M1, T val);
    static inline constexpr Matrix2<T> sub(T val, const Matrix2<T>& M1);
    static inline constexpr Matrix2<T> mul(const Matrix2<T>& M1, T val);
    static inline constexpr Matrix2<T> mul(T val, const Matrix2<T>& M1);
    static inline constexpr Matrix2<T> div(const Matrix2<T>& M1, T val);
    static inline constexpr Matrix2<T> trans(const Matrix2<T>& M);
    static inline constexpr T det(const Matrix2<T>& M);
    static inline constexpr T trace(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> minor(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> cofactor(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> adj(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> inv(const Matrix2<T>& M);

    constexpr Matrix2<T> operator+(const Matrix2<T>& other) const;
    constexpr Matrix2<T> operator-(const Matrix2<T>& other) const;
    constexpr Matrix2<T> operator*(const Matrix2<T>& other) const;
    constexpr Matrix2<T> operator*(T scalar) const;
    constexpr Matrix2<T> operator/(T scalar) const;
    constexpr Matrix2<T> operator%(T scalar) const;

    constexpr Matrix2<T> operator+() const;
    constexpr Matrix2<T> operator-() const;
    Matrix2<T>& operator++();
    Matrix2<T> operator++(int);
    Matrix2<T>& operator--();
    Matrix2<T> operator--(int);

    Matrix2<T>& operator+=(const Matrix2<T>& other);
    Matrix2<T>& operator-=(const Matrix2<T>& other);
    Matrix2<T>& operator*=(const Matrix2<T>& other);
    Matrix2<T>& operator/=(const Matrix2<T>& other);
    Matrix2<T>& operator*=(T scalar);
    Matrix2<T>& operator/=(T scalar);
    Matrix2<T>& operator%=(T scalar);

    constexpr bool operator==(const Matrix2<T>& other) const;
    constexpr bool operator!=(const Matrix2<T>& other) const;

    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;

    T& operator()(int row, int col);
    constexpr T operator()(int row, int col) const;
};

#include "Matrix2.tpp"

#endif
