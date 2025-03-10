#ifndef ROTATION2D_H
#define ROTATION2D_H

#include "../../Complex/Complex.h"
#include <cmath>

/**
 * @brief A class representing 2D rotations using complex numbers
 * 
 * This class provides a robust implementation of 2D rotations using complex numbers
 * as the internal representation. It offers conversions to and from various rotation
 * representations (angle, matrix) and implements common operations like composition
 * and vector rotation.
 * 
 * @tparam T The underlying scalar type (typically float or double)
 */
template <typename T>
class Rotation2D
{
    public:
        /** @brief Default constructor creates identity rotation */
        constexpr Rotation2D();

        /** @brief Construct from a complex number (must be normalized) */
        constexpr explicit Rotation2D(const Complex<T>& c);

        /**
         * @brief Construct from angle
         * @param angle Rotation angle in radians (counterclockwise)
         */
        constexpr explicit Rotation2D(T angle);

        /**
         * @brief Create rotation from 2x2 rotation matrix
         * @param m00 Matrix element (0,0)
         * @param m01 Matrix element (0,1)
         * @param m10 Matrix element (1,0)
         * @param m11 Matrix element (1,1)
         * @return Rotation2D object representing the same rotation
         */
        static Rotation2D<T> from_matrix(T m00, T m01, T m10, T m11);

        /** @brief Get the underlying complex number representation */
        Complex<T> as_complex() const;

        /** @brief Get the rotation angle in radians */
        T angle() const;

        /**
         * @brief Convert to 2x2 rotation matrix
         * @param[out] m00 Matrix element (0,0)
         * @param[out] m01 Matrix element (0,1)
         * @param[out] m10 Matrix element (1,0)
         * @param[out] m11 Matrix element (1,1)
         */
        void get_matrix(T& m00, T& m01, T& m10, T& m11) const;

        /** @brief Compute the inverse rotation */
        Rotation2D<T> inverse() const;

        /** @brief Compose with another rotation (applies other after this) */
        Rotation2D<T> operator*(const Rotation2D<T>& other) const;

        /**
         * @brief Apply rotation to a 2D vector
         * @param x X component of the vector
         * @param y Y component of the vector
         * @param rx Rotated X component (output)
         * @param ry Rotated Y component (output)
         */
        void rotate(T x, T y, T& rx, T& ry) const;

        /** @brief Create identity rotation */
        static Rotation2D<T> identity();

        /**
         * @brief Linear interpolation between rotations
         * @param r1 Starting rotation
         * @param r2 Ending rotation
         * @param t Interpolation parameter [0,1]
         * @return Interpolated rotation
         */
        static Rotation2D<T> lerp(const Rotation2D<T>& r1, const Rotation2D<T>& r2, T t);

        /**
         * @brief Spherical linear interpolation between rotations
         * @param r1 Starting rotation
         * @param r2 Ending rotation
         * @param t Interpolation parameter [0,1]
         * @return Interpolated rotation
         */
        static Rotation2D<T> slerp(const Rotation2D<T>& r1, const Rotation2D<T>& r2, T t);

    private:
        Complex<T> c;  // Internal complex number representation (always normalized)
};

#include "Rotation2D.tpp"

#endif
