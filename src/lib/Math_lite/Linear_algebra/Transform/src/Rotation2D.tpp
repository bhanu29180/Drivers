#include "Rotation2D.h"

template <typename T>
constexpr Rotation2D<T>::Rotation2D() : c(Complex<T>::one())
{
}

template <typename T>
constexpr Rotation2D<T>::Rotation2D(const Complex<T>& c) : c(c)
{
}

template <typename T>
constexpr Rotation2D<T>::Rotation2D(T angle)
    : c(std::cos(angle), std::sin(angle))
{
}

template <typename T>
Rotation2D<T> Rotation2D<T>::from_matrix(T m00, T m01, T m10, T m11)
{
    // Extract the complex number from the first row of the matrix
    // (which should be normalized)
    return Rotation2D<T>(Complex<T>(m00, m10));
}

template <typename T>
Complex<T> Rotation2D<T>::as_complex() const
{
    return c;
}

template <typename T>
T Rotation2D<T>::angle() const
{
    return std::atan2(c.imag, c.real);
}

template <typename T>
void Rotation2D<T>::get_matrix(T& m00, T& m01, T& m10, T& m11) const
{
    m00 = c.real;  // real part
    m01 = -c.imag; // negative imaginary part
    m10 = c.imag;  // imaginary part
    m11 = c.real;  // real part
}

template <typename T>
Rotation2D<T> Rotation2D<T>::inverse() const
{
    return Rotation2D<T>(Complex<T>::conj(c));
}

template <typename T>
Rotation2D<T> Rotation2D<T>::operator*(const Rotation2D<T>& other) const
{
    return Rotation2D<T>(Complex<T>::mul(c, other.c));
}

template <typename T>
void Rotation2D<T>::rotate(T x, T y, T& rx, T& ry) const
{
    // Rotate point (x,y) by multiplying with the complex number
    Complex<T> rotated = Complex<T>::mul(c, Complex<T>(x, y));
    rx = rotated.real;  // real part
    ry = rotated.imag;  // imaginary part
}

template <typename T>
Rotation2D<T> Rotation2D<T>::identity()
{
    return Rotation2D<T>();
}

template <typename T>
Rotation2D<T> Rotation2D<T>::lerp(const Rotation2D<T>& r1, const Rotation2D<T>& r2, T t)
{
    // Linear interpolation between complex numbers (not ideal for rotations)
    Complex<T> c = Complex<T>::add(
        Complex<T>::mul(r1.c, T(1) - t),
        Complex<T>::mul(r2.c, t)
    );
    return Rotation2D<T>(Complex<T>::normalize(c));
}

template <typename T>
Rotation2D<T> Rotation2D<T>::slerp(const Rotation2D<T>& r1, const Rotation2D<T>& r2, T t)
{
    // Get the angles
    T angle1 = r1.angle();
    T angle2 = r2.angle();

    // Ensure we take the shortest path
    if (angle2 - angle1 > M_PI)
        angle2 -= T(2) * M_PI;
    else if (angle1 - angle2 > M_PI)
        angle2 += T(2) * M_PI;

    // Interpolate the angle
    T angle = angle1 + t * (angle2 - angle1);

    // Create rotation from interpolated angle
    return Rotation2D<T>(angle);
}