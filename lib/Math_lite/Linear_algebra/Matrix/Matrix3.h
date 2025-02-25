#ifndef MATRIX3_H
#define MATRIX3_H

#include <cmath>

template <typename T>
class Matrix3
{
public:
    T m[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    constexpr Matrix3();
    constexpr Matrix3(T m11, T m12, T m13, T m21, T m22, T m23, T m31, T m32, T m33);
    
    // constexpr Matrix3(const Matrix3<T>& other);
    // constexpr Matrix3<T>& operator=(const Matrix3<T>& other);
    
    static inline constexpr Matrix3<T> zero();
    static inline constexpr Matrix3<T> ones();
    static inline constexpr Matrix3<T> identity();

    static inline constexpr Matrix3<T> add(const Matrix3<T>& M1, const Matrix3<T>& M2);
    static inline constexpr Matrix3<T> sub(const Matrix3<T>& M1, const Matrix3<T>& M2);
    static inline constexpr Matrix3<T> mul(const Matrix3<T>& M1, const Matrix3<T>& M2);
    static inline constexpr Matrix3<T> add(const Matrix3<T>& M1, T val);
    static inline constexpr Matrix3<T> add(T val, const Matrix3<T>& M1);
    static inline constexpr Matrix3<T> sub(const Matrix3<T>& M1, T val);
    static inline constexpr Matrix3<T> sub(T val, const Matrix3<T>& M1);
    static inline constexpr Matrix3<T> mul(const Matrix3<T>& M1, T val);
    static inline constexpr Matrix3<T> mul(T val, const Matrix3<T>& M1);
    static inline constexpr Matrix3<T> div(const Matrix3<T>& M1, T val);
    static inline constexpr Matrix3<T> trans(const Matrix3<T>& M);
    static inline constexpr T det(const Matrix3<T>& M);
    static inline constexpr T trace(const Matrix3<T>& M);
    static inline constexpr Matrix3<T> minor(const Matrix3<T>& M);
    static inline constexpr Matrix3<T> cofactor(const Matrix3<T>& M);
    static inline constexpr Matrix3<T> adj(const Matrix3<T>& M);
    static inline constexpr Matrix3<T> inv(const Matrix3<T>& M);

    constexpr Matrix3<T> operator+(const Matrix3<T>& other) const;
    constexpr Matrix3<T> operator-(const Matrix3<T>& other) const;
    constexpr Matrix3<T> operator*(const Matrix3<T>& other) const;
    constexpr Matrix3<T> operator*(T scalar) const;
    constexpr Matrix3<T> operator/(T scalar) const;
    constexpr Matrix3<T> operator%(T scalar) const;

    constexpr Matrix3<T> operator+() const;
    constexpr Matrix3<T> operator-() const;
    Matrix3<T>& operator++();
    Matrix3<T> operator++(int);
    Matrix3<T>& operator--();
    Matrix3<T> operator--(int);

    Matrix3<T>& operator+=(const Matrix3<T>& other);
    Matrix3<T>& operator-=(const Matrix3<T>& other);
    Matrix3<T>& operator*=(const Matrix3<T>& other);
    Matrix3<T>& operator/=(const Matrix3<T>& other);
    Matrix3<T>& operator*=(T scalar);
    Matrix3<T>& operator/=(T scalar);
    Matrix3<T>& operator%=(T scalar);

    constexpr bool operator==(const Matrix3<T>& other) const;
    constexpr bool operator!=(const Matrix3<T>& other) const;

    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;

    // T& operator()(int row, int col);
    // constexpr T operator()(int row, int col) const;
};

#include "Matrix3.tpp"

#endif
