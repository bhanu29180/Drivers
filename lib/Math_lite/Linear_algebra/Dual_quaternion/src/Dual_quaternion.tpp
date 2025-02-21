#include "Dual_quaternion.h"

template <typename T>
constexpr DualQuaternion<T>::DualQuaternion() : real(), dual()
{
}

template <typename T>
constexpr DualQuaternion<T>::DualQuaternion(const Quaternion<T>& real, const Quaternion<T>& dual)
    : real(real), dual(dual)
{
}

template <typename T>
constexpr DualQuaternion<T>::DualQuaternion(T r0, T r1, T r2, T r3, T d0, T d1, T d2, T d3)
    : real(r0, r1, r2, r3), dual(d0, d1, d2, d3)
{
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::zero()
{
    return DualQuaternion<T>(Quaternion<T>::zero(), Quaternion<T>::zero());
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::identity()
{
    return DualQuaternion<T>(Quaternion<T>::identity(), Quaternion<T>::zero());
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::from_rotation(const Quaternion<T>& rotation)
{
    return DualQuaternion<T>(rotation, Quaternion<T>::zero());
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::from_translation(T x, T y, T z)
{
    Quaternion<T> translation(0, x/2, y/2, z/2);
    return DualQuaternion<T>(
        Quaternion<T>::identity(),
        Quaternion<T>::mul(translation, Quaternion<T>::identity())
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::from_transform(const Quaternion<T>& rotation, T x, T y, T z)
{
    Quaternion<T> translation(0, x/2, y/2, z/2);
    return DualQuaternion<T>(
        rotation,
        Quaternion<T>::mul(translation, rotation)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::add(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2)
{
    return DualQuaternion<T>(
        Quaternion<T>::add(dq1.real, dq2.real),
        Quaternion<T>::add(dq1.dual, dq2.dual)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::sub(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2)
{
    return DualQuaternion<T>(
        Quaternion<T>::sub(dq1.real, dq2.real),
        Quaternion<T>::sub(dq1.dual, dq2.dual)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::mul(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2)
{
    return DualQuaternion<T>(
        Quaternion<T>::mul(dq1.real, dq2.real),
        Quaternion<T>::add(
            Quaternion<T>::mul(dq1.real, dq2.dual),
            Quaternion<T>::mul(dq1.dual, dq2.real)
        )
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::mul(const DualQuaternion<T>& dq, T s)
{
    return DualQuaternion<T>(
        Quaternion<T>::mul(dq.real, s),
        Quaternion<T>::mul(dq.dual, s)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::mul(T s, const DualQuaternion<T>& dq)
{
    return mul(dq, s);
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::div(const DualQuaternion<T>& dq, T s)
{
    return DualQuaternion<T>(
        Quaternion<T>::div(dq.real, s),
        Quaternion<T>::div(dq.dual, s)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::conj(const DualQuaternion<T>& dq)
{
    return DualQuaternion<T>(
        Quaternion<T>::conj(dq.real),
        Quaternion<T>::conj(dq.dual)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::inv(const DualQuaternion<T>& dq)
{
    Quaternion<T> real_inv = Quaternion<T>::inv(dq.real);
    return DualQuaternion<T>(
        real_inv,
        Quaternion<T>::mul(
            Quaternion<T>::mul(real_inv, Quaternion<T>::mul(dq.dual, real_inv)),
            T(-1)
        )
    );
}

template <typename T>
inline constexpr T DualQuaternion<T>::norm(const DualQuaternion<T>& dq)
{
    return Quaternion<T>::norm(dq.real);
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::normalize(const DualQuaternion<T>& dq)
{
    T n = norm(dq);
    return div(dq, n);
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::exp(const DualQuaternion<T>& dq)
{
    Quaternion<T> exp_real = Quaternion<T>::exp(dq.real);
    return DualQuaternion<T>(
        exp_real,
        Quaternion<T>::mul(exp_real, dq.dual)
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::log(const DualQuaternion<T>& dq)
{
    Quaternion<T> log_real = Quaternion<T>::log(dq.real);
    return DualQuaternion<T>(
        log_real,
        Quaternion<T>::mul(
            Quaternion<T>::mul(
                Quaternion<T>::inv(dq.real),
                dq.dual
            ),
            T(1)
        )
    );
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::pow(const DualQuaternion<T>& dq, T t)
{
    return exp(mul(log(dq), t));
}

template <typename T>
inline constexpr void DualQuaternion<T>::get_screw_parameters(const DualQuaternion<T>& dq,
    T& angle, T& pitch, T& direction_x, T& direction_y, T& direction_z,
    T& moment_x, T& moment_y, T& moment_z)
{
    // Extract rotation angle and axis
    T cos_half_angle = dq.real.q0;
    angle = T(2) * std::acos(cos_half_angle);
    
    T sin_half_angle = std::sqrt(T(1) - cos_half_angle * cos_half_angle);
    if (std::abs(sin_half_angle) < T(1e-10)) {
        direction_x = direction_y = direction_z = T(0);
        direction_x = T(1);  // Default direction if no rotation
    } else {
        direction_x = dq.real.q1 / sin_half_angle;
        direction_y = dq.real.q2 / sin_half_angle;
        direction_z = dq.real.q3 / sin_half_angle;
    }

    // Extract translation along the screw axis (pitch)
    if (std::abs(angle) < T(1e-10)) {
        pitch = T(0);
    } else {
        pitch = T(2) * (-dq.dual.q0 * dq.real.q1 + dq.real.q0 * dq.dual.q1 
                        -dq.dual.q2 * dq.real.q3 + dq.dual.q3 * dq.real.q2) / angle;
    }

    // Calculate moment vector
    moment_x = T(2) * (-dq.dual.q0 * dq.real.q1 + dq.real.q0 * dq.dual.q1 
                      -dq.dual.q2 * dq.real.q3 + dq.dual.q3 * dq.real.q2);
    moment_y = T(2) * (-dq.dual.q0 * dq.real.q2 + dq.real.q0 * dq.dual.q2 
                      -dq.dual.q3 * dq.real.q1 + dq.dual.q1 * dq.real.q3);
    moment_z = T(2) * (-dq.dual.q0 * dq.real.q3 + dq.real.q0 * dq.dual.q3 
                      -dq.dual.q1 * dq.real.q2 + dq.dual.q2 * dq.real.q1);
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::LERP(
    const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau)
{
    return add(mul(dq1, T(1) - tau), mul(dq2, tau));
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::SLERP(
    const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau)
{
    return mul(dq1, pow(mul(inv(dq1), dq2), tau));
}

template <typename T>
inline constexpr DualQuaternion<T> DualQuaternion<T>::ScLERP(
    const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau)
{
    DualQuaternion<T> dq = mul(inv(dq1), dq2);
    T angle, pitch, dx, dy, dz, mx, my, mz;
    get_screw_parameters(dq, angle, pitch, dx, dy, dz, mx, my, mz);
    
    // Create screw motion transformation
    T scaled_angle = angle * tau;
    T scaled_pitch = pitch * tau;
    Quaternion<T> rot = Quaternion<T>(
        std::cos(scaled_angle/T(2)),
        dx * std::sin(scaled_angle/T(2)),
        dy * std::sin(scaled_angle/T(2)),
        dz * std::sin(scaled_angle/T(2))
    );
    
    T d = scaled_pitch / T(2);
    Quaternion<T> trans = Quaternion<T>(
        T(0),
        d * dx,
        d * dy,
        d * dz
    );
    
    return mul(dq1, DualQuaternion<T>(rot, Quaternion<T>::mul(trans, rot)));
}

template <typename T>
void DualQuaternion<T>::get_rotation(Quaternion<T>& rotation) const
{
    rotation = real;
}

template <typename T>
void DualQuaternion<T>::get_translation(T& x, T& y, T& z) const
{
    Quaternion<T> t = Quaternion<T>::mul(dual, T(2));
    t = Quaternion<T>::mul(t, Quaternion<T>::conj(real));
    x = t.q1;
    y = t.q2;
    z = t.q3;
}

template <typename T>
void DualQuaternion<T>::get_rotation_matrix(T matrix[3][3]) const
{
    T q0 = real.q0, q1 = real.q1, q2 = real.q2, q3 = real.q3;
    T sq0 = q0*q0, sq1 = q1*q1, sq2 = q2*q2, sq3 = q3*q3;
    
    matrix[0][0] = sq0 + sq1 - sq2 - sq3;
    matrix[0][1] = T(2) * (q1*q2 - q0*q3);
    matrix[0][2] = T(2) * (q1*q3 + q0*q2);
    
    matrix[1][0] = T(2) * (q1*q2 + q0*q3);
    matrix[1][1] = sq0 - sq1 + sq2 - sq3;
    matrix[1][2] = T(2) * (q2*q3 - q0*q1);
    
    matrix[2][0] = T(2) * (q1*q3 - q0*q2);
    matrix[2][1] = T(2) * (q2*q3 + q0*q1);
    matrix[2][2] = sq0 - sq1 - sq2 + sq3;
}

template <typename T>
void DualQuaternion<T>::get_transformation_matrix(T matrix[4][4]) const
{
    get_rotation_matrix(reinterpret_cast<T(*)[3]>(matrix));
    
    T x, y, z;
    get_translation(x, y, z);
    
    matrix[0][3] = x;
    matrix[1][3] = y;
    matrix[2][3] = z;
    
    matrix[3][0] = matrix[3][1] = matrix[3][2] = T(0);
    matrix[3][3] = T(1);
}

// Operator Overloads
template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator+() const
{
    return *this;
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator-() const
{
    return DualQuaternion<T>(-real, -dual);
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator+(const DualQuaternion<T>& other) const
{
    return add(*this, other);
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator-(const DualQuaternion<T>& other) const
{
    return sub(*this, other);
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator*(const DualQuaternion<T>& other) const
{
    return mul(*this, other);
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator*(T scalar) const
{
    return mul(*this, scalar);
}

template <typename T>
constexpr DualQuaternion<T> DualQuaternion<T>::operator/(T scalar) const
{
    return div(*this, scalar);
}

template <typename T>
DualQuaternion<T>& DualQuaternion<T>::operator+=(const DualQuaternion<T>& other)
{
    real += other.real;
    dual += other.dual;
    return *this;
}

template <typename T>
DualQuaternion<T>& DualQuaternion<T>::operator-=(const DualQuaternion<T>& other)
{
    real -= other.real;
    dual -= other.dual;
    return *this;
}

template <typename T>
DualQuaternion<T>& DualQuaternion<T>::operator*=(const DualQuaternion<T>& other)
{
    *this = mul(*this, other);
    return *this;
}

template <typename T>
DualQuaternion<T>& DualQuaternion<T>::operator*=(T scalar)
{
    real *= scalar;
    dual *= scalar;
    return *this;
}

template <typename T>
DualQuaternion<T>& DualQuaternion<T>::operator/=(T scalar)
{
    real /= scalar;
    dual /= scalar;
    return *this;
}

template <typename T>
constexpr bool DualQuaternion<T>::operator==(const DualQuaternion<T>& other) const
{
    return (real == other.real) && (dual == other.dual);
}

template <typename T>
constexpr bool DualQuaternion<T>::operator!=(const DualQuaternion<T>& other) const
{
    return !(*this == other);
}
