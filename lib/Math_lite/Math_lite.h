#ifndef MATH_LITE_H
#define MATH_LITE_H

#include "Linear_algebra/Linear_algebra.h"
#include "Geometry/Geometry.h"
#include "Calculus/Calculus.h"
#include "Probability/Probability.h"
#include "Statistics/Statistics.h"

#include "cmath"
#include "../Constants/Constants.h"

template <typename T>
class Math_lite{
  public:
    static inline constexpr T saturate(T x, T x_min, T x_max);
    static inline constexpr T mod(T x);
    static inline constexpr T sign(T x);
    static inline constexpr int great_int(T x);
    static inline constexpr T ceil(T x);
    static inline constexpr T floor(T x);
    static inline constexpr T wrap(T x, T a, T b);
    static inline constexpr T apply_deadband(T x, T deadband);
    static inline constexpr T apply_deadband2(T x, T deadband);

    static inline constexpr T rad_2_deg(T x);
    static inline constexpr T deg_2_rad(T x);
    static inline constexpr T rps_2_rpm(T rps);
    static inline constexpr T rpm_2_rps(T rpm);
    
    static inline constexpr T linear_map(T x, T x1, T x2, T y1, T y2);
    static inline constexpr T poly_map_deg1(T x, T a0, T a1);
    static inline constexpr T poly_map_deg2(T x, T a0, T a1, T a2);
    static inline constexpr T poly_map_deg3(T x, T a0, T a1, T a2, T a3);
    static inline constexpr T poly_map_deg4(T x, T a0, T a1, T a2, T a3, T a4);
    static inline constexpr T poly_map_deg5(T x, T a0, T a1, T a2, T a3, T a4, T a5);
    static inline constexpr T poly_map_deg6(T x, T a0, T a1, T a2, T a3, T a4, T a5, T a6);
    static inline constexpr T poly_map_degn(T x, T a[], int n);
    static inline constexpr T fast_inv_sqrt(T number);

    bool points_AB_line_same_side(T x, T y, T x0, T y0, T x1, T y1, T x2, T y2);
    bool points_A0_line_same_side(T x, T y, T x1, T y1, T x2, T y2);
};

template <typename T>
class Circle{
  public:
    Circle();
    ~Circle();
    bool inside(T xc, T yc, T r, T x0, T y0);
    void intersection_line(T xc, T yc, T r, T x1, T y1, T x2, T y2, T* x10, T* y10, T* x20, T* y20);
    void intersection_circle(T c1x, T c1y, T r1, T c2x, T c2y, T r2, T* x01, T* y01, T* x02, T* y02);
};

#endif