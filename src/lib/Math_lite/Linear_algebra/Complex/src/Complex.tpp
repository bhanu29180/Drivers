#include "Complex.h"

template <typename T>
constexpr Complex<T>::Complex() : real(0), imag(0)
{
}

template <typename T>
constexpr Complex<T>::Complex(T real, T imag) : real(real), imag(imag)
{
}

template <typename T>
inline constexpr Complex<T> Complex<T>::zero()
{
    return Complex<T>(0, 0);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::one()
{
    return Complex<T>(1, 0);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::i()
{
    return Complex<T>(0, 1);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::add(const Complex<T>& z1, const Complex<T>& z2)
{
    return Complex<T>(z1.real + z2.real, z1.imag + z2.imag);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::sub(const Complex<T>& z1, const Complex<T>& z2)
{
    return Complex<T>(z1.real - z2.real, z1.imag - z2.imag);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::mul(const Complex<T>& z1, const Complex<T>& z2)
{
    return Complex<T>(
        z1.real * z2.real - z1.imag * z2.imag,
        z1.real * z2.imag + z1.imag * z2.real
    );
}

template <typename T>
inline constexpr Complex<T> Complex<T>::mul(const Complex<T>& z, T s)
{
    return Complex<T>(z.real * s, z.imag * s);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::mul(T s, const Complex<T>& z)
{
    return Complex<T>(z.real * s, z.imag * s);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::div(const Complex<T>& z1, const Complex<T>& z2)
{
    T denominator = z2.real * z2.real + z2.imag * z2.imag;
    return Complex<T>(
        (z1.real * z2.real + z1.imag * z2.imag) / denominator,
        (z1.imag * z2.real - z1.real * z2.imag) / denominator
    );
}

template <typename T>
inline constexpr Complex<T> Complex<T>::div(const Complex<T>& z, T s)
{
    return Complex<T>(z.real / s, z.imag / s);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::conj(const Complex<T>& z)
{
    return Complex<T>(z.real, -z.imag);
}

template <typename T>
inline constexpr T Complex<T>::abs(const Complex<T>& z)
{
    return std::sqrt(z.real * z.real + z.imag * z.imag);
}

template <typename T>
inline constexpr T Complex<T>::arg(const Complex<T>& z)
{
    return std::atan2(z.imag, z.real);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::inv(const Complex<T>& z)
{
    T denominator = z.real * z.real + z.imag * z.imag;
    return Complex<T>(z.real / denominator, -z.imag / denominator);
}

template <typename T>
inline constexpr Complex<T> Complex<T>::sqrt(const Complex<T>& z)
{
    T r = abs(z);
    T theta = arg(z) / 2;
    return Complex<T>(std::cos(theta) * std::sqrt(r), std::sin(theta) * std::sqrt(r));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::exp(const Complex<T>& z)
{
    T e_x = std::exp(z.real);
    return Complex<T>(e_x * std::cos(z.imag), e_x * std::sin(z.imag));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::log(const Complex<T>& z)
{
    return Complex<T>(std::log(abs(z)), arg(z));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::pow(const Complex<T>& z, T n)
{
    T r = abs(z);
    T theta = arg(z);
    T r_n = std::pow(r, n);
    return Complex<T>(r_n * std::cos(n * theta), r_n * std::sin(n * theta));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::pow(const Complex<T>& z1, const Complex<T>& z2)
{
    return exp(mul(log(z1), z2));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::sin(const Complex<T>& z)
{
    return Complex<T>(
        std::sin(z.real) * std::cosh(z.imag),
        std::cos(z.real) * std::sinh(z.imag)
    );
}

template <typename T>
inline constexpr Complex<T> Complex<T>::cos(const Complex<T>& z)
{
    return Complex<T>(
        std::cos(z.real) * std::cosh(z.imag),
        -std::sin(z.real) * std::sinh(z.imag)
    );
}

template <typename T>
inline constexpr Complex<T> Complex<T>::tan(const Complex<T>& z)
{
    return div(sin(z), cos(z));
}

template <typename T>
inline constexpr Complex<T> Complex<T>::fromPolar(T r, T theta)
{
    return Complex<T>(r * std::cos(theta), r * std::sin(theta));
}

template <typename T>
inline constexpr void Complex<T>::toPolar(T& r, T& theta) const
{
    r = abs(*this);
    theta = arg(*this);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Complex<T> Complex<T>::operator-() const
{
    return Complex<T>(-real, -imag);
}

template <typename T>
Complex<T>& Complex<T>::operator++()
{
    ++real;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator++(int)
{
    Complex<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Complex<T>& Complex<T>::operator--()
{
    --real;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator--(int)
{
    Complex<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Complex<T> Complex<T>::operator+(const Complex<T>& other) const
{
    return add(*this, other);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator-(const Complex<T>& other) const
{
    return sub(*this, other);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator*(const Complex<T>& other) const
{
    return mul(*this, other);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator/(const Complex<T>& other) const
{
    return div(*this, other);
}

template <typename T>
constexpr Complex<T> Complex<T>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T>
Complex<T>& Complex<T>::operator+=(const Complex<T>& other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator-=(const Complex<T>& other)
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator*=(const Complex<T>& other)
{
    T temp_real = real * other.real - imag * other.imag;
    imag = real * other.imag + imag * other.real;
    real = temp_real;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator*=(T scalar)
{
    real *= scalar;
    imag *= scalar;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator/=(const Complex<T>& other)
{
    T denominator = other.real * other.real + other.imag * other.imag;
    T temp_real = (real * other.real + imag * other.imag) / denominator;
    imag = (imag * other.real - real * other.imag) / denominator;
    real = temp_real;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator/=(T scalar)
{
    real /= scalar;
    imag /= scalar;
    return *this;
}

template <typename T>
constexpr bool Complex<T>::operator==(const Complex<T>& other) const
{
    return (real == other.real) && (imag == other.imag);
}

template <typename T>
constexpr bool Complex<T>::operator!=(const Complex<T>& other) const
{
    return !(*this == other);
}