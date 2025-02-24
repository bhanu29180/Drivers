#ifndef DUAL_QUATERNION_H
#define DUAL_QUATERNION_H

#include "../Quaternion/Quaternion.h"
#include <cmath>

template <typename T>
class DualQuaternion
{
    public:
        Quaternion<T> real;  // Real part
        Quaternion<T> dual;  // Dual part (ε component)

        // Constructors
        constexpr DualQuaternion();
        constexpr DualQuaternion(const Quaternion<T>& real, const Quaternion<T>& dual);
        constexpr DualQuaternion(T r0, T r1, T r2, T r3, T d0, T d1, T d2, T d3);

        // Factory methods
        static inline constexpr DualQuaternion<T> zero();
        static inline constexpr DualQuaternion<T> identity();
        static inline constexpr DualQuaternion<T> from_rotation(const Quaternion<T>& rotation);
        static inline constexpr DualQuaternion<T> from_translation(T x, T y, T z);
        static inline constexpr DualQuaternion<T> from_transform(const Quaternion<T>& rotation, T x, T y, T z);

        // Basic operations
        static inline constexpr DualQuaternion<T> add(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2);
        static inline constexpr DualQuaternion<T> sub(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2);
        static inline constexpr DualQuaternion<T> mul(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2);
        static inline constexpr DualQuaternion<T> mul(const DualQuaternion<T>& dq, T s);
        static inline constexpr DualQuaternion<T> mul(T s, const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> div(const DualQuaternion<T>& dq, T s);

        // Advanced operations
        static inline constexpr DualQuaternion<T> conj(const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> inv(const DualQuaternion<T>& dq);
        static inline constexpr T norm(const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> normalize(const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> exp(const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> log(const DualQuaternion<T>& dq);
        static inline constexpr DualQuaternion<T> pow(const DualQuaternion<T>& dq, T t);

        // Screw motion parameters
        static inline constexpr void get_screw_parameters(const DualQuaternion<T>& dq, 
            T& angle, T& pitch, T& direction_x, T& direction_y, T& direction_z,
            T& moment_x, T& moment_y, T& moment_z);

        // Linear interpolation
        static inline constexpr DualQuaternion<T> LERP(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau);
        static inline constexpr DualQuaternion<T> SLERP(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau);
        static inline constexpr DualQuaternion<T> ScLERP(const DualQuaternion<T>& dq1, const DualQuaternion<T>& dq2, T tau);

        // Getters for transformation
        void get_rotation(Quaternion<T>& rotation) const;
        void get_translation(T& x, T& y, T& z) const;
        void get_rotation_matrix(T matrix[3][3]) const;
        void get_transformation_matrix(T matrix[4][4]) const;

        // Operator overloads
        constexpr DualQuaternion<T> operator+() const;
        constexpr DualQuaternion<T> operator-() const;
        constexpr DualQuaternion<T> operator+(const DualQuaternion<T>& other) const;
        constexpr DualQuaternion<T> operator-(const DualQuaternion<T>& other) const;
        constexpr DualQuaternion<T> operator*(const DualQuaternion<T>& other) const;
        constexpr DualQuaternion<T> operator*(T scalar) const;
        constexpr DualQuaternion<T> operator/(T scalar) const;

        DualQuaternion<T>& operator+=(const DualQuaternion<T>& other);
        DualQuaternion<T>& operator-=(const DualQuaternion<T>& other);
        DualQuaternion<T>& operator*=(const DualQuaternion<T>& other);
        DualQuaternion<T>& operator*=(T scalar);
        DualQuaternion<T>& operator/=(T scalar);

        constexpr bool operator==(const DualQuaternion<T>& other) const;
        constexpr bool operator!=(const DualQuaternion<T>& other) const;
};

#include "Dual_quaternion.tpp"

#endif
