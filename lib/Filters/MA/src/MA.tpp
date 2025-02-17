#include "MA.h"

template <typename T>
MA<T>::MA()
{
	start = true;
}

template <typename T>
void MA<T>::init(T fc_, T dt_)
{
	set_param(fc_, dt_);
	start = true;
}

template <typename T>
void MA<T>::set_param(T fc_, T dt_)
{
	fc = fc_;
	dt = dt_;
	tau = 1.0 / (2.0*MATH_PI*fc);
	alpha = dt / (dt + tau);
}

template <typename T>
void MA<T>::set_x_arr(T* x_arr_, uint16_t len_arr_)
{
	x_arr = x_arr_;
	n = len_arr_;
}

template <typename T>
T MA<T>::update(T x_k)
{
	T y_k = 0.0;
	for(uint16_t i=0;i<n-1;i++)
{
		x_arr[i] = x_arr[i+1];
	}
	x_arr[n-1] = x_k;

	T sum = 0.0;
	for(uint16_t i=0;i<n;i++)
{
		sum = sum + x_arr[i];
	}
	y_k = sum / n;
	return y_k;
}

template <typename T>
void MA<T>::reset()
{
	start = true;
}

template <typename T>
void MA<T>::set_fc(T fc_)
{
	set_param(T fc_, T dt);
}

template <typename T>
void MA<T>::set_dt(T dt_)
{
	set_param(T fc, T dt_);
}

template <typename T>
void MA<T>::set_n(T n_)
{
	n = n_;
}

template <typename T>
T MA<T>::get_fc()
{
	return fc;
}

template <typename T>
T MA<T>::get_dt()
{
	return dt;
}

template <typename T>
T MA<T>::get_n()
{
	return n;
}
