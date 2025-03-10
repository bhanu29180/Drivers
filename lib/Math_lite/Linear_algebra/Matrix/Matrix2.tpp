#include "Matrix2.h"

template <typename T>
constexpr Matrix2<T>::Matrix2() : m{{0, 0}, {0, 0}}
{
}

template <typename T>
constexpr Matrix2<T>::Matrix2(T m11, T m12, T m21, T m22) : m{{m11, m12}, {m21, m22}}
{
}

template <typename T>
constexpr Matrix2<T>::Matrix2(const Matrix2<T>& other) : m{{other.m[0][0], other.m[0][1]}, {other.m[1][0], other.m[1][1]}}
{
}

template <typename T>
constexpr Matrix2<T>& Matrix2<T>::operator=(const Matrix2<T>& other)
{
    if (this != &other)
    {
        m[0][0] = other.m[0][0];
        m[0][1] = other.m[0][1];
        m[1][0] = other.m[1][0];
        m[1][1] = other.m[1][1];
    }
    return *this;
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::zero()
{
    return Matrix2<T>(0, 0, 0, 0);
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::ones()
{
    return Matrix2<T>(1, 1, 1, 1);
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::identity()
{
    return Matrix2<T>(1, 0, 0, 1);
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::add(const Matrix2<T>& M1, const Matrix2<T>& M2)
{
    return Matrix2<T>(
        M1.m[0][0] + M2.m[0][0], M1.m[0][1] + M2.m[0][1],
        M1.m[1][0] + M2.m[1][0], M1.m[1][1] + M2.m[1][1]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::sub(const Matrix2<T>& M1, const Matrix2<T>& M2)
{
    return Matrix2<T>(
        M1.m[0][0] - M2.m[0][0], M1.m[0][1] - M2.m[0][1],
        M1.m[1][0] - M2.m[1][0], M1.m[1][1] - M2.m[1][1]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::mul(const Matrix2<T>& M1, const Matrix2<T>& M2)
{
    return Matrix2<T>(
        M1.m[0][0] * M2.m[0][0] + M1.m[0][1] * M2.m[1][0], M1.m[0][0] * M2.m[0][1] + M1.m[0][1] * M2.m[1][1],
        M1.m[1][0] * M2.m[0][0] + M1.m[1][1] * M2.m[1][0], M1.m[1][0] * M2.m[0][1] + M1.m[1][1] * M2.m[1][1]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::add(const Matrix2<T>& M1, T val)
{
    return Matrix2<T>(
        M1.m[0][0] + val, M1.m[0][1] + val,
        M1.m[1][0] + val, M1.m[1][1] + val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::add(T val, const Matrix2<T>& M1)
{
    return Matrix2<T>(
        M1.m[0][0] + val, M1.m[0][1] + val,
        M1.m[1][0] + val, M1.m[1][1] + val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::sub(const Matrix2<T>& M1, T val)
{
    return Matrix2<T>(
        M1.m[0][0] - val, M1.m[0][1] - val,
        M1.m[1][0] - val, M1.m[1][1] - val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::sub(T val, const Matrix2<T>& M1)
{
    return Matrix2<T>(
        val - M1.m[0][0], val - M1.m[0][1],
        val - M1.m[1][0], val - M1.m[1][1]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::mul(const Matrix2<T>& M1, T val)
{
    return Matrix2<T>(
        M1.m[0][0] * val, M1.m[0][1] * val,
        M1.m[1][0] * val, M1.m[1][1] * val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::mul(T val, const Matrix2<T>& M1)
{
    return Matrix2<T>(
        M1.m[0][0] * val, M1.m[0][1] * val,
        M1.m[1][0] * val, M1.m[1][1] * val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::div(const Matrix2<T>& M1, T val)
{
    return Matrix2<T>(
        M1.m[0][0] / val, M1.m[0][1] / val,
        M1.m[1][0] / val, M1.m[1][1] / val
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::trans(const Matrix2<T>& M)
{
    return Matrix2<T>(
        M.m[0][0], M.m[1][0],
        M.m[0][1], M.m[1][1]
    );
}

template <typename T>
inline constexpr T Matrix2<T>::det(const Matrix2<T>& M)
{
    return M.m[0][0] * M.m[1][1] - M.m[0][1] * M.m[1][0];
}

template <typename T>
inline constexpr T Matrix2<T>::trace(const Matrix2<T>& M)
{
    return M.m[0][0] + M.m[1][1];
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::minor(const Matrix2<T>& M)
{
    return Matrix2<T>(
        M.m[1][1], M.m[1][0],
        M.m[0][1], M.m[0][0]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::cofactor(const Matrix2<T>& M)
{
    return Matrix2<T>(
         M.m[1][1], -M.m[1][0],
        -M.m[0][1],  M.m[0][0]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::adj(const Matrix2<T>& M)
{
    return Matrix2<T>(
         M.m[1][1], -M.m[0][1],
        -M.m[1][0],  M.m[0][0]
    );
}

template <typename T>
inline constexpr Matrix2<T> Matrix2<T>::inv(const Matrix2<T>& M)
{
    T determinant = det(M);
    return Matrix2<T>(
         M.m[1][1]/determinant, -M.m[0][1]/determinant,
        -M.m[1][0]/determinant,  M.m[0][0]/determinant
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator+(const Matrix2<T>& other) const
{
    return Matrix2<T>(
        m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
        m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator-(const Matrix2<T>& other) const
{
    return Matrix2<T>(
        m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
        m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator*(const Matrix2<T>& other) const
{
    return mul(*this, other);
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator*(T scalar) const
{
    return Matrix2<T>(
        m[0][0] * scalar, m[0][1] * scalar,
        m[1][0] * scalar, m[1][1] * scalar
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator/(T scalar) const
{
    return Matrix2<T>(
        m[0][0] / scalar, m[0][1] / scalar,
        m[1][0] / scalar, m[1][1] / scalar
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator%(T scalar) const
{
    return Matrix2<T>(
        m[0][0] % scalar, m[0][1] % scalar,
        m[1][0] % scalar, m[1][1] % scalar
    );
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Matrix2<T> Matrix2<T>::operator-() const
{
    return Matrix2<T>(
        -m[0][0], -m[0][1],
        -m[1][0], -m[1][1]
    );
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator++()
{
    ++m[0][0]; ++m[0][1];
    ++m[1][0]; ++m[1][1];
    return *this;
}

template <typename T>
Matrix2<T> Matrix2<T>::operator++(int)
{
    Matrix2<T> temp(*this);
    ++(*this);
    return temp;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator--()
{
    --m[0][0]; --m[0][1];
    --m[1][0]; --m[1][1];
    return *this;
}

template <typename T>
Matrix2<T> Matrix2<T>::operator--(int)
{
    Matrix2<T> temp(*this);
    --(*this);
    return temp;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator+=(const Matrix2<T>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator-=(const Matrix2<T>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator*=(const Matrix2<T>& other)
{
    *this = *this * other;
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator/=(const Matrix2<T>& other)
{
    *this = *this * inv(other);
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator*=(T scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator/=(T scalar)
{
    *this = *this / scalar;
    return *this;
}

template <typename T>
Matrix2<T>& Matrix2<T>::operator%=(T scalar)
{
    *this = *this % scalar;
    return *this;
}

template <typename T>
constexpr bool Matrix2<T>::operator==(const Matrix2<T>& other) const
{
    return ((m[0][0] == other.m[0][0]) &&
            (m[0][1] == other.m[0][1]) &&
            (m[1][0] == other.m[1][0]) &&
            (m[1][1] == other.m[1][1]));
}

template <typename T>
constexpr bool Matrix2<T>::operator!=(const Matrix2<T>& other) const
{
    return !(*this == other);
}

template <typename T>
bool Matrix2<T>::isDiagonal() const
{
    return ((m[0][1] == 0) && (m[1][0] == 0));
}

template <typename T>
bool Matrix2<T>::isSingular() const
{
    return (det(*this) == 0);
}

template <typename T>
bool Matrix2<T>::isIdentity() const
{
    return (*this == identity());
}

template <typename T>
bool Matrix2<T>::isSymmetric() const
{
    return (m[0][1] == m[1][0]);
}

template <typename T>
T& Matrix2<T>::operator()(int row, int col)
{
    return m[row][col];
}

template <typename T>
constexpr T Matrix2<T>::operator()(int row, int col) const
{
    return m[row][col];
}
