#include "Matrix4.h"

template <typename T>
constexpr Matrix4<T>::Matrix4() : m{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
{
}

template <typename T>
constexpr Matrix4<T>::Matrix4(T m11, T m12, T m13, T m14,
                             T m21, T m22, T m23, T m24,
                             T m31, T m32, T m33, T m34,
                             T m41, T m42, T m43, T m44)
    : m{{m11, m12, m13, m14},
        {m21, m22, m23, m24},
        {m31, m32, m33, m34},
        {m41, m42, m43, m44}}
{
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::zero()
{
    return Matrix4<T>(0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0);
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::ones()
{
    return Matrix4<T>(1, 1, 1, 1,
                     1, 1, 1, 1,
                     1, 1, 1, 1,
                     1, 1, 1, 1);
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::identity()
{
    return Matrix4<T>(1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1);
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::add(const Matrix4<T>& M1, const Matrix4<T>& M2)
{
    return Matrix4<T>(
        M1.m[0][0] + M2.m[0][0], M1.m[0][1] + M2.m[0][1], M1.m[0][2] + M2.m[0][2], M1.m[0][3] + M2.m[0][3],
        M1.m[1][0] + M2.m[1][0], M1.m[1][1] + M2.m[1][1], M1.m[1][2] + M2.m[1][2], M1.m[1][3] + M2.m[1][3],
        M1.m[2][0] + M2.m[2][0], M1.m[2][1] + M2.m[2][1], M1.m[2][2] + M2.m[2][2], M1.m[2][3] + M2.m[2][3],
        M1.m[3][0] + M2.m[3][0], M1.m[3][1] + M2.m[3][1], M1.m[3][2] + M2.m[3][2], M1.m[3][3] + M2.m[3][3]
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::sub(const Matrix4<T>& M1, const Matrix4<T>& M2)
{
    return Matrix4<T>(
        M1.m[0][0] - M2.m[0][0], M1.m[0][1] - M2.m[0][1], M1.m[0][2] - M2.m[0][2], M1.m[0][3] - M2.m[0][3],
        M1.m[1][0] - M2.m[1][0], M1.m[1][1] - M2.m[1][1], M1.m[1][2] - M2.m[1][2], M1.m[1][3] - M2.m[1][3],
        M1.m[2][0] - M2.m[2][0], M1.m[2][1] - M2.m[2][1], M1.m[2][2] - M2.m[2][2], M1.m[2][3] - M2.m[2][3],
        M1.m[3][0] - M2.m[3][0], M1.m[3][1] - M2.m[3][1], M1.m[3][2] - M2.m[3][2], M1.m[3][3] - M2.m[3][3]
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::mul(const Matrix4<T>& M1, const Matrix4<T>& M2)
{
    return Matrix4<T>(
        M1.m[0][0] * M2.m[0][0] + M1.m[0][1] * M2.m[1][0] + M1.m[0][2] * M2.m[2][0] + M1.m[0][3] * M2.m[3][0],
        M1.m[0][0] * M2.m[0][1] + M1.m[0][1] * M2.m[1][1] + M1.m[0][2] * M2.m[2][1] + M1.m[0][3] * M2.m[3][1],
        M1.m[0][0] * M2.m[0][2] + M1.m[0][1] * M2.m[1][2] + M1.m[0][2] * M2.m[2][2] + M1.m[0][3] * M2.m[3][2],
        M1.m[0][0] * M2.m[0][3] + M1.m[0][1] * M2.m[1][3] + M1.m[0][2] * M2.m[2][3] + M1.m[0][3] * M2.m[3][3],

        M1.m[1][0] * M2.m[0][0] + M1.m[1][1] * M2.m[1][0] + M1.m[1][2] * M2.m[2][0] + M1.m[1][3] * M2.m[3][0],
        M1.m[1][0] * M2.m[0][1] + M1.m[1][1] * M2.m[1][1] + M1.m[1][2] * M2.m[2][1] + M1.m[1][3] * M2.m[3][1],
        M1.m[1][0] * M2.m[0][2] + M1.m[1][1] * M2.m[1][2] + M1.m[1][2] * M2.m[2][2] + M1.m[1][3] * M2.m[3][2],
        M1.m[1][0] * M2.m[0][3] + M1.m[1][1] * M2.m[1][3] + M1.m[1][2] * M2.m[2][3] + M1.m[1][3] * M2.m[3][3],

        M1.m[2][0] * M2.m[0][0] + M1.m[2][1] * M2.m[1][0] + M1.m[2][2] * M2.m[2][0] + M1.m[2][3] * M2.m[3][0],
        M1.m[2][0] * M2.m[0][1] + M1.m[2][1] * M2.m[1][1] + M1.m[2][2] * M2.m[2][1] + M1.m[2][3] * M2.m[3][1],
        M1.m[2][0] * M2.m[0][2] + M1.m[2][1] * M2.m[1][2] + M1.m[2][2] * M2.m[2][2] + M1.m[2][3] * M2.m[3][2],
        M1.m[2][0] * M2.m[0][3] + M1.m[2][1] * M2.m[1][3] + M1.m[2][2] * M2.m[2][3] + M1.m[2][3] * M2.m[3][3],

        M1.m[3][0] * M2.m[0][0] + M1.m[3][1] * M2.m[1][0] + M1.m[3][2] * M2.m[2][0] + M1.m[3][3] * M2.m[3][0],
        M1.m[3][0] * M2.m[0][1] + M1.m[3][1] * M2.m[1][1] + M1.m[3][2] * M2.m[2][1] + M1.m[3][3] * M2.m[3][1],
        M1.m[3][0] * M2.m[0][2] + M1.m[3][1] * M2.m[1][2] + M1.m[3][2] * M2.m[2][2] + M1.m[3][3] * M2.m[3][2],
        M1.m[3][0] * M2.m[0][3] + M1.m[3][1] * M2.m[1][3] + M1.m[3][2] * M2.m[2][3] + M1.m[3][3] * M2.m[3][3]
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::add(const Matrix4<T>& M1, T val)
{
    return Matrix4<T>(
        M1.m[0][0] + val, M1.m[0][1] + val, M1.m[0][2] + val, M1.m[0][3] + val,
        M1.m[1][0] + val, M1.m[1][1] + val, M1.m[1][2] + val, M1.m[1][3] + val,
        M1.m[2][0] + val, M1.m[2][1] + val, M1.m[2][2] + val, M1.m[2][3] + val,
        M1.m[3][0] + val, M1.m[3][1] + val, M1.m[3][2] + val, M1.m[3][3] + val
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::add(T val, const Matrix4<T>& M1)
{
    return Matrix4<T>::add(M1, val);
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::sub(const Matrix4<T>& M1, T val)
{
    return Matrix4<T>(
        M1.m[0][0] - val, M1.m[0][1] - val, M1.m[0][2] - val, M1.m[0][3] - val,
        M1.m[1][0] - val, M1.m[1][1] - val, M1.m[1][2] - val, M1.m[1][3] - val,
        M1.m[2][0] - val, M1.m[2][1] - val, M1.m[2][2] - val, M1.m[2][3] - val,
        M1.m[3][0] - val, M1.m[3][1] - val, M1.m[3][2] - val, M1.m[3][3] - val
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::sub(T val, const Matrix4<T>& M1)
{
    return Matrix4<T>(
        val - M1.m[0][0], val - M1.m[0][1], val - M1.m[0][2], val - M1.m[0][3],
        val - M1.m[1][0], val - M1.m[1][1], val - M1.m[1][2], val - M1.m[1][3],
        val - M1.m[2][0], val - M1.m[2][1], val - M1.m[2][2], val - M1.m[2][3],
        val - M1.m[3][0], val - M1.m[3][1], val - M1.m[3][2], val - M1.m[3][3]
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::mul(const Matrix4<T>& M1, T val)
{
    return Matrix4<T>(
        M1.m[0][0] * val, M1.m[0][1] * val, M1.m[0][2] * val, M1.m[0][3] * val,
        M1.m[1][0] * val, M1.m[1][1] * val, M1.m[1][2] * val, M1.m[1][3] * val,
        M1.m[2][0] * val, M1.m[2][1] * val, M1.m[2][2] * val, M1.m[2][3] * val,
        M1.m[3][0] * val, M1.m[3][1] * val, M1.m[3][2] * val, M1.m[3][3] * val
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::mul(T val, const Matrix4<T>& M1)
{
    return Matrix4<T>::mul(M1, val);
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::div(const Matrix4<T>& M1, T val)
{
    return Matrix4<T>(
        M1.m[0][0] / val, M1.m[0][1] / val, M1.m[0][2] / val, M1.m[0][3] / val,
        M1.m[1][0] / val, M1.m[1][1] / val, M1.m[1][2] / val, M1.m[1][3] / val,
        M1.m[2][0] / val, M1.m[2][1] / val, M1.m[2][2] / val, M1.m[2][3] / val,
        M1.m[3][0] / val, M1.m[3][1] / val, M1.m[3][2] / val, M1.m[3][3] / val
    );
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::trans(const Matrix4<T>& M)
{
    return Matrix4<T>(
        M.m[0][0], M.m[1][0], M.m[2][0], M.m[3][0],
        M.m[0][1], M.m[1][1], M.m[2][1], M.m[3][1],
        M.m[0][2], M.m[1][2], M.m[2][2], M.m[3][2],
        M.m[0][3], M.m[1][3], M.m[2][3], M.m[3][3]
    );
}

template <typename T>
inline constexpr T Matrix4<T>::det(const Matrix4<T>& M)
{
    T m00 = M.m[0][0], m01 = M.m[0][1], m02 = M.m[0][2], m03 = M.m[0][3];
    T m10 = M.m[1][0], m11 = M.m[1][1], m12 = M.m[1][2], m13 = M.m[1][3];
    T m20 = M.m[2][0], m21 = M.m[2][1], m22 = M.m[2][2], m23 = M.m[2][3];
    T m30 = M.m[3][0], m31 = M.m[3][1], m32 = M.m[3][2], m33 = M.m[3][3];

    return m00 * (m11 * (m22 * m33 - m23 * m32) - m12 * (m21 * m33 - m23 * m31) + m13 * (m21 * m32 - m22 * m31)) -
           m01 * (m10 * (m22 * m33 - m23 * m32) - m12 * (m20 * m33 - m23 * m30) + m13 * (m20 * m32 - m22 * m30)) +
           m02 * (m10 * (m21 * m33 - m23 * m31) - m11 * (m20 * m33 - m23 * m30) + m13 * (m20 * m31 - m21 * m30)) -
           m03 * (m10 * (m21 * m32 - m22 * m31) - m11 * (m20 * m32 - m22 * m30) + m12 * (m20 * m31 - m21 * m30));
}

template <typename T>
inline constexpr T Matrix4<T>::trace(const Matrix4<T>& M)
{
    return M.m[0][0] + M.m[1][1] + M.m[2][2] + M.m[3][3];
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::minor(const Matrix4<T>& M)
{
    Matrix4<T> result;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            T det3x3 = 0;
            int r = 0;
            for(int k = 0; k < 4; k++) {
                if(k == i) continue;
                int c = 0;
                for(int l = 0; l < 4; l++) {
                    if(l == j) continue;
                    if(r == 0 && c == 0) det3x3 += M.m[k][l] * (M.m[(k+1)%4][(l+1)%4] * M.m[(k+2)%4][(l+2)%4] - M.m[(k+1)%4][(l+2)%4] * M.m[(k+2)%4][(l+1)%4]);
                    if(r == 0 && c == 1) det3x3 -= M.m[k][l] * (M.m[(k+1)%4][(l-1+4)%4] * M.m[(k+2)%4][(l+1)%4] - M.m[(k+1)%4][(l+1)%4] * M.m[(k+2)%4][(l-1+4)%4]);
                    if(r == 1 && c == 0) det3x3 += M.m[k][l] * (M.m[(k-1+4)%4][(l+1)%4] * M.m[(k+1)%4][(l+2)%4] - M.m[(k-1+4)%4][(l+2)%4] * M.m[(k+1)%4][(l+1)%4]);
                    c++;
                }
                r++;
            }
            result.m[i][j] = det3x3;
        }
    }
    return result;
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::cofactor(const Matrix4<T>& M)
{
    Matrix4<T> minors = minor(M);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if((i + j) % 2 == 1)
                minors.m[i][j] = -minors.m[i][j];
    return minors;
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::adj(const Matrix4<T>& M)
{
    return trans(cofactor(M));
}

template <typename T>
inline constexpr Matrix4<T> Matrix4<T>::inv(const Matrix4<T>& M)
{
    T determinant = det(M);
    Matrix4<T> adjugate = adj(M);
    return div(adjugate, determinant);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator+(const Matrix4<T>& other) const
{
    return add(*this, other);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator-(const Matrix4<T>& other) const
{
    return sub(*this, other);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator*(const Matrix4<T>& other) const
{
    return mul(*this, other);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator%(T scalar) const
{
    return Matrix4<T>(
        m[0][0] % scalar, m[0][1] % scalar, m[0][2] % scalar, m[0][3] % scalar,
        m[1][0] % scalar, m[1][1] % scalar, m[1][2] % scalar, m[1][3] % scalar,
        m[2][0] % scalar, m[2][1] % scalar, m[2][2] % scalar, m[2][3] % scalar,
        m[3][0] % scalar, m[3][1] % scalar, m[3][2] % scalar, m[3][3] % scalar
    );
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Matrix4<T> Matrix4<T>::operator-() const
{
    return Matrix4<T>(
        -m[0][0], -m[0][1], -m[0][2], -m[0][3],
        -m[1][0], -m[1][1], -m[1][2], -m[1][3],
        -m[2][0], -m[2][1], -m[2][2], -m[2][3],
        -m[3][0], -m[3][1], -m[3][2], -m[3][3]
    );
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator++()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ++m[i][j];
    return *this;
}

template <typename T>
Matrix4<T> Matrix4<T>::operator++(int)
{
    Matrix4<T> temp(*this);
    ++(*this);
    return temp;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator--()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            --m[i][j];
    return *this;
}

template <typename T>
Matrix4<T> Matrix4<T>::operator--(int)
{
    Matrix4<T> temp(*this);
    --(*this);
    return temp;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<T>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<T>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator*=(const Matrix4<T>& other)
{
    *this = *this * other;
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator/=(const Matrix4<T>& other)
{
    *this = *this * inv(other);
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator*=(T scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator/=(T scalar)
{
    *this = *this / scalar;
    return *this;
}

template <typename T>
Matrix4<T>& Matrix4<T>::operator%=(T scalar)
{
    *this = *this % scalar;
    return *this;
}

template <typename T>
constexpr bool Matrix4<T>::operator==(const Matrix4<T>& other) const
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(m[i][j] != other.m[i][j])
                return false;
    return true;
}

template <typename T>
constexpr bool Matrix4<T>::operator!=(const Matrix4<T>& other) const
{
    return !(*this == other);
}

template <typename T>
bool Matrix4<T>::isDiagonal() const
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(i != j && m[i][j] != 0)
                return false;
    return true;
}

template <typename T>
bool Matrix4<T>::isSingular() const
{
    return det(*this) == 0;
}

template <typename T>
bool Matrix4<T>::isIdentity() const
{
    return *this == identity();
}

template <typename T>
bool Matrix4<T>::isSymmetric() const
{
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            if(m[i][j] != m[j][i])
                return false;
    return true;
}
