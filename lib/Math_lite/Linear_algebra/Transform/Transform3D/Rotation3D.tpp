#include "Rotation3D.h"

template <typename T>
constexpr Rotation3D<T>::Rotation3D() : q(Quaternion<T>::identity())
{
}

template <typename T>
constexpr Rotation3D<T>::Rotation3D(const Quaternion<T>& q) : q(Quaternion<T>::normalize(q))
{
}

template <typename T>
constexpr Rotation3D<T>::Rotation3D(T angle, T x, T y, T z)
{
    T half_angle = angle / T(2);
    T sin_half = std::sin(half_angle);
    q = Quaternion<T>::normalize(Quaternion<T>(
        std::cos(half_angle),
        x * sin_half,
        y * sin_half,
        z * sin_half
    ));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::from_euler(T roll, T pitch, T yaw)
{
    // ZYX convention (yaw, pitch, roll)
    T cy = std::cos(yaw * T(0.5));
    T sy = std::sin(yaw * T(0.5));
    T cp = std::cos(pitch * T(0.5));
    T sp = std::sin(pitch * T(0.5));
    T cr = std::cos(roll * T(0.5));
    T sr = std::sin(roll * T(0.5));

    return Rotation3D<T>(Quaternion<T>(
        cr * cp * cy + sr * sp * sy,
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy
    ));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::from_matrix(const Matrix3<T>& R)
{
    T trace = Matrix3<T>::trace(R);
    Quaternion<T> q_result;

    if (trace > 0) {
        T S = std::sqrt(trace + T(1.0)) * T(2.0);
        q_result = Quaternion<T>(
            T(0.25) * S,
            (R.m[2][1] - R.m[1][2]) / S,
            (R.m[0][2] - R.m[2][0]) / S,
            (R.m[1][0] - R.m[0][1]) / S
        );
    } else if (R.m[0][0] > R.m[1][1] && R.m[0][0] > R.m[2][2]) {
        T S = std::sqrt(T(1.0) + R.m[0][0] - R.m[1][1] - R.m[2][2]) * T(2.0);
        q_result = Quaternion<T>(
            (R.m[2][1] - R.m[1][2]) / S,
            T(0.25) * S,
            (R.m[0][1] + R.m[1][0]) / S,
            (R.m[0][2] + R.m[2][0]) / S
        );
    } else if (R.m[1][1] > R.m[2][2]) {
        T S = std::sqrt(T(1.0) + R.m[1][1] - R.m[0][0] - R.m[2][2]) * T(2.0);
        q_result = Quaternion<T>(
            (R.m[0][2] - R.m[2][0]) / S,
            (R.m[0][1] + R.m[1][0]) / S,
            T(0.25) * S,
            (R.m[1][2] + R.m[2][1]) / S
        );
    } else {
        T S = std::sqrt(T(1.0) + R.m[2][2] - R.m[0][0] - R.m[1][1]) * T(2.0);
        q_result = Quaternion<T>(
            (R.m[1][0] - R.m[0][1]) / S,
            (R.m[0][2] + R.m[2][0]) / S,
            (R.m[1][2] + R.m[2][1]) / S,
            T(0.25) * S
        );
    }

    return Rotation3D<T>(q_result);
}

template <typename T>
Quaternion<T> Rotation3D<T>::as_quaternion() const
{
    return q;
}

template <typename T>
void Rotation3D<T>::as_angle_axis(T& angle, T& x, T& y, T& z) const
{
    angle = T(2) * std::acos(q.q0);
    T sin_half_angle = std::sin(angle / T(2));

    if (std::abs(sin_half_angle) > T(1e-10)) {
        T scale = T(1) / sin_half_angle;
        x = q.q1 * scale;
        y = q.q2 * scale;
        z = q.q3 * scale;
    } else {
        angle = T(0);
        x = T(1);
        y = T(0);
        z = T(0);
    }
}

template <typename T>
void Rotation3D<T>::as_euler_angles(T& roll, T& pitch, T& yaw) const
{
    // ZYX convention
    T sinr_cosp = T(2) * (q.q0 * q.q1 + q.q2 * q.q3);
    T cosr_cosp = T(1) - T(2) * (q.q1 * q.q1 + q.q2 * q.q2);
    roll = std::atan2(sinr_cosp, cosr_cosp);

    T sinp = T(2) * (q.q0 * q.q2 - q.q3 * q.q1);
    if (std::abs(sinp) >= T(1))
        pitch = std::copysign(M_PI / T(2), sinp);
    else
        pitch = std::asin(sinp);

    T siny_cosp = T(2) * (q.q0 * q.q3 + q.q1 * q.q2);
    T cosy_cosp = T(1) - T(2) * (q.q2 * q.q2 + q.q3 * q.q3);
    yaw = std::atan2(siny_cosp, cosy_cosp);
}

template <typename T>
Matrix3<T> Rotation3D<T>::as_matrix() const
{
    T q0q0 = q.q0 * q.q0;
    T q0q1 = q.q0 * q.q1;
    T q0q2 = q.q0 * q.q2;
    T q0q3 = q.q0 * q.q3;
    T q1q1 = q.q1 * q.q1;
    T q1q2 = q.q1 * q.q2;
    T q1q3 = q.q1 * q.q3;
    T q2q2 = q.q2 * q.q2;
    T q2q3 = q.q2 * q.q3;
    T q3q3 = q.q3 * q.q3;

    return Matrix3<T>(
        T(1) - T(2)*(q2q2 + q3q3), T(2)*(q1q2 - q0q3), T(2)*(q1q3 + q0q2),
        T(2)*(q1q2 + q0q3), T(1) - T(2)*(q1q1 + q3q3), T(2)*(q2q3 - q0q1),
        T(2)*(q1q3 - q0q2), T(2)*(q2q3 + q0q1), T(1) - T(2)*(q1q1 + q2q2)
    );
}

template <typename T>
Rotation3D<T> Rotation3D<T>::inverse() const
{
    return Rotation3D<T>(Quaternion<T>::conj(q));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::operator*(const Rotation3D<T>& other) const
{
    return Rotation3D<T>(Quaternion<T>::mul(q, other.q));
}

template <typename T>
Vector3<T> Rotation3D<T>::rotate(const Vector3<T>& v) const
{
    Quaternion<T> p(T(0), v.x, v.y, v.z);
    Quaternion<T> rotated = Quaternion<T>::mul(Quaternion<T>::mul(q, p), Quaternion<T>::conj(q));
    return Vector3<T>(rotated.q1, rotated.q2, rotated.q3);
}

template <typename T>
Rotation3D<T> Rotation3D<T>::identity()
{
    return Rotation3D<T>();
}

template <typename T>
Rotation3D<T> Rotation3D<T>::around_x(T angle)
{
    return Rotation3D<T>(angle, T(1), T(0), T(0));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::around_y(T angle)
{
    return Rotation3D<T>(angle, T(0), T(1), T(0));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::around_z(T angle)
{
    return Rotation3D<T>(angle, T(0), T(0), T(1));
}

template <typename T>
Rotation3D<T> Rotation3D<T>::slerp(const Rotation3D<T>& r1, const Rotation3D<T>& r2, T t)
{
    return Rotation3D<T>(Quaternion<T>::SLERP(r1.q, r2.q, t));
}