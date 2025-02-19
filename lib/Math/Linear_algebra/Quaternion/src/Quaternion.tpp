#include "Quaternion.h"

template <typename T>
constexpr Quaternion<T>::Quaternion() : q0(0), q1(0), q2(0), q3(0)
{
}

template <typename T>
constexpr Quaternion<T>::Quaternion(T q0, T q1, T q2, T q3) : q0(q0), q1(q1), q2(q2), q3(q3)
{
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::zero()
{
    return Quaternion<T>(0, 0, 0, 0)
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::ones()
{
    return Quaternion<T>(1, 1, 1, 1)
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::identity()
{
    return Quaternion<T>(1, 0, 0, 0)
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::add(const Quaternion<T>& q_1, const Quaternion<T>& q_2)
{
    return Quaternion<T>(q_1.q0 + q_2.q0, q_1.q1 + q_2.q1, q_1.q2 + q_2.q2, q_1.q3 + q_2.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::sub(const Quaternion<T>& q_1, const Quaternion<T>& q_2)
{
    return Quaternion<T>(q_1.q0 - q_2.q0, q_1.q1 - q_2.q1, q_1.q2 - q_2.q2, q_1.q3 - q_2.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(const Quaternion<T>& q_1, const Quaternion<T>& q_2)
{
    Quaternion<T> q_3;
    q_3.q0 = q_1.q0*q_2.q0 - q_1.q1*q_2.q1 - q_1.q2*q_2.q2 - q_1.q3*q_2.q3;
    q_3.q1 = q_1.q0*q_2.q1 + q_1.q1*q_2.q0 + q_1.q2*q_2.q3 - q_1.q3*q_2.q2;
    q_3.q2 = q_1.q0*q_2.q2 - q_1.q1*q_2.q3 + q_1.q2*q_2.q0 + q_1.q3*q_2.q1;
    q_3.q3 = q_1.q0*q_2.q3 + q_1.q1*q_2.q2 - q_1.q2*q_2.q1 + q_1.q3*q_2.q0;
    return q_3;
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(const Quaternion<T>& q, T s)
{
    return Quaternion<T>(q.q0 * s, q.q1 * s, q.q2 * s, q.q3 * s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::mul(T s, const Quaternion<T>& q)
{
    return Quaternion<T>(q.q0 * s, q.q1 * s, q.q2 * s, q.q3 * s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::div(const Quaternion<T>& q, T s)
{
    return Quaternion<T>(q.q0 / s, q.q1 / s, q.q2 / s, q.q3 / s);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::conj(const Quaternion<T>& q)
{
    return Quaternion<T>(q.q0, -q.q1, -q.q2, -q.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::normalize(const Quaternion<T>& q)
{
    T mag = sqrt(q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3);
    return Quaternion<T>(q.q0/mag, q.q1/mag, q.q2/mag, q.q3/mag);
}

template <typename T>
inline constexpr T Quaternion<T>::magnitude(const Quaternion<T>& q)
{
    return sqrt(q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3);
}

template <typename T>
inline constexpr T Quaternion<T>::length(const Quaternion<T>& q)
{
    return sqrt(q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3);
}

template <typename T>
inline constexpr T Quaternion<T>::norm(const Quaternion<T>& q)
{
    return sqrt(q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3);
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::inv(const Quaternion<T>& q)
{
    T len = q.q0*q.q0 + q.q1*q.q1 + q.q2*q.q2 + q.q3*q.q3;
    if (len == T(1))
    {
        return Quaternion<T>(q.q0, -q.q1, -q.q2, -q.q3);
    }
    else
    {
        return Quaternion<T>(q.q0/len, -q.q1/len, -q.q2/len, -q.q3/len);
    }
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::log_e(const Quaternion<T>& q)
{
    Quaternion<T> q_2;

    T q_norm = norm(q);
    q_2.q0 = log(q_norm);

    T u_norm = sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    T acos_q0_norm_q = acos(q.q0 / norm(q));
    q_2.q1 = acos_q0_norm_q * q.q1 / u_norm;
    q_2.q2 = acos_q0_norm_q * q.q2 / u_norm;
    q_2.q3 = acos_q0_norm_q * q.q3 / u_norm;

    return q_2;
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::exp(const Quaternion<T>& q)
{
    Quaternion<T> q_2;
    <T> u_norm = sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    q_2.q0 = cos(u_norm);
    q_2.q1 = sin(u_norm) * q.q1 / u_norm;
    q_2.q2 = sin(u_norm) * q.q2 / u_norm;
    q_2.q3 = sin(u_norm) * q.q3 / u_norm;

    q_2 = q2 * exp(q.q0);

    return q2;
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::pow(const Quaternion<T>& q, T r)
{
    T norm_q = norm(q);
    T th = acos(q.q0 / sqrt(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3));
    T u_norm = sqrt(q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);

    if(u_norm==0.0)
    {
        T sin_r_th = sin(r * th);
        return Quaternion<T>(pow(norm_q,r), 0.0, 0.0, 0.0);
    }
    else
    {
        T u_hat_x = q.q1 / u_norm;
        T u_hat_y = q.q2 / u_norm;
        T u_hat_z = q.q3 / u_norm;

        T sin_r_th = sin(r * th);
        Quaternion<T> q_2(cos(r*th), u_hat_x * sin_r_th, u_hat_y * sin_r_th, u_hat_z * sin_r_th);
        q2 = q2 * pow(norm_q,r);
        return q2;
    }
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::LERP(const Quaternion<T>& q_1, const Quaternion<T>& q_2, T tau)
{
    return (tau*q_1) + (T(1)-tau)*q_2;
}

template <typename T>
inline constexpr Quaternion<T> Quaternion<T>::SLERP(const Quaternion<T>& q_1, const Quaternion<T>& q_2, T tau)
{
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator-() const
{
    return Quaternion<T>(-q0, -q1, -q2, -q3);
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator++()
{
    ++q0;
    ++q1;
    ++q2;
    ++q3;
    return *this;
}

template <typename T>
Quaternion<T> Quaternion<T>::operator++(int)
{
    Quaternion<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator--()
{
    --q0;
    --q1;
    --q2;
    --q3;
    return *this;
}

template <typename T>
Quaternion<T> Quaternion<T>::operator--(int)
{
    Quaternion<T> temp = *this;
    --(*this);
    return temp;
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator+(const Quaternion<T>& other) const
{
    return Quaternion<T>(q0+other.q0, q1+other.q1, q2+other.q2, q3+other.q3);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator-(const Quaternion<T>& other) const
{
    return Quaternion<T>(q0-other.q0, q1-other.q1, q2-other.q2, q3-other.q3);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator*(T scalar) const
{
    return Quaternion<T>(q0*scalar, q1*scalar, q2*scalar, q3*scalar);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator/(T scalar) const
{
    return Quaternion<T>(q0/scalar, q1/scalar, q2/scalar, q3/scalar);
}

template <typename T>
constexpr Quaternion<T> Quaternion<T>::operator%(T scalar) const
{
    return Quaternion<T>(q0%scalar, q1%scalar, q2%scalar, q3%scalar);
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& other)
{
    q0 += other.q0;
    q1 += other.q1;
    q2 += other.q2;
    q3 += other.q3;
    return *this;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& other)
{
    q0 -= other.q0;
    q1 -= other.q1;
    q2 -= other.q2;
    q3 -= other.q3;
    return *this;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& q_2)
{
    Quaternion<T> q_1(q0, q1, q2, q3);
    q0_ = q_1.q0*q_2.q0 - q_1.q1*q_2.q1 - q_1.q2*q_2.q2 - q_1.q3*q_2.q3;
    q1_ = q_1.q0*q_2.q1 + q_1.q1*q_2.q0 + q_1.q2*q_2.q3 - q_1.q3*q_2.q2;
    q2_ = q_1.q0*q_2.q2 - q_1.q1*q_2.q3 + q_1.q2*q_2.q0 + q_1.q3*q_2.q1;
    q3_ = q_1.q0*q_2.q3 + q_1.q1*q_2.q2 - q_1.q2*q_2.q1 + q_1.q3*q_2.q0;
    return *this;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator*=(T scalar)
{
    q0 *= scalar;
    q1 *= scalar;
    q2 *= scalar;
    q3 *= scalar;
    return *this;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator/=(T scalar)
{
    q0 /= scalar;
    q1 /= scalar;
    q2 /= scalar;
    q3 /= scalar;
    return *this;
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator%=(T scalar)
{
    q0 %= scalar;
    q1 %= scalar;
    q2 %= scalar;
    q3 %= scalar;
    return *this;
}

template <typename T>
constexpr bool Quaternion<T>::operator==(const Quaternion<T>& other) const
{
    return (q0==other.q0) && (q1==other.q1) && (q2==other.q2) || (q3==other.q3);
}

template <typename T>
constexpr bool Quaternion<T>::operator!=(const Quaternion<T>& other) const
{
    return !(*this == other)
}
