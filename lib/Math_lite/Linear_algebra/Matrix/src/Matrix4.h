#ifndef MATRIX4_H
#define MATRIX4_H

#include <cmath>

template <typename T>
class Matrix4
{
public:
    T m[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    constexpr Matrix4();
    constexpr Matrix4(T m11, T m12, T m13, T m14,
                     T m21, T m22, T m23, T m24,
                     T m31, T m32, T m33, T m34,
                     T m41, T m42, T m43, T m44);
    
    static inline constexpr Matrix4<T> zero();
    static inline constexpr Matrix4<T> ones();
    static inline constexpr Matrix4<T> identity();

    static inline constexpr Matrix4<T> add(const Matrix4<T>& M1, const Matrix4<T>& M2);
    static inline constexpr Matrix4<T> sub(const Matrix4<T>& M1, const Matrix4<T>& M2);
    static inline constexpr Matrix4<T> mul(const Matrix4<T>& M1, const Matrix4<T>& M2);
    static inline constexpr Matrix4<T> add(const Matrix4<T>& M1, T val);
    static inline constexpr Matrix4<T> add(T val, const Matrix4<T>& M1);
    static inline constexpr Matrix4<T> sub(const Matrix4<T>& M1, T val);
    static inline constexpr Matrix4<T> sub(T val, const Matrix4<T>& M1);
    static inline constexpr Matrix4<T> mul(const Matrix4<T>& M1, T val);
    static inline constexpr Matrix4<T> mul(T val, const Matrix4<T>& M1);
    static inline constexpr Matrix4<T> div(const Matrix4<T>& M1, T val);
    static inline constexpr Matrix4<T> trans(const Matrix4<T>& M);
    static inline constexpr T det(const Matrix4<T>& M);
    static inline constexpr T trace(const Matrix4<T>& M);
    static inline constexpr Matrix4<T> minor(const Matrix4<T>& M);
    static inline constexpr Matrix4<T> cofactor(const Matrix4<T>& M);
    static inline constexpr Matrix4<T> adj(const Matrix4<T>& M);
    static inline constexpr Matrix4<T> inv(const Matrix4<T>& M);

    constexpr Matrix4<T> operator+(const Matrix4<T>& other) const;
    constexpr Matrix4<T> operator-(const Matrix4<T>& other) const;
    constexpr Matrix4<T> operator*(const Matrix4<T>& other) const;
    constexpr Matrix4<T> operator*(T scalar) const;
    constexpr Matrix4<T> operator/(T scalar) const;
    constexpr Matrix4<T> operator%(T scalar) const;

    constexpr Matrix4<T> operator+() const;
    constexpr Matrix4<T> operator-() const;
    Matrix4<T>& operator++();
    Matrix4<T> operator++(int);
    Matrix4<T>& operator--();
    Matrix4<T> operator--(int);

    Matrix4<T>& operator+=(const Matrix4<T>& other);
    Matrix4<T>& operator-=(const Matrix4<T>& other);
    Matrix4<T>& operator*=(const Matrix4<T>& other);
    Matrix4<T>& operator/=(const Matrix4<T>& other);
    Matrix4<T>& operator*=(T scalar);
    Matrix4<T>& operator/=(T scalar);
    Matrix4<T>& operator%=(T scalar);

    constexpr bool operator==(const Matrix4<T>& other) const;
    constexpr bool operator!=(const Matrix4<T>& other) const;

    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;
};

#include "Matrix4.tpp"

#endif
