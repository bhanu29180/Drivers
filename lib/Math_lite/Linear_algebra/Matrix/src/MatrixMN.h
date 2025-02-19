#ifndef MATRIXMN_H
#define MATRIXMN_H

#include <cmath>
#include <type_traits>
#include <initializer_list>

template <typename T, int M, int N>
class MatrixMN
{
public:
    T m[M][N] = {{0}};

    // Constructors
    constexpr MatrixMN();
    // Variadic constructor: accepts exactly M*N values in row-major order.
    template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == M * N>>
    constexpr MatrixMN(Args... args);
    
    constexpr MatrixMN(const MatrixMN<T, M, N>& other);
    constexpr MatrixMN<T, M, N>& operator=(const MatrixMN<T, M, N>& other);
    
    // Static functions to create matrices
    static inline constexpr MatrixMN<T, M, N> zero();
    static inline constexpr MatrixMN<T, M, N> ones();

    // Identity is only defined for square matrices.
    static inline constexpr MatrixMN<T, M, N> identity();

    // Static arithmetic operations (element-wise for add/sub; proper matrix multiplication for mul is defined for square matrices)
    static inline constexpr MatrixMN<T, M, N> add(const MatrixMN<T, M, N>& A, const MatrixMN<T, M, N>& B);
    static inline constexpr MatrixMN<T, M, N> sub(const MatrixMN<T, M, N>& A, const MatrixMN<T, M, N>& B);
    static inline constexpr MatrixMN<T, M, N> mul(const MatrixMN<T, M, N>& A, const MatrixMN<T, M, N>& B);
    
    static inline constexpr MatrixMN<T, M, N> add(const MatrixMN<T, M, N>& A, T val);
    static inline constexpr MatrixMN<T, M, N> add(T val, const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> sub(const MatrixMN<T, M, N>& A, T val);
    static inline constexpr MatrixMN<T, M, N> sub(T val, const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> mul(const MatrixMN<T, M, N>& A, T val);
    static inline constexpr MatrixMN<T, M, N> mul(T val, const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> div(const MatrixMN<T, M, N>& A, T val);

    // Transpose returns a matrix with dimensions N x M.
    static inline constexpr MatrixMN<T, N, M> trans(const MatrixMN<T, M, N>& A);

    // The following functions are meaningful only for square matrices (M == N)
    static inline constexpr T det(const MatrixMN<T, M, N>& A);
    static inline constexpr T trace(const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> minor(const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> cofactor(const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> adj(const MatrixMN<T, M, N>& A);
    static inline constexpr MatrixMN<T, M, N> inv(const MatrixMN<T, M, N>& A);

    // Operator overloads (arithmetic)
    constexpr MatrixMN<T, M, N> operator+(const MatrixMN<T, M, N>& other) const;
    constexpr MatrixMN<T, M, N> operator-(const MatrixMN<T, M, N>& other) const;
    constexpr MatrixMN<T, M, N> operator*(const MatrixMN<T, M, N>& other) const;
    constexpr MatrixMN<T, M, N> operator*(T scalar) const;
    constexpr MatrixMN<T, M, N> operator/(T scalar) const;
    constexpr MatrixMN<T, M, N> operator%(T scalar) const;

    constexpr MatrixMN<T, M, N> operator+() const;
    constexpr MatrixMN<T, M, N> operator-() const;
    MatrixMN<T, M, N>& operator++();
    MatrixMN<T, M, N> operator++(int);
    MatrixMN<T, M, N>& operator--();
    MatrixMN<T, M, N> operator--(int);

    MatrixMN<T, M, N>& operator+=(const MatrixMN<T, M, N>& other);
    MatrixMN<T, M, N>& operator-=(const MatrixMN<T, M, N>& other);
    MatrixMN<T, M, N>& operator*=(const MatrixMN<T, M, N>& other);
    MatrixMN<T, M, N>& operator*=(T scalar);
    MatrixMN<T, M, N>& operator/=(T scalar);
    MatrixMN<T, M, N>& operator%=(T scalar);

    constexpr bool operator==(const MatrixMN<T, M, N>& other) const;
    constexpr bool operator!=(const MatrixMN<T, M, N>& other) const;

    // Utility functions
    bool isDiagonal() const;
    bool isSingular() const;
    bool isIdentity() const;
    bool isSymmetric() const;

    // Element access operators
    T& operator()(int row, int col);
    constexpr T operator()(int row, int col) const;
};

#include "MatrixMN.tpp"

#endif
