#include "BPF_2.h"

template <typename T>
BPF_2<T>::BPF_2()
{
   reset();
}

template <typename T>
void BPF_2<T>::init(T f0_, T dt_)
{
   set_param(f0_, dt_);
}

template <typename T>
void BPF_2<T>::set_param(T f0_, T dt_)
{
   f0 = f0_;
   dt = dt_;
   T wc = MATH_2_PI*f0;
   T b0 = 2.0*MATH_SQRT_2*dt*wc;
   T b1 = 0.0;
   T b2 = -b0;
   T a0 = dt*dt*wc*wc + 2.0*MATH_SQRT_2*dt*wc + 4.0;
   T a1 = 2.0*dt*dt*wc*wc - 8.0;
   T a2 = dt*dt*wc*wc - 2.0*MATH_SQRT_2*dt*wc + 4.0;

   lambda_1 = b0 / a0;
   lambda_2 = b1 / a0;
   lambda_3 = b2 / a0;
   lambda_4 = -a1 / a0;
   lambda_5 = -a2 / a0;
}

template <typename T>
T BPF_2<T>::update(T x_k)
{
   T y_k = 0.0;

   if (start_counter <= 1)
   {
      y_k = x_k;
      start_counter++;
   }
   else
   {
      y_k = lambda_1 * x_k + lambda_2 * x_k_1 + lambda_3 * x_k_2 + lambda_4 * y_k_1 + lambda_5 * y_k_2;
   }
   y_k_2 = y_k_1;
   y_k_1 = y_k;
   x_k_2 = x_k_1;
   x_k_1 = x_k;

   return y_k;
}

template <typename T>
void BPF_2<T>::reset()
{
   start_counter = 0;
}

template <typename T>
void BPF_2<T>::set_f0(T f0_)
{
   set_param(f0_, dt);
}

template <typename T>
void BPF_2<T>::set_dt(T dt_)
{
   set_param(f0, dt_);
}

template <typename T>
T BPF_2<T>::get_f0()
{
   return f0;
}

template <typename T>
T BPF_2<T>::get_dt()
{
   return dt;
}

template <typename T>
T BPF_2<T>::get_fs()
{
   return 1.0 / dt;
}