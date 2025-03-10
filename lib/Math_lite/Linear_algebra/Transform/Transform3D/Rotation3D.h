#ifndef ROTATION3D_H
#define ROTATION3D_H

#include "../../Quaternion/Quaternion.h"
#include "../../Matrix/Matrix3.h"
#include "../../Vector/Vector3.h"
#include <cmath>

template <typename T>
class Rotation3D
{
    public:
        // Constructors
        constexpr Rotation3D();  // Identity rotation
        constexpr explicit Rotation3D(const Quaternion<T>& q);  // From quaternion
        constexpr Rotation3D(T angle, T x, T y, T z);  // Angle-axis
        static Rotation3D<T> from_euler(T roll, T pitch, T yaw);  // Euler angles (ZYX)
        static Rotation3D<T> from_matrix(const Matrix3<T>& R);  // From 3x3 matrix

        // Getters in different formats
        Quaternion<T> as_quaternion() const;
        void as_angle_axis(T& angle, T& x, T& y, T& z) const;
        void as_euler_angles(T& roll, T& pitch, T& yaw) const;  // ZYX convention
        Matrix3<T> as_matrix() const;

        // Basic operations
        Rotation3D<T> inverse() const;
        Rotation3D<T> operator*(const Rotation3D<T>& other) const;  // Composition
        Vector3<T> rotate(const Vector3<T>& v) const;  // Apply to vector

        // Static factory methods for common rotations
        static Rotation3D<T> identity();
        static Rotation3D<T> around_x(T angle);
        static Rotation3D<T> around_y(T angle);
        static Rotation3D<T> around_z(T angle);

        // Interpolation
        static Rotation3D<T> slerp(const Rotation3D<T>& r1, const Rotation3D<T>& r2, T t);

    private:
        Quaternion<T> q;  // Internal quaternion representation
};

#include "Rotation3D.tpp"

#endif