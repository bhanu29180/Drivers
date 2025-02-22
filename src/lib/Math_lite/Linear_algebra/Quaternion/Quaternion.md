# Quaternion Library Documentation

## Overview
A templated quaternion library implementation designed for efficiency and suitability for embedded systems. The library provides comprehensive quaternion operations with compile-time optimizations.

## Mathematical Background
A quaternion q is represented as:
```
q = q₀ + q₁i + q₂j + q₃k
```
where q₀ is the scalar part and (q₁, q₂, q₃) form the vector part.

## Class Template
```cpp
template <typename T>
class Quaternion;
```
The template parameter `T` typically represents a floating-point type (float, double).

## Constructors

### Default Constructor
```cpp
constexpr Quaternion()
```
Initializes a quaternion with all components set to zero: (0, 0, 0, 0)

### Parameter Constructor
```cpp
constexpr Quaternion(T q0, T q1, T q2, T q3)
```
Initializes a quaternion with specified components: q = q₀ + q₁i + q₂j + q₃k

## Static Factory Methods

### zero()
```cpp
static inline constexpr Quaternion<T> zero()
```
Returns a zero quaternion: (0, 0, 0, 0)

### ones()
```cpp
static inline constexpr Quaternion<T> ones()
```
Returns a quaternion with all components set to one: (1, 1, 1, 1)

### identity()
```cpp
static inline constexpr Quaternion<T> identity()
```
Returns the identity quaternion: (1, 0, 0, 0)

## Basic Operations

### Addition
```cpp
static inline constexpr Quaternion<T> add(const Quaternion<T>& q₁, const Quaternion<T>& q₂)
```
Adds two quaternions component-wise:
```
result = (q₁₀ + q₂₀) + (q₁₁ + q₂₁)i + (q₁₂ + q₂₂)j + (q₁₃ + q₂₃)k
```

### Subtraction
```cpp
static inline constexpr Quaternion<T> sub(const Quaternion<T>& q₁, const Quaternion<T>& q₂)
```
Subtracts two quaternions component-wise:
```
result = (q₁₀ - q₂₀) + (q₁₁ - q₂₁)i + (q₁₂ - q₂₂)j + (q₁₃ - q₂₃)k
```

### Multiplication
```cpp
static inline constexpr Quaternion<T> mul(const Quaternion<T>& q₁, const Quaternion<T>& q₂)
```
Quaternion multiplication following Hamilton's rules:
```
q₁q₂ = (q₁₀q₂₀ - q₁₁q₂₁ - q₁₂q₂₂ - q₁₃q₂₃) +
       (q₁₀q₂₁ + q₁₁q₂₀ + q₁₂q₂₃ - q₁₃q₂₂)i +
       (q₁₀q₂₂ - q₁₁q₂₃ + q₁₂q₂₀ + q₁₃q₂₁)j +
       (q₁₀q₂₃ + q₁₁q₂₂ - q₁₂q₂₁ + q₁₃q₂₀)k
```

### Scalar Multiplication
```cpp
static inline constexpr Quaternion<T> mul(const Quaternion<T>& q, T s)
static inline constexpr Quaternion<T> mul(T s, const Quaternion<T>& q)
```
Multiplies each component by a scalar:
```
result = (sq₀) + (sq₁)i + (sq₂)j + (sq₃)k
```

### Division by Scalar
```cpp
static inline constexpr Quaternion<T> div(const Quaternion<T>& q, T s)
```
Divides each component by a scalar:
```
result = (q₀/s) + (q₁/s)i + (q₂/s)j + (q₃/s)k
```

## Advanced Operations

### Conjugate
```cpp
static inline constexpr Quaternion<T> conj(const Quaternion<T>& q)
```
Returns the conjugate of a quaternion:
```
q* = q₀ - q₁i - q₂j - q₃k
```

### Normalization
```cpp
static inline constexpr Quaternion<T> normalize(const Quaternion<T>& q)
```
Returns a unit quaternion in the same direction:
```
q_norm = q/|q| where |q| = √(q₀² + q₁² + q₂² + q₃²)
```

### Magnitude/Length/Norm
```cpp
static inline constexpr T magnitude(const Quaternion<T>& q)
static inline constexpr T length(const Quaternion<T>& q)
static inline constexpr T norm(const Quaternion<T>& q)
```
Returns the magnitude (length) of the quaternion:
```
|q| = √(q₀² + q₁² + q₂² + q₃²)
```

### Inverse
```cpp
static inline constexpr Quaternion<T> inv(const Quaternion<T>& q)
```
Returns the multiplicative inverse:
```
q⁻¹ = q*/(|q|²) where |q|² = q₀² + q₁² + q₂² + q₃²
```

### Natural Logarithm
```cpp
static inline constexpr Quaternion<T> log_e(const Quaternion<T>& q)
```
Computes the natural logarithm:
```
log(q) = log(|q|) + v/|v| * arccos(q₀/|q|)
where v = (q₁, q₂, q₃)
```

### Exponential
```cpp
static inline constexpr Quaternion<T> exp(const Quaternion<T>& q)
```
Computes the exponential:
```
exp(q) = exp(q₀)(cos(|v|) + v/|v| * sin(|v|))
where v = (q₁, q₂, q₃)
```

### Power
```cpp
static inline constexpr Quaternion<T> pow(const Quaternion<T>& q, T r)
```
Raises a quaternion to a real power:
```
q^r = exp(r * log(q))
```

## Interpolation

### Linear Interpolation (LERP)
```cpp
static inline constexpr Quaternion<T> LERP(const Quaternion<T>& q₁, const Quaternion<T>& q₂, T tau)
```
Linear interpolation between two quaternions:
```
LERP(q₁, q₂, τ) = (1-τ)q₁ + τq₂
```

### Spherical Linear Interpolation (SLERP)
```cpp
static inline constexpr Quaternion<T> SLERP(const Quaternion<T>& q₁, const Quaternion<T>& q₂, T tau)
```
Spherical linear interpolation between two quaternions:
```
SLERP(q₁, q₂, τ) = q₁(q₁⁻¹q₂)^τ
```
Computationally:
```
SLERP(q₁, q₂, τ) = (sin((1-τ)θ)/sin(θ))q₁ + (sin(τθ)/sin(θ))q₂
where θ = arccos(q₁·q₂)
```

## Operator Overloads

The library provides overloads for the following operators:
- Unary: `+q`, `-q`
- Increment/Decrement: `++q`, `q++`, `--q`, `q--`
- Binary arithmetic: `q₁ + q₂`, `q₁ - q₂`, `q * s`, `q / s`, `q % s`
- Compound assignment: `+=`, `-=`, `*=`, `/=`, `%=`
- Comparison: `==`, `!=`

## Usage Example
```cpp
#include "Quaternion.h"

int main() {
    // Create quaternions
    Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
    Quaternion<double> q2(2.0, 3.0, 4.0, 5.0);
    
    // Basic operations
    auto sum = q1 + q2;
    auto product = q1 * q2;
    
    // Normalization
    auto unit_q = Quaternion<double>::normalize(q1);
    
    // Interpolation
    auto interpolated = Quaternion<double>::SLERP(q1, q2, 0.5);
    
    return 0;
}
```

## Performance Considerations
- The library is header-only and uses template metaprogramming
- Most operations are marked `constexpr` for compile-time evaluation
- No dynamic memory allocation
- Suitable for embedded systems and microcontrollers
- Optimized for minimal computational overhead
