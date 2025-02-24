#include "Matrix3.h"

template <typename T>
constexpr Matrix3<T>::Matrix3() : m{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
{
}

template <typename T>
constexpr Matrix3<T>::Matrix3(T m11, T m12, T m13, T m21, T m22, T m23, T m31, T m32, T m33) 
    : m{{m11, m12, m13}, {m21, m22, m23}, {m31, m32, m33}}
{
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::zero()
{
    return Matrix3<T>(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::ones()
{
    return Matrix3<T>(1, 1, 1, 1, 1, 1, 1, 1, 1);
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::identity()
{
    return Matrix3<T>(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::add(const Matrix3<T>& M1, const Matrix3<T>& M2)
{
    return Matrix3<T>(
        M1.m[0][0] + M2.m[0][0], M1.m[0][1] + M2.m[0][1], M1.m[0][2] + M2.m[0][2],
        M1.m[1][0] + M2.m[1][0], M1.m[1][1] + M2.m[1][1], M1.m[1][2] + M2.m[1][2],
        M1.m[2][0] + M2.m[2][0], M1.m[2][1] + M2.m[2][1], M1.m[2][2] + M2.m[2][2]
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::sub(const Matrix3<T>& M1, const Matrix3<T>& M2)
{
    return Matrix3<T>(
        M1.m[0][0] - M2.m[0][0], M1.m[0][1] - M2.m[0][1], M1.m[0][2] - M2.m[0][2],
        M1.m[1][0] - M2.m[1][0], M1.m[1][1] - M2.m[1][1], M1.m[1][2] - M2.m[1][2],
        M1.m[2][0] - M2.m[2][0], M1.m[2][1] - M2.m[2][1], M1.m[2][2] - M2.m[2][2]
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::mul(const Matrix3<T>& M1, const Matrix3<T>& M2)
{
    return Matrix3<T>(
        M1.m[0][0] * M2.m[0][0] + M1.m[0][1] * M2.m[1][0] + M1.m[0][2] * M2.m[2][0],
        M1.m[0][0] * M2.m[0][1] + M1.m[0][1] * M2.m[1][1] + M1.m[0][2] * M2.m[2][1],
        M1.m[0][0] * M2.m[0][2] + M1.m[0][1] * M2.m[1][2] + M1.m[0][2] * M2.m[2][2],
        
        M1.m[1][0] * M2.m[0][0] + M1.m[1][1] * M2.m[1][0] + M1.m[1][2] * M2.m[2][0],
        M1.m[1][0] * M2.m[0][1] + M1.m[1][1] * M2.m[1][1] + M1.m[1][2] * M2.m[2][1],
        M1.m[1][0] * M2.m[0][2] + M1.m[1][1] * M2.m[1][2] + M1.m[1][2] * M2.m[2][2],
        
        M1.m[2][0] * M2.m[0][0] + M1.m[2][1] * M2.m[1][0] + M1.m[2][2] * M2.m[2][0],
        M1.m[2][0] * M2.m[0][1] + M1.m[2][1] * M2.m[1][1] + M1.m[2][2] * M2.m[2][1],
        M1.m[2][0] * M2.m[0][2] + M1.m[2][1] * M2.m[1][2] + M1.m[2][2] * M2.m[2][2]
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::add(const Matrix3<T>& M1, T val)
{
    return Matrix3<T>(
        M1.m[0][0] + val, M1.m[0][1] + val, M1.m[0][2] + val,
        M1.m[1][0] + val, M1.m[1][1] + val, M1.m[1][2] + val,
        M1.m[2][0] + val, M1.m[2][1] + val, M1.m[2][2] + val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::add(T val, const Matrix3<T>& M1)
{
    return Matrix3<T>(
        M1.m[0][0] + val, M1.m[0][1] + val, M1.m[0][2] + val,
        M1.m[1][0] + val, M1.m[1][1] + val, M1.m[1][2] + val,
        M1.m[2][0] + val, M1.m[2][1] + val, M1.m[2][2] + val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::sub(const Matrix3<T>& M1, T val)
{
    return Matrix3<T>(
        M1.m[0][0] - val, M1.m[0][1] - val, M1.m[0][2] - val,
        M1.m[1][0] - val, M1.m[1][1] - val, M1.m[1][2] - val,
        M1.m[2][0] - val, M1.m[2][1] - val, M1.m[2][2] - val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::sub(T val, const Matrix3<T>& M1)
{
    return Matrix3<T>(
        val - M1.m[0][0], val - M1.m[0][1], val - M1.m[0][2],
        val - M1.m[1][0], val - M1.m[1][1], val - M1.m[1][2],
        val - M1.m[2][0], val - M1.m[2][1], val - M1.m[2][2]
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::mul(const Matrix3<T>& M1, T val)
{
    return Matrix3<T>(
        M1.m[0][0] * val, M1.m[0][1] * val, M1.m[0][2] * val,
        M1.m[1][0] * val, M1.m[1][1] * val, M1.m[1][2] * val,
        M1.m[2][0] * val, M1.m[2][1] * val, M1.m[2][2] * val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::mul(T val, const Matrix3<T>& M1)
{
    return Matrix3<T>(
        M1.m[0][0] * val, M1.m[0][1] * val, M1.m[0][2] * val,
        M1.m[1][0] * val, M1.m[1][1] * val, M1.m[1][2] * val,
        M1.m[2][0] * val, M1.m[2][1] * val, M1.m[2][2] * val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::div(const Matrix3<T>& M1, T val)
{
    return Matrix3<T>(
        M1.m[0][0] / val, M1.m[0][1] / val, M1.m[0][2] / val,
        M1.m[1][0] / val, M1.m[1][1] / val, M1.m[1][2] / val,
        M1.m[2][0] / val, M1.m[2][1] / val, M1.m[2][2] / val
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::trans(const Matrix3<T>& M)
{
    return Matrix3<T>(
        M.m[0][0], M.m[1][0], M.m[2][0],
        M.m[0][1], M.m[1][1], M.m[2][1],
        M.m[0][2], M.m[1][2], M.m[2][2]
    );
}

template <typename T>
inline constexpr T Matrix3<T>::det(const Matrix3<T>& M)
{
    return M.m[0][0] * (M.m[1][1] * M.m[2][2] - M.m[1][2] * M.m[2][1]) -
           M.m[0][1] * (M.m[1][0] * M.m[2][2] - M.m[1][2] * M.m[2][0]) +
           M.m[0][2] * (M.m[1][0] * M.m[2][1] - M.m[1][1] * M.m[2][0]);
}

template <typename T>
inline constexpr T Matrix3<T>::trace(const Matrix3<T>& M)
{
    return M.m[0][0] + M.m[1][1] + M.m[2][2];
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::minor(const Matrix3<T>& M)
{
    return Matrix3<T>(
        M.m[1][1] * M.m[2][2] - M.m[1][2] * M.m[2][1],
        M.m[1][0] * M.m[2][2] - M.m[1][2] * M.m[2][0],
        M.m[1][0] * M.m[2][1] - M.m[1][1] * M.m[2][0],
        
        M.m[0][1] * M.m[2][2] - M.m[0][2] * M.m[2][1],
        M.m[0][0] * M.m[2][2] - M.m[0][2] * M.m[2][0],
        M.m[0][0] * M.m[2][1] - M.m[0][1] * M.m[2][0],
        
        M.m[0][1] * M.m[1][2] - M.m[0][2] * M.m[1][1],
        M.m[0][0] * M.m[1][2] - M.m[0][2] * M.m[1][0],
        M.m[0][0] * M.m[1][1] - M.m[0][1] * M.m[1][0]
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::cofactor(const Matrix3<T>& M)
{
    return Matrix3<T>(
         (M.m[1][1] * M.m[2][2] - M.m[1][2] * M.m[2][1]),
        -(M.m[1][0] * M.m[2][2] - M.m[1][2] * M.m[2][0]),
         (M.m[1][0] * M.m[2][1] - M.m[1][1] * M.m[2][0]),
        
        -(M.m[0][1] * M.m[2][2] - M.m[0][2] * M.m[2][1]),
         (M.m[0][0] * M.m[2][2] - M.m[0][2] * M.m[2][0]),
        -(M.m[0][0] * M.m[2][1] - M.m[0][1] * M.m[2][0]),
        
         (M.m[0][1] * M.m[1][2] - M.m[0][2] * M.m[1][1]),
        -(M.m[0][0] * M.m[1][2] - M.m[0][2] * M.m[1][0]),
         (M.m[0][0] * M.m[1][1] - M.m[0][1] * M.m[1][0])
    );
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::adj(const Matrix3<T>& M)
{
    return trans(cofactor(M));
}

template <typename T>
inline constexpr Matrix3<T> Matrix3<T>::inv(const Matrix3<T>& M)
{
    T determinant = det(M);
    Matrix3<T> adjugate = adj(M);
    return div(adjugate, determinant);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator+(const Matrix3<T>& other) const
{
    return add(*this, other);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator-(const Matrix3<T>& other) const
{
    return sub(*this, other);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator*(const Matrix3<T>& other) const
{
    return mul(*this, other);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator%(T scalar) const
{
    return Matrix3<T>(
        m[0][0] % scalar, m[0][1] % scalar, m[0][2] % scalar,
        m[1][0] % scalar, m[1][1] % scalar, m[1][2] % scalar,
        m[2][0] % scalar, m[2][1] % scalar, m[2][2] % scalar
    );
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Matrix3<T> Matrix3<T>::operator-() const
{
    return Matrix3<T>(
        -m[0][0], -m[0][1], -m[0][2],
        -m[1][0], -m[1][1], -m[1][2],
        -m[2][0], -m[2][1], -m[2][2]
    );
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator++()
{
    ++m[0][0]; ++m[0][1]; ++m[0][2];
    ++m[1][0]; ++m[1][1]; ++m[1][2];
    ++m[2][0]; ++m[2][1]; ++m[2][2];
    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator++(int)
{
    Matrix3<T> temp(*this);
    ++(*this);
    return temp;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator--()
{
    --m[0][0]; --m[0][1]; --m[0][2];
    --m[1][0]; --m[1][1]; --m[1][2];
    --m[2][0]; --m[2][1]; --m[2][2];
    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator--(int)
{
    Matrix3<T> temp(*this);
    --(*this);
    return temp;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& other)
{
    *this = *this * other;
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator/=(const Matrix3<T>& other)
{
    *this = *this * inv(other);
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator*=(T scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator/=(T scalar)
{
    *this = *this / scalar;
    return *this;
}

template <typename T>
Matrix3<T>& Matrix3<T>::operator%=(T scalar)
{
    *this = *this % scalar;
    return *this;
}

template <typename T>
constexpr bool Matrix3<T>::operator==(const Matrix3<T>& other) const
{
    return ((m[0][0] == other.m[0][0]) && (m[0][1] == other.m[0][1]) && (m[0][2] == other.m[0][2]) &&
            (m[1][0] == other.m[1][0]) && (m[1][1] == other.m[1][1]) && (m[1][2] == other.m[1][2]) &&
            (m[2][0] == other.m[2][0]) && (m[2][1] == other.m[2][1]) && (m[2][2] == other.m[2][2]));
}

template <typename T>
constexpr bool Matrix3<T>::operator!=(const Matrix3<T>& other) const
{
    return !(*this == other);
}

template <typename T>
bool Matrix3<T>::isDiagonal() const
{
    return ((m[0][1] == 0) && (m[0][2] == 0) &&
            (m[1][0] == 0) && (m[1][2] == 0) &&
            (m[2][0] == 0) && (m[2][1] == 0));
}

template <typename T>
bool Matrix3<T>::isSingular() const
{
    return (det(*this) == 0);
}

template <typename T>
bool Matrix3<T>::isIdentity() const
{
    return (*this == identity());
}

template <typename T>
bool Matrix3<T>::isSymmetric() const
{
    return ((m[0][1] == m[1][0]) &&
            (m[0][2] == m[2][0]) &&
            (m[1][2] == m[2][1]));
}
