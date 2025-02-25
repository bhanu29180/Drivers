#include <algorithm>
#include <cstring>
#include "MatrixN.h"

template <typename T, size_t N>
constexpr MatrixN<T,N>::MatrixN()
{
    // Default constructor - array already zero-initialized
}

template <typename T, size_t N>
constexpr MatrixN<T,N>::MatrixN(const std::initializer_list<std::initializer_list<T>>& list)
{
    size_t i = 0;
    for (const auto& row : list) {
        size_t j = 0;
        for (const auto& val : row) {
            if (i < N && j < N) {
                m[i][j] = val;
            }
            ++j;
        }
        ++i;
    }
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::zero()
{
    return MatrixN<T,N>();
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::ones()
{
    MatrixN<T,N> result;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            result.m[i][j] = T(1);
    return result;
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::identity()
{
    MatrixN<T,N> result;
    for (size_t i = 0; i < N; ++i)
        result.m[i][i] = T(1);
    return result;
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::add(const MatrixN<T,N>& M1, const MatrixN<T,N>& M2)
{
    MatrixN<T,N> result;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            result.m[i][j] = M1.m[i][j] + M2.m[i][j];
    return result;
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::mul(const MatrixN<T,N>& M1, const MatrixN<T,N>& M2)
{
    MatrixN<T,N> result;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            T sum = T();
            for (size_t k = 0; k < N; ++k) {
                sum += M1.m[i][k] * M2.m[k][j];
            }
            result.m[i][j] = sum;
        }
    }
    return result;
}

template <typename T, size_t N>
inline constexpr MatrixN<T,N> MatrixN<T,N>::trans(const MatrixN<T,N>& M)
{
    MatrixN<T,N> result;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            result.m[i][j] = M.m[j][i];
    return result;
}

// Helper function for determinant calculation
template<typename T, size_t N>
constexpr T calculateDeterminant(const MatrixN<T,N>& M) {
    if constexpr (N == 1) {
        return M.m[0][0];
    }
    else if constexpr (N == 2) {
        return M.m[0][0] * M.m[1][1] - M.m[0][1] * M.m[1][0];
    }
    else {
        T result = T();
        int sign = 1;

        for (size_t j = 0; j < N; ++j) {
            // Create submatrix
            MatrixN<T,N-1> submatrix;

            // Fill submatrix excluding first row and column j
            for (size_t row = 1; row < N; ++row) {
                size_t sub_col = 0;
                for (size_t col = 0; col < N; ++col) {
                    if (col != j) {
                        submatrix.m[row-1][sub_col++] = M.m[row][col];
                    }
                }
            }

            result += sign * M.m[0][j] * calculateDeterminant(submatrix);
            sign = -sign;
        }
        return result;
    }
}

template <typename T, size_t N>
inline constexpr T MatrixN<T,N>::det(const MatrixN<T,N>& M)
{
    return calculateDeterminant(M);
}

template <typename T, size_t N>
inline constexpr T MatrixN<T,N>::trace(const MatrixN<T,N>& M)
{
    T result = T();
    for (size_t i = 0; i < N; ++i)
        result += M.m[i][i];
    return result;
}

template <typename T, size_t N>
constexpr MatrixN<T,N> MatrixN<T,N>::operator+(const MatrixN<T,N>& other) const
{
    return add(*this, other);
}

template <typename T, size_t N>
constexpr MatrixN<T,N> MatrixN<T,N>::operator-(const MatrixN<T,N>& other) const
{
    return sub(*this, other);
}

template <typename T, size_t N>
constexpr MatrixN<T,N> MatrixN<T,N>::operator*(const MatrixN<T,N>& other) const
{
    return mul(*this, other);
}

template <typename T, size_t N>
constexpr MatrixN<T,N> MatrixN<T,N>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T, size_t N>
constexpr MatrixN<T,N> MatrixN<T,N>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T, size_t N>
bool MatrixN<T,N>::isDiagonal() const
{
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            if (i != j && m[i][j] != T())
                return false;
    return true;
}

template <typename T, size_t N>
bool MatrixN<T,N>::isSingular() const
{
    return det(*this) == T();
}

template <typename T, size_t N>
bool MatrixN<T,N>::isSymmetric() const
{
    for (size_t i = 0; i < N; ++i)
        for (size_t j = i + 1; j < N; ++j)
            if (m[i][j] != m[j][i])
                return false;
    return true;
}
