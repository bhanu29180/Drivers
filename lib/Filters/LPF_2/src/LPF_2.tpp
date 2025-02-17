#include "LPF_2.h"

template <typename T>
LPF_2<T>::LPF_2()
{
   reset();
}

template <typename T>
void LPF_2<T>::init(T fc_, T dt_)
{
   set_param(fc_, dt_);
}

template <typename T>
void LPF_2<T>::set_param(T fc_, T dt_)
{
   fc = fc_;
   dt = dt_;
   T wc = MATH_2_PI*fc;
   T b0 = dt*dt*wc*wc;
   T b1 = 2.0*b0;
   T b2 = b0;
   T a0 = b0 + 2.0*MATH_SQRT_2*dt*wc + 4.0;
   T a1 = b1 - 8.0;
   T a2 = b0 - 2*MATH_SQRT_2*dt*wc + 4.0;

   lambda_1 = b0 / a0;
   lambda_2 = b1 / a0;
   lambda_3 = b2 / a0;
   lambda_4 = -a1 / a0;
   lambda_5 = -a2 / a0;
}

template <typename T>
T LPF_2<T>::update(T x_k)
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
void LPF_2<T>::reset()
{
   start_counter = 0;
}

template <typename T>
void LPF_2<T>::set_fc(T fc_)
{
   set_param(fc_, dt);
}

template <typename T>
void LPF_2<T>::set_dt(T dt_)
{
   set_param(fc, dt_);
}

template <typename T>
T LPF_2<T>::get_fc()
{
   return fc;
}

template <typename T>
T LPF_2<T>::get_dt()
{
   return dt;
}

template <typename T>
T LPF_2<T>::get_fs()
{
   return 1.0 / dt;
}