#ifndef MATRIX2_H
#define MATRIX2_H

element operator
    increment
    decrement
    multiplication
    division

mathematical opetation
    addition
    subtraction
    multiplication
    division
    transpose
    inverse

#endif

1. Constructors & Initialization
    Matrix2()  Default constructor (zero matrix)
    Matrix2(T a, T b, T c, T d)  Initialize with four values
    Matrix2(const Matrix2& other)  Copy constructor
    Matrix2& operator=(const Matrix2& other)  Copy assignment
2. Basic Matrix Operations
    Matrix2 operator+(const Matrix2& other) const  Matrix addition
    Matrix2 operator-(const Matrix2& other) const  Matrix subtraction
    Matrix2 operator*(const Matrix2& other) const  Matrix multiplication
    Matrix2 operator*(T scalar) const  Scalar multiplication
    Matrix2 operator/(T scalar) const  Scalar division
    bool operator==(const Matrix2& other) const  Equality check
    bool operator!=(const Matrix2& other) const  Inequality check
3. Access & Modification
    T& operator()(int row, int col)  Element access (modifiable)
    T operator()(int row, int col) const  Element access (read-only)
    void set(T a, T b, T c, T d)  Set all elements
    void setIdentity()  Set to identity matrix
    void setZero()  Set to zero matrix
4. Linear Algebra Operations
    T determinant() const  Compute determinant
    Matrix2 transpose() const  Compute transpose
    Matrix2 inverse() const  Compute inverse (if determinant ≠ 0)
    T trace() const  Compute trace (sum of diagonal elements)
5. Utility Functions
    bool isSingular() const  Check if determinant is zero
    bool isIdentity() const  Check if matrix is identity
    bool isSymmetric() const  Check if matrix is symmetric
    void print() const  Print matrix (for debugging)