#include "MatrixMN.h"

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N>::MatrixMN()
{
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            m[i][j] = T(0);
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N>::MatrixMN(const T (&values)[M][N])
{
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            m[i][j] = values[i][j];
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::zero()
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = T(0);
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::ones()
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = T(1);
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::identity()
{
    static_assert(M == N, "Identity matrix is only defined for square matrices");
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = (i == j) ? T(1) : T(0);
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::add(const MatrixMN<T,M,N>& M1, const MatrixMN<T,M,N>& M2)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] + M2.m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::sub(const MatrixMN<T,M,N>& M1, const MatrixMN<T,M,N>& M2)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] - M2.m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
template <size_t P>
inline constexpr MatrixMN<T,M,P> MatrixMN<T,M,N>::mul(const MatrixMN<T,M,N>& M1, const MatrixMN<T,N,P>& M2)
{
    MatrixMN<T,M,P> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < P; ++j) {
            result.m[i][j] = T(0);
            for(size_t k = 0; k < N; ++k)
                result.m[i][j] += M1.m[i][k] * M2.m[k][j];
        }
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::add(const MatrixMN<T,M,N>& M1, T val)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] + val;
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::add(T val, const MatrixMN<T,M,N>& M1)
{
    return add(M1, val);
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::sub(const MatrixMN<T,M,N>& M1, T val)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] - val;
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::sub(T val, const MatrixMN<T,M,N>& M1)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = val - M1.m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::mul(const MatrixMN<T,M,N>& M1, T val)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] * val;
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::mul(T val, const MatrixMN<T,M,N>& M1)
{
    return mul(M1, val);
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::div(const MatrixMN<T,M,N>& M1, T val)
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] / val;
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::trans(const MatrixMN<T,M,N>& M)
{
    MatrixMN<T,N,M> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[j][i] = M.m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr T MatrixMN<T,M,N>::det(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Determinant is only defined for square matrices");
    if constexpr (M == 1) {
        return M.m[0][0];
    }
    else {
        T result = T(0);
        int sign = 1;
        for(size_t j = 0; j < N; ++j) {
            if(M.m[0][j] != T(0)) {
                MatrixMN<T,M-1,N-1> submatrix;
                for(size_t row = 1; row < M; ++row)
                    for(size_t col = 0, subcol = 0; col < N; ++col)
                        if(col != j)
                            submatrix.m[row-1][subcol++] = M.m[row][col];
                result += sign * M.m[0][j] * det(submatrix);
            }
            sign = -sign;
        }
        return result;
    }
}

template <typename T, size_t M, size_t N>
inline constexpr T MatrixMN<T,M,N>::trace(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Trace is only defined for square matrices");
    T result = T(0);
    for(size_t i = 0; i < M; ++i)
        result += M.m[i][i];
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::minor(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Minor is only defined for square matrices");
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j) {
            MatrixMN<T,M-1,N-1> submatrix;
            for(size_t row = 0, subrow = 0; row < M; ++row) {
                if(row != i) {
                    for(size_t col = 0, subcol = 0; col < N; ++col)
                        if(col != j)
                            submatrix.m[subrow][subcol++] = M.m[row][col];
                    ++subrow;
                }
            }
            result.m[i][j] = det(submatrix);
        }
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::cofactor(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Cofactor is only defined for square matrices");
    MatrixMN<T,M,N> result = minor(M);
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            if((i + j) % 2 == 1)
                result.m[i][j] = -result.m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::adj(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Adjugate is only defined for square matrices");
    return trans(cofactor(M));
}

template <typename T, size_t M, size_t N>
inline constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::inv(const MatrixMN<T,M,N>& M)
{
    static_assert(M == N, "Inverse is only defined for square matrices");
    T determinant = det(M);
    if(determinant == T(0))
        throw std::runtime_error("Matrix is singular");
    return div(adj(M), determinant);
}

// Operator implementations
template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator+(const MatrixMN<T,M,N>& other) const
{
    return add(*this, other);
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator-(const MatrixMN<T,M,N>& other) const
{
    return sub(*this, other);
}

template <typename T, size_t M, size_t N>
template <size_t P>
constexpr MatrixMN<T,M,P> MatrixMN<T,M,N>::operator*(const MatrixMN<T,N,P>& other) const
{
    return mul(*this, other);
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator%(T scalar) const
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = m[i][j] % scalar;
    return result;
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator+() const
{
    return *this;
}

template <typename T, size_t M, size_t N>
constexpr MatrixMN<T,M,N> MatrixMN<T,M,N>::operator-() const
{
    MatrixMN<T,M,N> result;
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            result.m[i][j] = -m[i][j];
    return result;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator++()
{
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            ++m[i][j];
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N> MatrixMN<T,M,N>::operator++(int)
{
    MatrixMN<T,M,N> temp(*this);
    ++(*this);
    return temp;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator--()
{
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            --m[i][j];
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N> MatrixMN<T,M,N>::operator--(int)
{
    MatrixMN<T,M,N> temp(*this);
    --(*this);
    return temp;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator+=(const MatrixMN<T,M,N>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator-=(const MatrixMN<T,M,N>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator*=(const MatrixMN<T,M,N>& other)
{
    static_assert(M == N, "Matrix multiplication assignment requires square matrices");
    *this = *this * other;
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator/=(const MatrixMN<T,M,N>& other)
{
    static_assert(M == N, "Matrix division assignment requires square matrices");
    *this = *this * inv(other);
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator*=(T scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator/=(T scalar)
{
    *this = *this / scalar;
    return *this;
}

template <typename T, size_t M, size_t N>
MatrixMN<T,M,N>& MatrixMN<T,M,N>::operator%=(T scalar)
{
    *this = *this % scalar;
    return *this;
}

template <typename T, size_t M, size_t N>
constexpr bool MatrixMN<T,M,N>::operator==(const MatrixMN<T,M,N>& other) const
{
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            if(m[i][j] != other.m[i][j])
                return false;
    return true;
}

template <typename T, size_t M, size_t N>
constexpr bool MatrixMN<T,M,N>::operator!=(const MatrixMN<T,M,N>& other) const
{
    return !(*this == other);
}

template <typename T, size_t M, size_t N>
bool MatrixMN<T,M,N>::isDiagonal() const
{
    static_assert(M == N, "Diagonal property is only defined for square matrices");
    for(size_t i = 0; i < M; ++i)
        for(size_t j = 0; j < N; ++j)
            if(i != j && m[i][j] != T(0))
                return false;
    return true;
}

template <typename T, size_t M, size_t N>
bool MatrixMN<T,M,N>::isSingular() const
{
    static_assert(M == N, "Singular property is only defined for square matrices");
    return det(*this) == T(0);
}

template <typename T, size_t M, size_t N>
bool MatrixMN<T,M,N>::isIdentity() const
{
    static_assert(M == N, "Identity property is only defined for square matrices");
    return *this == identity();
}

template <typename T, size_t M, size_t N>
bool MatrixMN<T,M,N>::isSymmetric() const
{
    static_assert(M == N, "Symmetric property is only defined for square matrices");
    for(size_t i = 0; i < M; ++i)
        for(size_t j = i + 1; j < N; ++j)
            if(m[i][j] != m[j][i])
                return false;
    return true;
}
