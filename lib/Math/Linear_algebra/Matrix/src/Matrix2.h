#ifndef MATRIX2_H
#define MATRIX2_H

template <typename T>
class Matrix2
{
public:
    constexpr Matrix2();
    constexpr Matrix2(T m11, T m12, T m21, T m22);
    Matrix2<T>(const Matrix2<T>& other);
    Matrix2<T>& operator=(const Matrix2& other);
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
    static inline constexpr Matrix2<T> transpose(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> det(const Matrix2<T>& M);
    static inline constexpr Matrix2<T> trace(const Matrix2<T>& M);
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
    Matrix2<T>& operator*=(T scalar);
    Matrix2<T>& operator/=(T scalar);
    Matrix2<T>& operator%=(T scalar);

    T& operator()(int row, int col); // Element access (modifiable)
    T operator()(int row, int col) const; // Element access (read-only)
    
    constexpr bool operator==(const Matrix2<T>& other) const;
    constexpr bool operator!=(const Matrix2<T>& other) const;

    bool isDiagonal(const Matrix2<T>& M) const;
    bool isSingular(const Matrix2<T>& M) const;
    bool isIdentity(const Matrix2<T>& M) const;
    bool isSymmetric(const Matrix2<T>& M) const;
};

#include "Matrix2.tpp"

#endif