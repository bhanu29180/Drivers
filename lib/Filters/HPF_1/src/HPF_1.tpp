#include "HPF_1.h"

template <typename T>
HPF_1<T>::HPF_1()
{
	start = true;
}

template <typename T>
void HPF_1<T>::init(T fc_, T dt_)
{
	set_param(fc_, dt_);
	start = true;
}

template <typename T>
void HPF_1<T>::set_param(T fc_, T dt_)
{
	fc = fc_;
	dt = dt_;

	tau = 1.0 / (2.0*math_pi*fc);
	alpha = tau / (dt + tau);
}

template <typename T>
T HPF_1<T>::update(T x_k)
{
	T y_k = 0.0;
	
	if(start==true)
{
		start = false;
		y_k = x_k;
	}
	else{
		y_k = alpha*(y_k_1 + x_k - x_k_1);
	}
	x_k_1 = x_k;
	y_k_1 = y_k;

	return y_k;
}

template <typename T>
void HPF_1<T>::reset()
{
	x_k_1 = 0.0;
	y_k_1 = 0.0;
	start = true;
}

template <typename T>
void HPF_1<T>::set_fc(T fc_)
{
	set_param(fc_, dt);
}

template <typename T>
void HPF_1<T>::set_tau(T tau_)
{
	tau = tau_;
	fc = 1.0 / (2.0*math_pi*tau);
	alpha = tau / (dt + tau);
}

template <typename T>
void HPF_1<T>::set_dt(T dt_)
{
	set_param(fc, dt_);
}

template <typename T>
void HPF_1<T>::set_alpha(T alpha_)
{
	alpha = alpha_;
	tau = (alpha/(1.0 - alpha)) * dt;
	fc = 1.0 / (2.0*math_pi*tau);
}

template <typename T>
T HPF_1<T>::get_fc()
{
	return fc;
}

template <typename T>
T HPF_1<T>::get_tau()
{
	return tau;
}

template <typename T>
T HPF_1<T>::get_dt()
{
	return dt;
}

template <typename T>
T HPF_1<T>::get_alpha()
{
	return alpha;
}
